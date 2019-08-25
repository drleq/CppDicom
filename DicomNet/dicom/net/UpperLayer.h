#pragma once

namespace dicom::net { struct PDU; }
namespace dicom::net { class StateMachine; }

namespace dicom::net {

    using AsyncCallback = std::function<void(const asio::error_code&)>;
    using ArtimExpiredCallback = AsyncCallback;

    class DICOMNET_EXPORT UpperLayer
    {
    public:
        UpperLayer(
            asio::io_context& context,
            StateMachine* state_machine,
            ArtimExpiredCallback&& artim_expired_callback
        );
        virtual ~UpperLayer();

        void ResetArtimTimeout();
        void CancelArtimTimeout();

        void AdoptSocket(asio::ip::tcp::socket&& socket);
        void AsyncConnect(
            const asio::ip::tcp::endpoint& endpoint,
            AsyncCallback&& callback
        );
        void Disconnect();

        void AsyncSendPDU(
            const PDU& pdu,
            AsyncCallback&& callback
        );

    private:
        asio::io_context*const m_io_context;
        StateMachine*const m_state_machine;
        ArtimExpiredCallback m_artim_expired_callback;
        asio::steady_timer m_artim;
        std::unique_ptr<asio::ip::tcp::socket> m_socket00;
    };

}