#pragma once

#include "dicom/net/DimseHandlers.h"
#include <atomic>

namespace dicom::net {

    class DICOMNET_EXPORT Acceptor {
    public:
        Acceptor(
            asio::io_context& context,
            asio::ip::tcp::endpoint endpoint,
            std::shared_ptr<DimseHandlers> dimse_handlers
        );
        virtual ~Acceptor();

        void Shutdown();

    private:
        asio::io_context*const m_context;
        std::shared_ptr<DimseHandlers> m_dimse_handlers;
        asio::ip::tcp::acceptor m_acceptor;

        std::atomic<bool> m_cancel_flag;
        struct Worker;
        std::vector<std::unique_ptr<Worker>> m_workers;
        
        void AcceptNext();
    };

}