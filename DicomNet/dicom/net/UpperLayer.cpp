#include "dicomnet_pch.h"
#include "dicom/net/UpperLayer.h"

#include "dicom/net/ProtocolDataUnits.h"
#include "dicom/net/StateMachine.h"
#include "dicom/detail/intrinsic.h"

#include <fstream>

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
        DataSequence&& pdu_data,
        AsyncCallback&& callback
    ) {
        if (m_socket00 == nullptr) {
            throw std::logic_error("Socket not connected");
        }

        // Construct the asio [buffer] sequence first as we need to move [pdu_data] into the callback.
        std::vector<asio::const_buffer> buffers;
        buffers.reserve(pdu_data.Sequence.size());
        for (auto& b : pdu_data.Sequence) {
            buffers.push_back(b->AsBuffer());

            std::fstream fs{ "pdu.dat", std::ios_base::out | std::ios_base::binary };
            fs.write(reinterpret_cast<const char*>(b->AsBuffer().data()), b->AsBuffer().size());
        }

        auto wrapped_callback = [callback=std::forward<AsyncCallback>(callback), data=std::move(pdu_data)](
            auto& error, size_t bytes_transmitted
        ) {
            if (error.value() == asio::error::operation_aborted) {
                // An aborted timer means we're being cancelled or destructed.  Do nothing.
                return;
            }
            callback(error);
            (void)bytes_transmitted;
        };

        asio::async_write(*m_socket00, buffers, std::move(wrapped_callback));
    }

    //--------------------------------------------------------------------------------------------------------

    void UpperLayer::AsyncReadPDU(AsyncReadCallback&& callback) {
        data_buffer pdu_buf(sizeof(PDUHeader), 0);

        // Start by reading the PDUHeader.  This will tell us how much additional data to read.
        auto readh_buf = asio::mutable_buffer(pdu_buf.data(), sizeof(PDUHeader));
        asio::async_read(
            *m_socket00,
            readh_buf,
            [this, callback=std::forward<AsyncReadCallback>(callback), buf=std::move(pdu_buf)](auto& error, size_t bytes_read) mutable {
                if (error) {
                    if (error.value() != asio::error::operation_aborted) {
                        callback(error, std::vector<uint8_t>{});
                    }
                    return;
                }

                (void)bytes_read;
                
                // Extract the PDUHeader so we can read the Length field.
                PDUHeader header;
                memcpy(&header, buf.data(), sizeof(PDUHeader));
                header.Length = dicom::detail::byte_swap32(header.Length);

                // Resize the buffer and continue reading the rest of the PDU.
                buf.resize(buf.size() + header.Length);
                auto read_buf = asio::mutable_buffer(buf.data() + sizeof(PDUHeader), header.Length);
                asio::async_read(
                    *m_socket00,
                    read_buf,
                    [callback=std::move(callback), buf=std::move(buf)](auto& error, size_t bytes_received) mutable {
                        if (error) {
                            if (error.value() != asio::error::operation_aborted) {
                                callback(error, std::vector<uint8_t>{});
                            }
                            return;
                        }

                        (void)bytes_received;

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