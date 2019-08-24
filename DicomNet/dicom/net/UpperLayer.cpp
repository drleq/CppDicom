#include "dicomnet_pch.h"
#include "dicom/net/UpperLayer.h"

#include "dicom/net/StateMachine.h"

namespace dicom::net {

    UpperLayer::UpperLayer(
        asio::io_context& io_context,
        StateMachine* state_machine,
        ArtimExpiredCallback&& artim_expired_callback
    ) : m_io_context(&io_context),
        m_state_machine(state_machine),
        m_artim_expired_callback(artim_expired_callback),
        m_artim(io_context)
    {}

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::WrapSocket([[maybe_unused]] asio::ip::tcp::socket&& socket) {
        //m_socket = std::forward<asio::ip::tcp::socket>(socket);
        m_artim = asio::steady_timer(*m_io_context);
        m_artim.expires_from_now(std::chrono::seconds(30));
        m_artim.async_wait(
            [this](const asio::error_code& error) {
                if (error.value() == asio::error::operation_aborted) {
                    // An aborted timer means we're being destructed.  Do nothing.
                    return;
                }

                // Timeout triggered.
                m_artim_expired_callback(error);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    UpperLayer::~UpperLayer() = default;

}