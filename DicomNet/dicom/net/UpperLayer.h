#pragma once

#include "dicom/net/ProtocolDataUnits.h"
namespace dicom::net { class StateMachine; }

namespace dicom::net {

    using AsyncCallback = std::function<void(const asio::error_code&)>;
    using AsyncReadCallback = std::function<void(const asio::error_code&, data_buffer&&)>;

    class DICOMNET_EXPORT UpperLayer
    {
    public:
        UpperLayer(asio::io_context& context);
        virtual ~UpperLayer();

        void AdoptConnection(
            asio::ip::tcp::socket&& socket
        );
        void AsyncConnect(
            const asio::ip::tcp::endpoint& endpoint,
            AsyncCallback&& callback
        );
        void Disconnect();

        void AsyncSendPDU(
            DataSequence&& pdu_data,
            AsyncCallback&& callback
        );
        void AsyncReadPDU(
            AsyncReadCallback&& callback
        );

    private:
        asio::io_context*const m_io_context;
        std::optional<asio::ip::tcp::socket> m_socket00;
    };

}