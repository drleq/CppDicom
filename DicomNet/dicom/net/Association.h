#pragma once

#include "dicom/net/AcseHandlers.h"
namespace dicom::net { class StateMachine; }

namespace dicom::net {

    class DICOMNET_EXPORT Association :
        private AcseHandlers
    {
    public:
        Association(
            asio::io_context& context,
            asio::ip::tcp::socket&& provider_socket
        );
        Association(
            asio::io_context& context,
            const asio::ip::tcp::endpoint& remote_provider_endpoint
        );
        virtual ~Association();

    private: // AcseHandlers
        AcceptanceResult IsAssociationAcceptable(const AAssociateRQ& pdu) override;
        void OnData(PDataTF&& pdu) override;

    private:
        std::unique_ptr<StateMachine> m_state_machine;

        struct DimseCommandSet {
            size_t Length;
            dicom::net::data_buffer Data;
        };
        std::optional<DimseCommandSet> m_current00;
    };

}