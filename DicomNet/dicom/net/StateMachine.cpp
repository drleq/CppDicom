#include "dicomnet_pch.h"
#include "dicom/net/StateMachine.h"

#include "dicom/net/UpperLayer.h"

namespace dicom::net {

    StateMachine::StateMachine(
        asio::io_context& io_context
    ) {
        m_upper_layer = std::make_unique<UpperLayer>(
            io_context,
            this,
            [=](auto& error) { HandleArtimExpired(error); }
        );
        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    StateMachine::~StateMachine() = default;

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAction(MachineAction action) {
        (void)action;
    }
    
    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleArtimExpired(const asio::error_code& error) {
        if (error) {
            // Handle errors here.
        }

        switch (m_state) {
        case MachineState::Sta2:
        case MachineState::Sta13:
            ApplyAction(MachineAction::AA2);
            break;
        }
    }

}