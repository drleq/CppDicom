#include "dicomnet_pch.h"
#include "dicom/net/Association.h"

#include "dicom/net/DataStorage.h"
#include "dicom/net/DimseHandlers.h"
#include "dicom/net/StateMachine.h"
#include "dicom/net/Tags.h"

#include "dicom/DataDictionary.h"
#include "dicom/data/UL.h"
#include "dicom/data/US.h"
#include "dicom/data/VR.h"
#include "dicom/data/VRType.h"
#include "dicom/detail/intrinsic.h"
#include "dicom/tag.h"
#include "dicom/tag_number.h"
#include "dicom/io/part10/MemoryInputStream.h"
#include "dicom/io/part10/MemoryOutputStream.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/OutputContext.h"
#include "dicom/io/part10/detail/read_vr.h"
#include "dicom/io/part10/detail/write_vr.h"

namespace {
    using namespace dicom;
    using namespace dicom::data;
    using namespace dicom::net;

    DataDictionaryPtr get_data_dictionary() {
        DataDictionaryPtr dict = std::make_shared<DataDictionary>();
        dicom::net::tags::populate_data_dictionary(dict);
        return dict;
    }

    //--------------------------------------------------------------------------------------------------------

    [[nodiscard]] bool read_data_element(
        io::part10::detail::InputContext& ctx,
        tag_number* tag,
        std::unique_ptr<data::VR>* attribute
    ) {
        *tag = ctx.ReadTagNumber();
        auto length = ctx.ReadImplicitTagLength();

        auto vr_type = ctx.DataDictionary()->Get(*tag);
        if (!vr_type) {
            // Unknown attribute.
            return false;
        }

        *attribute = io::part10::detail::read_vr(ctx, length, vr_type->Type);
        if (!attribute) {
            return false;
        }

        return !ctx.Failed() && ctx.Stream()->Good();
    }

    //--------------------------------------------------------------------------------------------------------

    void write_data_element(
        io::part10::detail::OutputContext& ctx,
        const tag_number& tag,
        const data::VR* attribute
    ) {
        auto& stream = ctx.Stream();

        ctx.WriteTagNumber(tag);

        // Write a dummy length value.
        auto length_position = stream->Tell();
        ctx.WriteImplicitTagLength(0);

        // Write the attribute data, recording how many bytes it consumes.
        auto attribute_start_position = stream->Tell();
        write_vr(&ctx, attribute);
        auto attribute_end_position = stream->Tell();

        // Update the length value.
        auto bytes_written = attribute_end_position - attribute_start_position;
        stream->Seek(length_position, std::ios::beg);
        ctx.WriteImplicitTagLength(bytes_written);
        stream->Seek(0, std::ios::end);
    }

    //--------------------------------------------------------------------------------------------------------

    DataStoragePtr encode_command_set(const data::AttributeSet& command_set) {
        auto stream = std::make_shared<io::part10::MemoryOutputStream>();
        io::part10::detail::OutputContext ctx{
            stream,
            &io::transfer_syntax::ImplicitLittle,
            data::StringEncodingType::ISO_IEC_646
        };

        ctx.WriteTagNumber(tags::CommandGroupLength);
        ctx.WriteImplicitTagLength(4);
        stream->WriteValue(0U);

        auto start_pos = stream->Tell();
        for (auto [tag, attrib] : command_set) {
            write_data_element(ctx, tag, attrib);
        }
        auto end_pos = stream->Tell();
        stream->Seek(8, std::ios_base::beg);
        stream->WriteValue(static_cast<uint32_t>(end_pos - start_pos));

        return std::make_shared<SharedValueDataStorage>(stream->Detach());
    }

    //--------------------------------------------------------------------------------------------------------

