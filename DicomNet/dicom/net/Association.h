#pragma once

#include "dicom/net/AcseHandlers.h"
namespace dicom::data { class AttributeSet; }
namespace dicom::net { class DimseHandlers; }
namespace dicom::net { class StateMachine; }

namespace dicom::net {

    class DICOMNET_EXPORT Association :
        private AcseHandlers
    {
    public:
        Association(
            asio::io_context& context,
            asio::ip::tcp::socket&& provider_socket,
            std::shared_ptr<DimseHandlers> dimse_handlers
        );
        Association(
            asio::io_context& context,
            const asio::ip::tcp::endpoint& remote_provider_endpoint
        );
        virtual ~Association();

        bool IsClosed() const;
        void Abort() const;

    private: // AcseHandlers
        AcceptanceResult IsAssociationAcceptable(const AAssociateRQ& pdu) override;
        void OnData(PDataTF&& pdu) override;

    private:
        std::shared_ptr<DimseHandlers> m_dimse_handlers;
        std::unique_ptr<StateMachine> m_state_machine;

        struct DimseCommandSet {
            std::streamsize Length;
            dicom::net::data_buffer Data;
            std::unique_ptr<dicom::data::AttributeSet> Attributes;
        };
        std::optional<DimseCommandSet> m_current00;

        void HandleCEcho();
    };

}