#include "dicomnet_pch.h"
#include "dicom/net/Acceptor.h"

#include "dicom/net/StateMachine.h"

namespace {
    std::vector<std::unique_ptr<dicom::net::StateMachine>> s_tmp;
}

namespace dicom::net {

    Acceptor::Acceptor(
        asio::io_context& context,
        asio::ip::tcp::endpoint endpoint
    ) : m_context(&context),
        m_acceptor(context, endpoint)
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
                    s_tmp.push_back(
                        StateMachine::CreateForProvider(*m_context, std::move(conn))
                    );
                    // Start Association handler
                }

                AcceptNext();
            }
        );
    }

}