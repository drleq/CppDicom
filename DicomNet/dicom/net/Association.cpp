#include "dicomnet_pch.h"
#include "dicom/net/Association.h"

#include "dicom/net/detail/encode_dimse_message.h"
#include "dicom/net/detail/read_data_element.h"
// #include "dicom/net/detail/write_data_element.h"
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
        if (m_cs_decoder.HasDecodeFailed()) {
            // Ignore data as we should be aborting.
            return;
        }

        for (auto& v : pdu.Values) {
            if (v.EncodedData.empty()) {
                continue;
            }

            uint8_t message_control_header = *reinterpret_cast<const uint8_t*>(v.EncodedData.front()->AsBuffer().data());
            if (message_control_header & 0x1) {
                // Command set message
                
                // The first byte in a PDV indicates if more data is to come.
                size_t d_offset = 1;
                for (auto& d : v.EncodedData) {
                    m_cs_decoder.SupplyData(d->AsBuffer() + d_offset);
                    d_offset = 0;
                }

                if (message_control_header & 0x2) {
                    // Last fragment of the message.
                    if (m_cs_decoder.HasDecodeFailed() || !m_cs_decoder.IsComplete()) {
                        m_state_machine->AbortFromInvalidPDU();
                        return;
                    }
                }
            } else {
                // Message data
            }
        }

        if (m_cs_decoder.IsComplete()) {
            auto& cs = m_cs_decoder.CommandSet();
            auto command_field = cs.Get<data::US>(tags::CommandField);
            if (!command_field) {
                m_state_machine->AbortFromInvalidPDU();
                return;
            }

            auto dimse_op = static_cast<DimseOp>(command_field->First());
            switch (dimse_op) {
            case DimseOp::CEchoRQ: HandleCEcho(cs); break;
            default:
                // Error.
                return;
            }

            m_cs_decoder = detail::CommandSetDecoder{};
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::HandleCEcho(const dicom::data::AttributeSet& command_set) {
        if (!m_dimse_handlers) {
            // SCU has received a DIMSE message
            return;
        }

        constexpr uint16_t DataSetType = 0x0101;

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

        auto fragments = detail::encode_dimse_message(16*1024, *response);

        for (auto& fragment : fragments) {
            PDataTF pdu;
            pdu.Values.push_back(PDataTF::ValueItem{ 1, std::move(fragment) });
            m_state_machine->SendPData(std::move(pdu));
        }
    }

}