#include "dicomnet_pch.h"
#include "dicom/net/UpperLayer.h"

#include "dicom/net/ProtocolDataUnits.h"
#include "dicom/net/StateMachine.h"

namespace dicom::net {

    UpperLayer::UpperLayer(
        asio::io_context& io_context,
        StateMachine* state_machine,
        ArtimExpiredCallback&& artim_expired_callback
    ) : m_io_context(&io_context),
        m_state_machine(state_machine),
        m_artim_expired_callback(std::forward<ArtimExpiredCallback>(artim_expired_callback)),
        m_artim(io_context)
    {}

    //--------------------------------------------------------------------------------------------------------

    UpperLayer::~UpperLayer() = default;

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::AdoptSocket(asio::ip::tcp::socket&& socket) {
        m_socket00 = std::make_unique<asio::ip::tcp::socket>(
            std::forward<asio::ip::tcp::socket>(socket)
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::AsyncConnect(
        const asio::ip::tcp::endpoint& endpoint,
        AsyncCallback&& callback
    ) {
        m_socket00 = std::make_unique<asio::ip::tcp::socket>(*m_io_context);
        m_socket00->async_connect(endpoint, callback);
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::Disconnect() {
        if (m_socket00 == nullptr) {
            // error.
        }

        m_socket00.reset();
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::AsyncSendPDU(
        data_buffer&& pdu_data,
        AsyncCallback&& callback
    ) {
        if (m_socket00 == nullptr) {
            throw std::logic_error("Socket not connected");
        }

        // Construct the asio [buffer] first as we need to move [pdu_data] into the callback.
        auto buffer = asio::buffer(pdu_data);
        auto wrapped_callback = [callback=std::forward<AsyncCallback>(callback), data=std::move(pdu_data)](auto& error, size_t) {
            if (error.value() == asio::error::operation_aborted) {
                // An aborted timer means we're being cancelled or destructed.  Do nothing.
                return;
            }
            callback(error);
        };

        asio::async_write(*m_socket00, buffer, std::move(wrapped_callback));
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::AsyncReadPDU(AsyncReadCallback&& callback) {
        data_buffer pdu_buf{ sizeof(PDUHeader), 0 };

        // Start by reading the PDUHeader.  This will tell us how much additional data to read.
        asio::async_read(
            *m_socket00,
            asio::buffer(pdu_buf),
            [this, callback=std::forward<AsyncReadCallback>(callback), buf=std::move(pdu_buf)](auto& error, size_t) mutable {
                if (error) {
                    if (error.value() != asio::error::operation_aborted) {
                        callback(error, std::vector<uint8_t>{});
                    }
                    return;
                }
                
                // Extract the PDUHeader so we can read the Length field.
                PDUHeader header;
                memcpy(&header, buf.data(), sizeof(PDUHeader));

                // Resize the buffer and continue reading the rest of the PDU.
                buf.resize(buf.size() + header.Length);
                asio::async_read(
                    *m_socket00,
                    asio::buffer(buf) + sizeof(PDUHeader),
                    [callback=std::move(callback), buf=std::move(buf)](auto& error, size_t) mutable {
                        if (error) {
                            if (error.value() != asio::error::operation_aborted) {
                                callback(error, std::vector<uint8_t>{});
                            }
                            return;
                        }

                        // Success.  Invoke the callback.
                        callback(error, std::move(buf));
                    }
                );
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::ResetArtimTimeout() {
        m_artim.expires_from_now(std::chrono::seconds(30));
        m_artim.async_wait(
            [this](const asio::error_code& error) {
                if (error.value() == asio::error::operation_aborted) {
                    // An aborted timer means we're being cancelled or destructed.  Do nothing.
                    return;
                }

                // Timeout triggered.
                m_artim_expired_callback(error);
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::CancelArtimTimeout() {
        m_artim.cancel();
    }

}