#pragma once

#include "dicom/net/ArtimTimer.h"
#include "dicom/net/ProtocolDataUnits.h"
namespace dicom::io { struct TransferSyntax; }
namespace dicom::net { class UpperLayer; }

namespace dicom::net {

    enum class MachineState {
        // PS 3.8, Table 9-1: No Association
        Sta1,  // Idle

        // PS 3.8, Table 9-2: Association Establishment
        Sta2,  // Transport connection open (Awaiting A-ASSOCIATE-RQ PDU)
        Sta3,  // Awaiting local A-ASSOCIATE response primitive (from local user)
        Sta4,  // Awaiting transport connection opening to complete (from local transport service)
        Sta5,  // Awaiting A-ASSOCIATE-AC or A-ASSOCIATE-RJ PDU

        // PS 3.8, Table 9-3: Data Transfer
        Sta6,  // Association established and ready for data transfer

        // PS 3.8, Table 9-4: Association Release
        Sta7,  // Awaiting A-RELEASE-RP PDU
        Sta8,  // Awaiting local A-RELEASE response primitive (from local user)
        Sta9,  // Release collision requestor side; awaiting A-RELEASE response (from local user)
        Sta10, // Release collision acceptor side; awaiting A-RELEASE-RP PDU
        Sta11, // Release collision requestor side; awaiting A-RELEASE-RP PDU
        Sta12, // Release collision acceptor side; awaiting A-RELEASE response primitive (from local user)

        // PS 3.8, Table 9-5: Waiting for Transport Connection Close
        Sta13  //  Transport Connection Close Indication (Association no longer exists)
    };

    enum class MachineAction {
        // PS 3.8, Table 9-6: Association Establishment Related Actions
        AE1,  // Issue TRANSPORT CONNECT request primitive to local transport service
              // Next state is Sta4
        AE2,  // Send A-ASSOCIATE-RQ-PDU
              // Next state is Sta5
        AE3,  // Issue A-ASSOCIATE confirmation (accept) primitive
              // Next state is Sta6
        AE4,  // Issue A-ASSOCIATE confirmation (reject) primitive and close transport connection
              // Next state is Sta1
        AE5,  // Issue Transport connection response primitive; start ARTIM timer
              // Next state is Sta2
        AE6,  // Stop ARTIM timer and if A-ASSOCIATE-RQ acceptable by service-provider:
              //   - issue A-ASSOCIATE indication primitive
              //     Next state is Sta3
              // otherwise:
              //   - issue A-ASSOCIATE-RJ-PDU and start ARTIM timer
              //     Next state is Sta13
        AE7,  // Send A-ASSOCIATE-AC PDU
              // Next state is Sta6
        AE8,  // Send A-ASSOCIATE-RJ PDU and start ARTIM timer
              // Next state is STA13

        // PS 3.8, Table 9-7: Data Transfer Related Actions
        DT1,  // Send P-DATA-TF PDU
              // Next state is Sta6
        DT2,  // Send P-DATA indication primitive
              // Next state is Sta6

        // PS 3.8, Table 9-8: Association Release Related Actions
        AR1,  // Send A-RELEASE-RQ PDU
              // Next state is Sta7
        AR2,  // Issue A-RELEASE indication primitive
              // Next state is Sta8
        AR3,  // Issue A-RELEASE confirmation primitive, and close transport connection
              // Next state is Sta1
        AR4,  // Issue A-RELEASE-RP PDU and start ARTIM timer
              // Next state is Sta13
        AR5,  // Stop ARTIM timer
              // Next state is Sta1
        AR6,  // Issue P-DATA indication
              // Next state is Sta7
        AR7,  // Issue P-DATA-TF PDU
              // Next state is Sta8
        AR8,  // Issue A-RELEASE indication (release collision):
              //   - if association-requestor, next state is Sta9
              //   - if not, next state is Sta10
        AR9,  // Send A-RELEASE-RP PDU
              // Next state is Sta11
        AR10, // Issue A-RELEASE confirmation primitive
              // Next state is Sta12

        // PS 3.8, Table 9-9: Association Release Related Actions
        AA1,  // Send A-ABORT PDU (service-user source) and start (or restart if already started) ARTIM timer
              // Next state is Sta13
        AA2,  // Stop ARTIM timer if running. Close transport connection
              // Next state is Sta1
        AA3,  // If (service-user inititated abort):
              //   - issue A-ABORT indication and close transport connection
              // otherwise (service-provider inititated abort):
              //   - issue A-P-ABORT indication and close transport connection
              // Next state is Sta1
        AA4,  // Issue A-P-ABORT indication primitive
              // Next state is Sta1
        AA5,  // Stop ARTIM timer
              // Next state is Sta1
        AA6,  // Ignore PDU
              // Next state is Sta13
        AA7,  // Send A-ABORT PDU
              // Next state is Sta13
        AA8,  // Send A-ABORT PDU (service-provider source-), issue an A-P-ABORT indication, and start ARTIM timer
              // Next state is Sta13
    };

    class DICOMNET_EXPORT IllegalStateChange :
        public std::logic_error
    {
    public:
        using std::logic_error::logic_error;
    };

    //--------------------------------------------------------------------------------------------------------

    // PS 3.8, Table 9-10: DICOM Upper Layer Protocol State Transition Table
    class DICOMNET_EXPORT StateMachine
    {
    public:
        StateMachine(
            asio::io_context& io_context
        );
        virtual ~StateMachine();

        MachineState State() const { return m_state; }
        void StartUser();


    private:
        void HandleArtimExpired(const asio::error_code& error);
        void ApplyAE1();
        void ApplyAE2();
        void ApplyAE3(const AAssociateAC& pdu);
        void ApplyAE4(const AAssociateRJ& pdu);
        void ApplyAE5();
        void ApplyAE6(const AAssociateRQ& pdu);
        void ApplyAE7(const AAssociateAC& pdu);
        void ApplyAE8(const AAssociateRJ& pdu);
        void ApplyDT1(const PDataTF& pdu);
        void ApplyDT2(const PDataTF& pdu);
        void ApplyAR1();
        void ApplyAR2();
        void ApplyAR3();
        void ApplyAR4();
        void ApplyAR5();
        void ApplyAR6();
        void ApplyAR7();
        void ApplyAR8();
        void ApplyAR9();
        void ApplyAR10();
        void ApplyAA1(AAbort::ReasonType reason);
        void ApplyAA2();
        void ApplyAA3();
        void ApplyAA4();
        void ApplyAA5();
        void ApplyAA6();
        void ApplyAA7(AAbort::ReasonType reason);
        void ApplyAA8(AAbort::ReasonType reason);
        void ThrowInvalidState() const;

        void ResetArtim();
        void AsyncReadNextPDU();

        void HandleNetworkError(const asio::error_code& error);
        void HandleInvalidPDU();
        void HandleAAssociateAC(PDUPtr&& pdu);
        void HandleAAssociateRJ(PDUPtr&& pdu);
        void HandleAAbort(PDUPtr&& pdu);

    private:
        bool m_is_service_user;
        std::unique_ptr<UpperLayer> m_upper_layer;
        ArtimTimer m_artim;
        MachineState m_state;

        size_t m_maximum_pdu_size = 0;
        const dicom::io::TransferSyntax* m_chosen_transfer_syntax = nullptr;
    };

}