#include "dicomnet_pch.h"
#include "dicom/net/ArtimTimer.h"

namespace dicom::net {

    ArtimTimer::ArtimTimer(
        asio::io_context& io_context
    ) : m_io_context{ &io_context },
        m_artim{ io_context }
    {}

    //--------------------------------------------------------------------------------------------------------

    ArtimTimer::~ArtimTimer() = default;

    //--------------------------------------------------------------------------------------------------------

    void ArtimTimer::Reset(
        std::chrono::milliseconds timeout,
        ArtimExpiredCallback&& callback
    ) {
        m_artim.expires_from_now(timeout);
        m_artim.async_wait(
            [cb=std::forward<ArtimExpiredCallback>(callback)](const asio::error_code& error) {
                if (error.value() == asio::error::operation_aborted) {
                    // An aborted timer means we're being cancelled or destructed.  Do nothing.
                    return;
                }

                // Timeout triggered.
                cb(error);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void ArtimTimer::Cancel() {
        m_artim.cancel();
    }

}