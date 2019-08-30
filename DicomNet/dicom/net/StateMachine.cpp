#include "dicomnet_pch.h"
#include "dicom/net/StateMachine.h"

#include "dicom/net/ProtocolDataUnits.h"
#include "dicom/net/UpperLayer.h"

namespace dicom::net {

    StateMachine::StateMachine(
        asio::io_context& io_context
    ) : m_is_service_user(true)
    {
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

    void StateMachine::StartUser() {
        m_is_service_user = true;
        ApplyAE1();
    }
    
    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleArtimExpired(const asio::error_code& error) {
        switch (m_state) {
        case MachineState::Sta2:
        case MachineState::Sta13:
            ApplyAA2();
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
            asio::ip::tcp::endpoint(asio::ip::make_address_v4("127.0.0.1"), 106),
            [this](auto& error) {
                if (error) {
                    // Log error information.
                    ApplyAA4();
                } else {
                    ApplyAE2();
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
            "DVTK_QR_SCP",
            "DVTK_QR_SCU",
            "1.2.3.4.5",
            1,
            "1.2.840.10008.1.1", // AbstractSyntax
            { "1.2.840.10008.1.2" }, // TransferSyntaxes
            16 * 1024,
            "1.2.3.4.5",
            "FakeImp"
        };
        
        DataSequence data;
        encode_pdu(data, pdu);

        m_upper_layer->AsyncSendPDU(
            std::move(data),
            [this](auto& error) {
                if (error) {
                    // Log error information.
                    ApplyAA4();
                }
            }
        );

        m_state = MachineState::Sta5;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE3() {}
    void StateMachine::ApplyAE4() {}
    void StateMachine::ApplyAE5() {}
    void StateMachine::ApplyAE6() {}
    void StateMachine::ApplyAE7() {}
    void StateMachine::ApplyAE8() {}
    void StateMachine::ApplyDT1() {}
    void StateMachine::ApplyDT2() {}
    void StateMachine::ApplyAR1() {}
    void StateMachine::ApplyAR2() {}
    void StateMachine::ApplyAR3() {}
    void StateMachine::ApplyAR4() {}
    void StateMachine::ApplyAR5() {}
    void StateMachine::ApplyAR6() {}
    void StateMachine::ApplyAR7() {}
    void StateMachine::ApplyAR8() {}
    void StateMachine::ApplyAR9() {}
    void StateMachine::ApplyAR10() {}

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA1() {}
    void StateMachine::ApplyAA2() {}
    void StateMachine::ApplyAA3() {}

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA4() {
        if (m_state < MachineState::Sta3 || m_state > MachineState::Sta12) {
            ThrowInvalidState();
        }

        if (m_state != MachineState::Sta4) {
            // Send A-P-ABORT message.
            // Note: This doesn't really make sense as the client is disconnected and we don't _really_ have
            // a local SCU to send this to. 
            AAbort pdu{
                m_is_service_user ?
                    AAbort::SourceType::ServiceUser :
                    AAbort::SourceType::ServiceProvider,
                AAbort::ReasonType::NotSpecified
            };

            // Send to handler
        }

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA5() {}
    void StateMachine::ApplyAA6() {}
    void StateMachine::ApplyAA7() {}
    void StateMachine::ApplyAA8() {}

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ThrowInvalidState() const {
        throw IllegalStateChange("Unexpected state: " + std::to_string(static_cast<int>(m_state)));
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::AsyncReadNextPDU() {
        m_upper_layer->AsyncReadPDU(
            [this](auto& error, data_buffer&& pdu_buf){
                if (error) {
                    // Networking error.
                    ApplyAA4();
                    return;
                }

                auto pdu = decode_pdu(std::forward<data_buffer>(pdu_buf));
                if (!pdu) {
                    // Failed to decode PDU.
                    HandleInvalidPDU();
                    return;
                }

                switch (pdu->Type()) {
                case PDUType::AAssociateAC: HandleAAssociateAC(std::move(pdu)); break;
                }
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleInvalidPDU() {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA1();
            break;

        case MachineState::Sta13:
            ApplyAA7();
            break;

        default:
            ApplyAA8();
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleAAssociateAC([[maybe_unused]] PDUPtr&& pdu) {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA1();
            break;

        case MachineState::Sta5:
            ApplyAE3();
            break;

        case MachineState::Sta13:
            ApplyAA6();
            break;

        default:
            ApplyAA8();
            break;
        }
    }

}