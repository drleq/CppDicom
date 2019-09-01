#include "dicomnettestbed_pch.h"

#include "dicom/net/StateMachine.h"
#include <thread>

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
    asio::io_context context;

    auto sm = dicom::net::StateMachine::CreateForUser(
        context,
        asio::ip::tcp::endpoint(asio::ip::make_address_v4("127.0.0.1"), 106)
    );

    while (true) {
        context.run();
    }

    return 0;
}