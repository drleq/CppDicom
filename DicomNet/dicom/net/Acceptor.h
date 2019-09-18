#pragma once

#include <atomic>

namespace dicom::net {

    class DICOMNET_EXPORT Acceptor {
    public:
        Acceptor(
            asio::io_context& context,
            asio::ip::tcp::endpoint endpoint
        );
        virtual ~Acceptor();

    private:
        asio::io_context*const m_context;
        asio::ip::tcp::acceptor m_acceptor;

        std::atomic<bool> m_cancel_flag;
        struct Worker;
        std::vector<std::unique_ptr<Worker>> m_workers;
        
        void AcceptNext();
    };

}