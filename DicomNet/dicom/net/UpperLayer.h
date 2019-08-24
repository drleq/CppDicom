#pragma once

namespace dicom::net { class StateMachine; }

namespace dicom::net {

    using ArtimExpiredCallback = std::function<void(const asio::error_code&)>;

    class DICOMNET_EXPORT UpperLayer
    {
    public:
        UpperLayer(
            asio::io_context& context,
            StateMachine* state_machine,
            ArtimExpiredCallback&& artim_expired_callback
        );
        virtual ~UpperLayer();

        void WrapSocket(asio::ip::tcp::socket&& socket);

    private:
        asio::io_context*const m_io_context;
        StateMachine*const m_state_machine;
        ArtimExpiredCallback m_artim_expired_callback;
        asio::steady_timer m_artim;
    };

}