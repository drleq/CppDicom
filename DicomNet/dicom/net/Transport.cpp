#include "dicomnet_pch.h"
#include "dicom/net/Transport.h"

#include "dicom/net/ProtocolDataUnits.h"
#include "dicom/net/StateMachine.h"
#include "dicom/detail/intrinsic.h"

namespace dicom::net {

    Transport::Transport(
        asio::io_context& io_context
    ) : m_io_context(&io_context)
    {}

    //--------------------------------------------------------------------------------------------------------

    Transport::~Transport() = default;

    //--------------------------------------------------------------------------------------------------------

    void Transport::AdoptConnection(asio::ip::tcp::socket&& socket) {
        m_socket00 = std::forward<asio::ip::tcp::socket>(socket);
    }

    //--------------------------------------------------------------------------------------------------------

    void Transport::AsyncConnect(
        const asio::ip::tcp::endpoint& endpoint,
        AsyncCallback&& callback
    ) {
        m_socket00 = asio::ip::tcp::socket{ *m_io_context };
        m_socket00->async_connect(endpoint, callback);
    }

    //--------------------------------------------------------------------------------------------------------

    void Transport::Disconnect() {
        m_socket00.reset();
    }

    //--------------------------------------------------------------------------------------------------------

    void Transport::AsyncSendPDU(
        DataSequence&& pdu_data,
        AsyncCallback&& callback
    ) {
        // Construct the asio [buffer] sequence first as we need to move [pdu_data] into the callback.
        std::vector<asio::const_buffer> buffers;
        buffers.reserve(pdu_data.Sequence.size());
        for (auto& b : pdu_data.Sequence) {
            buffers.push_back(b->AsBuffer());
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

    void Transport::AsyncReadPDU(AsyncReadCallback&& callback) {
        data_buffer pdu_buf(sizeof(PDUHeader), 0);

        // Start by reading the PDUHeader.  This will tell us how much additional data to read.
        auto readh_buf = asio::mutable_buffer(pdu_buf.data(), sizeof(PDUHeader));
        asio::async_read(
            *m_socket00,
            readh_buf,
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
                header.Length = dicom::detail::byte_swap32(header.Length);

                // Resize the buffer and continue reading the rest of the PDU.
                buf.resize(buf.size() + header.Length);
                auto read_buf = asio::mutable_buffer(buf.data() + sizeof(PDUHeader), header.Length);
                asio::async_read(
                    *m_socket00,
                    read_buf,
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

}