#pragma once

namespace dicom::net {

    using ArtimExpiredCallback = std::function<void(const asio::error_code&)>;

    class DICOMNET_EXPORT ArtimTimer
    {
    public:
        ArtimTimer(asio::io_context& io_context);
        ~ArtimTimer();

        void Reset(
            std::chrono::milliseconds timeout,
            ArtimExpiredCallback&& callback
        );
        void Cancel();

    private:
        asio::io_context*const m_io_context;
        asio::steady_timer m_artim;
        ArtimExpiredCallback m_timer_expired_callback;
    };

}