    std::vector<DataStorageSequence> fragment_message_data(
        size_t maximum_fragment_length,
        bool is_command_set,
        const DataStorageSequence& data
    ) {
        static const auto NonLastCommandFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x01 });
        static const auto LastCommandFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x03 });
        static const auto NonLastDatasetFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x00 });
        static const auto LastDatasetFlag = std::make_shared<UniqueValueDataStorage>(data_buffer{ 0x02 });
        constexpr size_t MessageFlagSize = 1;
        constexpr size_t ValueItemHeaderSize = 4 + 1;
        constexpr size_t HeaderSize = ValueItemHeaderSize + MessageFlagSize;

        DataStoragePtr non_last_fragment_flag;
        DataStoragePtr last_fragment_flag;
        if (is_command_set) {
            non_last_fragment_flag = NonLastCommandFlag;
            last_fragment_flag = LastCommandFlag;
        } else {
            non_last_fragment_flag = NonLastDatasetFlag;
            last_fragment_flag = LastDatasetFlag;
        }

        // [data] contains a sequence of buffers representing all the data we want to send.  For
        // transmission over the ACSE layer the data needs to be split into fragments and sent as
        // individual messages.  Each fragment can consist of multiple buffers to make up the maximum
        // allowed length, including a single byte buffer at the beginning that
        std::vector<DataStorageSequence> fragments;
        DataStorageSequence fragment { non_last_fragment_flag };
        size_t fragment_remaining = maximum_fragment_length - HeaderSize;

        for (auto& s : data) {
            auto length = s->AsBuffer().size();

            size_t pos = 0;
            while (pos < length) {
                size_t sub_length = std::min(fragment_remaining, length - pos);

                auto sub_storage = std::make_shared<SubRangeDataStorage>(s, pos, sub_length);
                fragment.push_back(std::move(sub_storage));

                pos += sub_length;
                fragment_remaining -= sub_length;

                if (fragment_remaining == 0) {
                    fragments.push_back(std::move(fragment));

                    fragment_remaining = maximum_fragment_length - HeaderSize;
                    fragment.push_back(non_last_fragment_flag);
                }
            }
        }

        if (fragment.size() > 1) {
            fragment[0] = last_fragment_flag;
            fragments.push_back(std::move(fragment));
        }

        return fragments;
    }

    //--------------------------------------------------------------------------------------------------------

    std::vector<DataStorageSequence> encode_dimse_message(
        size_t maximum_fragment_length,
        const data::AttributeSet& command_set//,
        /* ??? dataset */
    ) {
        // Encode the command set to a buffer.
        auto encoded_command_set = encode_command_set(command_set);
        auto command_set_sequence = fragment_message_data(maximum_fragment_length, true, { encoded_command_set });

        // Encode the dataset to a buffer.

        return command_set_sequence;
    }
}

namespace dicom::net {

    Association::Association(
        asio::io_context& context,
        asio::ip::tcp::socket&& provider_socket,
        std::shared_ptr<DimseHandlers> dimse_handlers
    ) : m_dimse_handlers(std::move(dimse_handlers))
    {
        m_state_machine = std::make_unique<StateMachine>(
            context,
            static_cast<AcseHandlers*>(this),
            std::forward<asio::ip::tcp::socket>(provider_socket)
        );
    }

    //--------------------------------------------------------------------------------------------------------

    Association::Association(
        asio::io_context& context,
        const asio::ip::tcp::endpoint& remote_provider_endpoint
    ) {
        m_state_machine = std::make_unique<StateMachine>(
            context,
            static_cast<AcseHandlers*>(this),
            remote_provider_endpoint
        );
    }

    //--------------------------------------------------------------------------------------------------------

    Association::~Association() = default;

    //--------------------------------------------------------------------------------------------------------

