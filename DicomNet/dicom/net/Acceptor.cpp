#include "dicomnet_pch.h"
#include "dicom/net/Acceptor.h"

#include "dicom/net/AcseHandlers.h"
#include "dicom/net/StateMachine.h"

namespace {
    using namespace dicom::net;
    std::vector<std::unique_ptr<StateMachine>> s_tmp;

    class Dummy : public AcseHandlers {
    public:
        virtual ~Dummy() = default;

        AcceptanceResult IsAssociationAcceptable(const AAssociateRQ& pdu) override {
            return AcceptanceResult {
                true,
                pdu.PresentationContext.TransferSyntaxes.front().TransferSyntax,
                128 * 1024
            };
        }

        void OnData(PDataTF&& pdu) override {
            (void)pdu;
        }
    };
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
                        StateMachine::CreateForProvider(*m_context, std::move(conn), std::make_shared<Dummy>())
                    );
                    // Start Association handler
                }

                AcceptNext();
            }
        );
    }

}