#include "dicomnet_pch.h"
#include "dicom/net/StateMachine.h"

#include "dicom/net/ProtocolDataUnits.h"
#include "dicom/net/UpperLayer.h"

namespace dicom::net {

    StateMachine::StateMachine(
        asio::io_context& io_context
    ) {
        m_upper_layer = std::make_unique<UpperLayer>(
            io_context,
            this,
            [this](auto& error) { HandleArtimExpired(error); }
        );
        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    StateMachine::~StateMachine() = default;

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAction(MachineAction action) {
        switch (action) {
        case MachineAction::AE1: ApplyAE1(); break;
        case MachineAction::AE2: ApplyAE2(); break;
        case MachineAction::AE3: ApplyAE3(); break;
        case MachineAction::AE4: ApplyAE4(); break;
        case MachineAction::AE5: ApplyAE5(); break;
        case MachineAction::AE6: ApplyAE6(); break;
        case MachineAction::AE7: ApplyAE7(); break;
        case MachineAction::AE8: ApplyAE8(); break;
        case MachineAction::DT1: ApplyDT1(); break;
        case MachineAction::DT2: ApplyDT2(); break;
        case MachineAction::AR1: ApplyAR1(); break;
        case MachineAction::AR2: ApplyAR2(); break;
        case MachineAction::AR3: ApplyAR3(); break;
        case MachineAction::AR4: ApplyAR4(); break;
        case MachineAction::AR5: ApplyAR5(); break;
        case MachineAction::AR6: ApplyAR6(); break;
        case MachineAction::AR7: ApplyAR7(); break;
        case MachineAction::AR8: ApplyAR8(); break;
        case MachineAction::AR9: ApplyAR9(); break;
        case MachineAction::AR10: ApplyAR10(); break;
        case MachineAction::AA1: ApplyAA1(); break;
        case MachineAction::AA2: ApplyAA2(); break;
        case MachineAction::AA3: ApplyAA3(); break;
        case MachineAction::AA4: ApplyAA4(); break;
        case MachineAction::AA5: ApplyAA5(); break;
        case MachineAction::AA6: ApplyAA6(); break;
        case MachineAction::AA7: ApplyAA7(); break;
        case MachineAction::AA8: ApplyAA8(); break;
        default:
            throw std::invalid_argument("Invalid action");
        }
    }
    
    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleArtimExpired(const asio::error_code& error) {
        switch (m_state) {
        case MachineState::Sta2:
        case MachineState::Sta13:
            ApplyAction(MachineAction::AA2);
            break;

        default:
            if (error) {
                // Handle errors here.
            }

            // This shouldn't happen.
            std::string msg = "Unexpected ARTIM expiration: " + std::to_string(static_cast<int>(m_state)); 
            throw IllegalStateChange(msg);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE1() {
        if (m_state != MachineState::Sta1) {
            ThrowInvalidState();
        }

        m_upper_layer->AsyncConnect(
            asio::ip::tcp::endpoint(),
            [this](auto& error) {
                if (error) {
                    // Log error information.
                    ApplyAction(MachineAction::AA4);
                } else {
                    ApplyAction(MachineAction::AE2);
                }
            }
        );
        m_state = MachineState::Sta4;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE2() {
        if (m_state != MachineState::Sta4) {
            ThrowInvalidState();
        }

        // Send A-ASSOCIATE-RQ-PDU
        AAssociateRQ pdu {
            "TARGET_AE",
            "MY_AE",
            "Temp",
            0,
            "1.2.3.4.5", // AbstractSyntax
            { "2.3.4.5.6", "3.4.5.6.7" }, // TransferSyntaxes
            128 * 1024
        };
        data_buffer data;
        auto buffer = asio::dynamic_buffer(data);
        encode_pdu(buffer, pdu);

        m_upper_layer->AsyncSendPDU(
            std::move(data),
            [this](auto& error) {
                if (error) {
                    // Log error information.
                    ApplyAction(MachineAction::AA4);
                }
            }
        );

        m_state = MachineState::Sta5;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA4() {
        if (m_state < MachineState::Sta3 || m_state > MachineState::Sta12) {
            ThrowInvalidState();
        }

        if (m_state != MachineState::Sta4) {
            // Send A-P-ABORT message
        }

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ThrowInvalidState() const {
        throw IllegalStateChange("Unexpected state: " + std::to_string(static_cast<int>(m_state)));
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::AsyncReadNextPDU() {
        // m_upper_layer->AsyncReadPDU(
        //     [this](auto& error, std::vector<uint8_t>&& pdu_buf){
        //         PDUHeader header;
        //         memcpy(&header, pdu_buf.data(), sizeof(PDUHeader));


        //     }
        // );
    }

}