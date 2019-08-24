#include "dicomnet_pch.h"
#include "dicom/net/Acceptor.h"

namespace dicom::net {

    Acceptor::Acceptor(
        asio::io_context& context,
        asio::ip::tcp::endpoint endpoint
    ) : m_acceptor(context, endpoint)
    {
        m_acceptor.listen();
        AcceptNext();
    }

    //--------------------------------------------------------------------------------------------------------

    Acceptor::~Acceptor() = default;

    //--------------------------------------------------------------------------------------------------------

    void Acceptor::AcceptNext() {
        m_acceptor.async_accept(
            [this](const asio::error_code& error, asio::ip::tcp::socket conn) {
                if (error) {
                    // Handle error.
                } else {
                    // Start Association handler
                }

                AcceptNext();
            }
        );
    }

}