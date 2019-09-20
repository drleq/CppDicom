#include "dicomnet_pch.h"
#include "dicom/net/Acceptor.h"

#include "dicom/net/AcseHandlers.h"
#include "dicom/net/Association.h"
#include <thread>

namespace dicom::net {

    struct Acceptor::Worker
    {
        Worker(const Acceptor* owner, asio::ip::tcp::socket&& conn) {
            Thread = std::thread{
                HandleAssociation,
                owner,
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

    private:
        static void HandleAssociation(
            const Acceptor* owner,
            std::atomic<bool>*const has_completed,
            asio::ip::tcp::socket&& conn
        ) {
            // Create a new asio context for this thread.
            asio::io_context context;

            try {
                // Create an Association to handle the connection.
                Association assoc{
                    context,
                    std::forward<asio::ip::tcp::socket>(conn),
                    owner->m_dimse_handlers
                };
                
                // Keep running until the association terminates.
                bool cancelling = false;
                while (!assoc.IsClosed()) {
                    if (owner->m_cancel_flag && !cancelling) {
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
    };

    //--------------------------------------------------------------------------------------------------------

    Acceptor::Acceptor(
        asio::io_context& context,
        asio::ip::tcp::endpoint endpoint,
        std::shared_ptr<DimseHandlers> dimse_handlers
    ) : m_context(&context),
        m_dimse_handlers(std::move(dimse_handlers)),
        m_acceptor(context, endpoint),
        m_cancel_flag(false)
    {
        m_acceptor.listen();
        AcceptNext();
    }

    //--------------------------------------------------------------------------------------------------------

    Acceptor::~Acceptor() {
        Shutdown();
    }

    //--------------------------------------------------------------------------------------------------------

    void Acceptor::Shutdown() {
        m_cancel_flag = true;

        for (auto& worker : m_workers) {
            if (worker->Thread.joinable()) {
                worker->Thread.join();
            }
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void Acceptor::AcceptNext() {
        auto completed_it = std::remove_if(
            m_workers.begin(),
            m_workers.end(),
            [](auto& worker) -> bool { return worker->HasCompleted; }
        );
        std::for_each(
            completed_it,
            m_workers.end(),
            [](auto& worker) { worker->Thread.join(); }
        );
        m_workers.erase(completed_it, m_workers.end());

        m_acceptor.async_accept(
            [this](const asio::error_code& error, asio::ip::tcp::socket conn) {
                if (error) {
                    // Handle error.
                    return;
                }
                
                auto worker = std::make_unique<Worker>(this, std::move(conn));
                m_workers.push_back(std::move(worker));
                AcceptNext();
            }
        );
    }

}