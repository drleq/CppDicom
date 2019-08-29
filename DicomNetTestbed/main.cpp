#include "dicomnettestbed_pch.h"

#include "dicom/net/StateMachine.h"
#include <thread>

int main([[maybe_unused]] int argc, [[maybe_unused]] const char* argv[]) {
    asio::io_context context;

    dicom::net::StateMachine sm{ context };
    sm.ApplyAction(dicom::net::MachineAction::AE1);

    while (true) {
        context.run();
    }

    return 0;
}