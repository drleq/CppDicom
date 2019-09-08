#include "dicomnet_pch.h"
#include "dicom/net/Association.h"

#include "dicom/net/StateMachine.h"

#include "dicom/DataDictionary.h"
#include "dicom/data/VR.h"
#include "dicom/data/VRType.h"
#include "dicom/detail/intrinsic.h"
#include "dicom/tag.h"
#include "dicom/tag_number.h"
#include "dicom/io/part10/detail/InputContext.h"
#include "dicom/io/part10/detail/read_vr.h"

namespace {
    using namespace dicom;
    using namespace dicom::data;
    using namespace dicom::net;

    [[nodiscard]] bool read_data_element(
        input_buffer& data,
        const DataDictionaryPtr& data_dict,
        tag_number* tag,
        std::unique_ptr<data::VR>* attribute
    ) {
        if (data.size() < 8) {
            // Not enough data.
            return false;
        }

        io::part10::detail::InputContext ctx{
            nullptr,
            data_dict,
            dicom::io::EndianType::Little,
            dicom::io::TagEncodingType::Implicit,
            StringEncodingType::ISO_IEC_646 // Can SpecificCharacterSet be specified?
        };

        auto ptr = reinterpret_cast<const uint8_t*>(data.data());
        *tag = detail::byte_swap32(*reinterpret_cast<const uint32_t*>(&ptr[0]));
        uint32_t length = *reinterpret_cast<const uint32_t*>(&ptr[4]);

        if (data.size() - 8 < length) {
            // Not enough data.
            return false;
        }

        auto vr_type = data_dict->Get(*tag);
        if (!vr_type) {
            // Unknown attribute.
            return false;
        }

        *attribute = io::part10::detail::read_vr(ctx, length, vr_type->Type);
        if (!attribute) {
            return false;
        }

        return true;
    }
}

namespace dicom::net {

    Association::Association(
        asio::io_context& context,
        asio::ip::tcp::socket&& provider_socket
    ) {
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

    Association::AcceptanceResult Association::IsAssociationAcceptable(const AAssociateRQ& pdu) {
        return AcceptanceResult{
            true,
            pdu.PresentationContext.TransferSyntaxes.front().TransferSyntax,
            128 * 1024
        };
    }

    //--------------------------------------------------------------------------------------------------------

    void Association::OnData(PDataTF&& pdu) {
        (void)pdu;
        // Establish DIMSE message stream
        // - Read Command Group Length value (UL - 12 bytes total)
        // - Read read of Command Group based on length
        // - If C-STORE start stream handler
        if (!m_current00) {
            auto buf = pdu.Values.front().EncodedData->AsBuffer();
        }
    }

}