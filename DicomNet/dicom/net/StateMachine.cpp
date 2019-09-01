#include "dicomnet_pch.h"
#include "dicom/net/StateMachine.h"

#include "dicom/io/TransferSyntax.h"
#include "dicom/net/ProtocolDataUnits.h"

namespace dicom::net {

    StateMachine::StateMachine(
        asio::io_context& io_context,
        bool is_service_user
    ) : m_is_service_user(is_service_user),
        m_transport(io_context),
        m_artim(io_context)
    {
        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<StateMachine> StateMachine::CreateForProvider(
        asio::io_context& io_context,
        asio::ip::tcp::socket&& socket
    ) {
        std::unique_ptr<StateMachine> sm{ new StateMachine{ io_context, false } };
        sm->ApplyAE5(std::forward<asio::ip::tcp::socket>(socket));
        return sm;
    }

    //--------------------------------------------------------------------------------------------------------

    std::unique_ptr<StateMachine> StateMachine::CreateForUser(
        asio::io_context& io_context,
        const asio::ip::tcp::endpoint& provider_endpoint
    ) {
        std::unique_ptr<StateMachine> sm{ new StateMachine{ io_context, true } };
        sm->ApplyAE1(provider_endpoint);
        return sm;
    }

    //--------------------------------------------------------------------------------------------------------

    StateMachine::~StateMachine() = default;
    
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

    void StateMachine::ApplyAE1(const asio::ip::tcp::endpoint& provider_endpoint) {
        // [Idle] ->
        // [Service User establishing connection to remote Service Provider]
        //
        // Issue TRANSPORT CONNECT request primitive to local transport service
        // Next state is Sta4

        if (m_state != MachineState::Sta1) {
            ThrowInvalidState();
        }

        m_transport.AsyncConnect(
            provider_endpoint,
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
        // [Service User initiating connection to remote Service Provider] ->
        // [Service User sending Association Request PDU]
        //
        // Send A-ASSOCIATE-RQ-PDU
        // Next state is Sta5

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

        m_transport.AsyncSendPDU(
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

    void StateMachine::ApplyAE3(const AAssociateAC& pdu) {
        // [Service User sending Association Request PDU] ->
        // [Service User received Association Accepted PDU] ->
        // [Service User ready for Data Transfer]
        //
        // Issue A-ASSOCIATE confirmation (accept) primitive
        // Next state is Sta6

        m_maximum_pdu_size = pdu.UserInformation.MaximumLength.MaximumLength;
        m_chosen_transfer_syntax = dicom::io::get_transfer_syntax(pdu.PresentationContext.TransferSyntax.TransferSyntax);

        m_state = MachineState::Sta6;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE4(const AAssociateRJ& pdu) {
        // [Service User sending Association Request PDU] ->
        // [Service User received Association Rejected PDU; Connection is closed]
        //
        // Issue A-ASSOCIATE confirmation (reject) primitive and close transport connection
        // Next state is Sta1

        // Log why association was rejected.  Raise event.
        (void)pdu;

        m_transport.Disconnect();

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE5(asio::ip::tcp::socket&& socket) {
        // [Service Provider receives connection from Service User] ->
        // [Service Provider waiting for Association Request PDU; Start ARTIM timeout]
        //
        // Issue Transport connection response primitive; start ARTIM timer
        // Next state is Sta2
        
        m_transport.AdoptConnection(std::forward<asio::ip::tcp::socket>(socket));
        ResetArtim();

        m_state = MachineState::Sta2;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE6([[maybe_unused]] const AAssociateRQ& pdu) {
        // [Service Provider receives for Association Request PDU] ->
        // [Service Provider determines if Association Request is acceptable]
        //
        // Stop ARTIM timer and if A-ASSOCIATE-RQ acceptable by service-provider:
        //    issue A-ASSOCIATE indication primitive
        //    Next state is Sta3
        // otherwise:
        //    issue A-ASSOCIATE-RJ-PDU and start ARTIM timer
        //    Next state is Sta13

        m_artim.Cancel();

        bool is_acceptable = true; // Check if [pdu] can be accepted
        if (is_acceptable) {
            m_state = MachineState::Sta3;

        } else {
            // TODO: Obtain and pack actual reason
            AAssociateRJ rj_pdu{ 
                AAssociateRJ::ResultType::RejectedPermanent,
                AAssociateRJ::SourceType::ServiceUser,
                AAssociateRJ::ReasonType::ACSE_ProtocolNotSupported
            };
            DataSequence data;
            encode_pdu(data, rj_pdu);

            m_transport.AsyncSendPDU(
                std::move(data),
                [this](auto& error) { HandleNetworkError(error); }
            );
            ResetArtim();
            m_state = MachineState::Sta13;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE7(const AAssociateAC& pdu) {
        // [Service Provider determines if Association Request is acceptable] ->
        // [Service Provider accepts Association Request] ->
        // [Service Provider ready for Data Transfer]
        //
        // Send A-ASSOCIATE-AC PDU
        // Next state is Sta6

        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );

        m_state = MachineState::Sta6;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAE8(const AAssociateRJ& pdu) {
        // [Service Provider determines if Association Request is acceptable] ->
        // [Service Provider rejects Association Request]
        //
        // Send A-ASSOCIATE-RJ PDU and start ARTIM timer
        // Next state is STA13

        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );
        ResetArtim();

        m_state = MachineState::Sta13;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyDT1(const PDataTF& pdu) {
        // [Service Provider/User ready for Data Transfer] ->
        // [Service Provider/User sends Data PDU]
        //
        // Send P-DATA-TF PDU
        // Next state is Sta6

        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );
        
        m_state = MachineState::Sta6;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyDT2([[maybe_unused]] const PDataTF& pdu) {
        // [Service Provider/User ready for Data Transfer] ->
        // [Service Provider/User receives Data PDU]
        //
        // Send P-DATA indication primitive
        // Next state is Sta6

        // Send data to handler

        m_state = MachineState::Sta6;
        AsyncReadNextPDU();
    }

    //--------------------------------------------------------------------------------------------------------

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

    void StateMachine::ApplyAA1(AAbort::ReasonType reason) {
        // [Service User ready for Data Transfer] ->
        // [Service User sends Abort PDU]
        //
        // Send A-ABORT PDU (service-user source) and start (or restart if already started) ARTIM timer
        // Next state is Sta13

        AAbort pdu{ AAbort::SourceType::ServiceUser, reason };
        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );
        ResetArtim();

        m_state = MachineState::Sta13;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA2() {
        // [Service User initiating connection to remote Service Provider] ->
        // [Service User sends Abort PDU]
        //
        // Stop ARTIM timer if running. Close transport connection
        // Next state is Sta1

        // We haven't actually connected yet so there's no need to send an Abort PDU.
        m_artim.Cancel();
        m_transport.Disconnect();

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA3() {
        // [Service Provider/User ready for Data Transfer] ->
        // [Service Provider/User receives Abort PDU]
        //
        // If (service-user inititated abort):
        //    issue A-ABORT indication and close transport connection
        // otherwise (service-provider inititated abort):
        //    issue A-P-ABORT indication and close transport connection
        // Next state is Sta1

        // Trigger handler.

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA4() {
        // [Service Provider/User is disconnected (at transport level)]
        //
        // Issue A-P-ABORT indication primitive
        // Next state is Sta1

        if (m_state < MachineState::Sta3 || m_state > MachineState::Sta12) {
            ThrowInvalidState();
        }

        // Trigger handler
        AAbort pdu{
            m_is_service_user ?
                AAbort::SourceType::ServiceUser :
                AAbort::SourceType::ServiceProvider,
            AAbort::ReasonType::NotSpecified
        };

        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA5() {
        // [Service Provider/User is disconnected (at transport level) but connection isn't fully established]
        //
        // Stop ARTIM timer
        // Next state is Sta1

        m_artim.Cancel();
        m_state = MachineState::Sta1;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA6() {
        // [Service Provider/User receives PDU after Association has ended]
        //
        // Ignore PDU
        // Next state is Sta13

        m_state = MachineState::Sta13;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA7(AAbort::ReasonType reason) {
        // [Service Provider receives Association Request while waiting for transport to close]
        //
        // Send A-ABORT PDU
        // Next state is Sta13

        AAbort pdu{ AAbort::SourceType::ServiceUser, reason };
        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );

        m_state = MachineState::Sta13;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ApplyAA8(AAbort::ReasonType reason) {
        // [Service Provider/User receives unexpected PDU for the current state]
        //
        // Send A-ABORT PDU (service-provider source-), issue an A-P-ABORT indication, and start ARTIM timer
        // Next state is Sta13

        AAbort pdu{ AAbort::SourceType::ServiceProvider, reason };
        DataSequence data;
        encode_pdu(data, pdu);

        m_transport.AsyncSendPDU(
            std::move(data),
            [this](auto& error) { HandleNetworkError(error); }
        );
        ResetArtim();

        m_state = MachineState::Sta13;
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ThrowInvalidState() const {
        throw IllegalStateChange("Unexpected state: " + std::to_string(static_cast<int>(m_state)));
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::ResetArtim() {
        m_artim.Reset(
            std::chrono::seconds(30),
            [this](auto& error) { HandleArtimExpired(error); }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::AsyncReadNextPDU() {
        m_transport.AsyncReadPDU(
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
                case PDUType::AAssociateRJ: HandleAAssociateRJ(std::move(pdu)); break;
                case PDUType::AAbort: HandleAAbort(std::move(pdu)); break;
                }
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleNetworkError(const asio::error_code& error) {
        if (m_state == MachineState::Sta1) {
            ThrowInvalidState();
        }

        // Log error
        (void)error;

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA5();
            break;

        case MachineState::Sta13:
            ApplyAR5();
            break;

        default:
            ApplyAA4();
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleInvalidPDU() {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA1(AAbort::ReasonType::UnrecognisedPDU);
            break;

        case MachineState::Sta13:
            ApplyAA7(AAbort::ReasonType::UnrecognisedPDU);
            break;

        default:
            ApplyAA8(AAbort::ReasonType::UnrecognisedPDU);
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleAAssociateAC(PDUPtr&& pdu) {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA1(AAbort::ReasonType::UnexpectedPDU);
            break;

        case MachineState::Sta5:
            ApplyAE3(dynamic_cast<AAssociateAC&>(*pdu));
            break;

        case MachineState::Sta13:
            ApplyAA6();
            break;

        default:
            ApplyAA8(AAbort::ReasonType::UnexpectedPDU);
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleAAssociateRJ(PDUPtr&& pdu) {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
            ApplyAA1(AAbort::ReasonType::UnexpectedPDU);
            break;

        case MachineState::Sta5:
            ApplyAE4(dynamic_cast<AAssociateRJ&>(*pdu));
            break;

        case MachineState::Sta13:
            ApplyAA6();
            break;

        default:
            ApplyAA8(AAbort::ReasonType::UnexpectedPDU);
            break;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    void StateMachine::HandleAAbort([[maybe_unused]] PDUPtr&& pdu) {
        if (m_state == MachineState::Sta1 || m_state == MachineState::Sta4) {
            ThrowInvalidState();
        }

        switch (m_state) {
        case MachineState::Sta2:
        case MachineState::Sta13:
            ApplyAA2();
            break;

        default:
            ApplyAA3();
            break;
        }
    }

}