#include "dicomnet_pch.h"
#include "dicom/net/Acceptor.h"

#include "dicom/net/AcseHandlers.h"
#include "dicom/net/Association.h"
#include <thread>

namespace {
    using namespace dicom::net;

    static void HandleAssociation(
        std::atomic<bool>*const cancel_flag,
        std::atomic<bool>*const has_completed,
        asio::ip::tcp::socket&& conn
    ) {
        // Create a new asio context for this thread.
        asio::io_context context;

        try {
            // Create an Association to handle the connection.
            Association assoc{
                context,
                std::forward<asio::ip::tcp::socket>(conn)
            };
            
            // Keep running until the association terminates.
            bool cancelling = false;
            while (!assoc.IsClosed()) {
                if (*cancel_flag && !cancelling) {
                    // We have been asked to cancel the association.  Issue an Abort but continue processing
                    // events to allow the conversation to occur.
                    assoc.Abort();
                    cancelling = true;
                }

                context.run();
            }
        } catch (const std::exception&) {
        } catch (...) {
        }

        *has_completed = true;
    }

}

namespace dicom::net {

    struct Acceptor::Worker
    {
        Worker(std::atomic<bool>& cancel_flag, asio::ip::tcp::socket&& conn)
        {
            Thread = std::thread{
                HandleAssociation,
                &cancel_flag,
                &HasCompleted,
                std::forward<asio::ip::tcp::socket>(conn)
            };
        }

        Worker(const Worker&) = delete;
        Worker& operator = (const Worker&) = delete;
        Worker(Worker&&) = delete;
        Worker& operator = (Worker&&) = delete;

        std::thread Thread;
        std::atomic<bool> HasCompleted = false;
    };

    //--------------------------------------------------------------------------------------------------------

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
        auto completed_it = std::remove_if(
            m_workers.begin(),
            m_workers.end(),
            [](auto& worker) -> bool { return worker->HasCompleted; }
        );
        m_workers.erase(completed_it, m_workers.end());

        m_acceptor.async_accept(
            [this](const asio::error_code& error, asio::ip::tcp::socket conn) {
                if (error) {
                    // Handle error.
                    return;
                }
                
                auto worker = std::make_unique<Worker>(m_cancel_flag, std::move(conn));
                m_workers.push_back(std::move(worker));
                AcceptNext();
            }
        );
    }

}