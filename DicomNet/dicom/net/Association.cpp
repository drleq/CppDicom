#include "dicomnet_pch.h"
#include "dicom/net/Association.h"

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
            auto buf = pdu.Values.front().EncodedData->AsBuffer();

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
        for (auto [tag, attrib] : *response) {
            write_data_element(ctx, tag, attrib);
        }
        auto end_pos = stream->Tell();
        stream->Seek(8, std::ios_base::beg);
        stream->WriteValue(static_cast<uint32_t>(end_pos - start_pos));

        std::vector<uint8_t> buf = stream->Detach();
    }

}