    bool Association::IsClosed() const {
        return m_state_machine->IsClosed();
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::Abort() const {
        m_state_machine->Abort();
    }

    //--------------------------------------------------------------------------------------------------------

    Association::AcceptanceResult Association::IsAssociationAcceptable(const AAssociateRQ& pdu) {
        return AcceptanceResult{
            true,
            pdu.PresentationContext.TransferSyntaxes.front().TransferSyntax,
            128 * 1024
        };
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::OnData(PDataTF&& pdu) {
        // Establish DIMSE message stream
        // - Read Command Group Length value (UL - 12 bytes total)
        // - Read of Command Group based on length
        // - If C-STORE start stream handler
        if (!m_current00) {
            // Assume only one value fragment.
            auto buf = pdu.Values.front().EncodedData.front()->AsBuffer();

            // Skip the control byte.
            buf += 1;

            auto stream = std::make_shared<io::part10::MemoryInputStream>(
                std::make_shared<io::part10::MemoryInputView>(
                    reinterpret_cast<const uint8_t*>(buf.data()),
                    buf.size()
                )
            );
            io::part10::detail::InputContext ctx{
                stream,
                get_data_dictionary(),
                dicom::io::EndianType::Little,
                dicom::io::TagEncodingType::Implicit,
                StringEncodingType::ISO_IEC_646
            };

            // Read the Command Group Length value
            tag_number tag;
            std::unique_ptr<VR> attrib;
            bool result = read_data_element(ctx, &tag, &attrib);
            if (!result || tag != tags::CommandGroupLength) {
                // Fail.
                return;
            }

            std::streampos cs_length = dynamic_cast<dicom::data::UL*>(attrib.get())->First();
            auto cs = DimseCommandSet{
                cs_length,
                { reinterpret_cast<const uint8_t*>(buf.data()) + ctx.Stream()->Tell(), reinterpret_cast<const uint8_t*>(buf.data()) + buf.size() },
                std::make_unique<dicom::data::AttributeSet>()
            };
            cs.Attributes->Add(tags::CommandGroupLength, std::move(attrib));

            if (cs_length > ctx.Stream()->Length() - ctx.Stream()->Tell()) {
                // This shouldn't happen.
                return;
            }

            // Can read entire commad set now.
            std::streampos end_pos = ctx.Stream()->Tell() + cs_length;
            while (ctx.Stream()->Tell() < end_pos) {
                result = read_data_element(ctx, &tag, &attrib);
                if (!result || get_tag_group(tag) != 0x0000) {
                    // Error.
                    return;
                }

                cs.Attributes->Add(tag, std::move(attrib));
            }

            m_current00 = std::move(cs);
        }

        auto command_field = m_current00->Attributes->Get<data::US>(tags::CommandField);
        if (!command_field) {
            // This shouldn't happen.
            return;
        }
        auto dimse_op = static_cast<DimseOp>(command_field->First());

        switch (dimse_op) {
        case DimseOp::CEchoRQ: HandleCEcho(); break;
        default:
            // Error.
            return;
        }

        m_current00 = std::nullopt;
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::HandleCEcho() {
        if (!m_dimse_handlers) {
            // SCU has received a DIMSE message
            return;
        }

        constexpr uint16_t DataSetType = 0x0101;

        auto& command_set = *m_current00->Attributes;
        auto response = std::make_unique<data::AttributeSet>();
        response->CopyExact(command_set, tags::AffectedSOPClassUID);
        response->CopyTo(command_set, tags::MessageID, tags::MessageIDBeingRespondedTo);
        response->AddValue(tags::CommandDataSetType, DataSetType);
        response->AddValue(tags::CommandField, DimseOp::CEchoRSP);

        if (command_set.GetValue<uint16_t>(tags::CommandDataSetType) != DataSetType) {
            // Something is wrong.  "Reject" the echo.
            response->AddValue(tags::Status, DimseResultCode::MistypedArgument);

        } else {
            // Handle the echo.
            auto result = m_dimse_handlers->OnCEcho(command_set);
            response->AddValue(tags::Status, result);
        }

        auto fragments = encode_dimse_message(16*1024, *response);

        for (auto& fragment : fragments) {
            PDataTF pdu;
            pdu.Values.push_back(PDataTF::ValueItem{ 1, std::move(fragment) });
            m_state_machine->SendPData(std::move(pdu));
        }
    }

}