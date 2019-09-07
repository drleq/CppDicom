#pragma once

#include "dicom/net/ProtocolDataUnits.h"

namespace dicom::net {

    class DICOMNET_EXPORT AcseHandlers
    {
    public:
        virtual ~AcseHandlers();

        struct AcceptanceResult {
            bool IsAccepted;
            std::string AcceptedTransferSyntax;
            int MaximumDataTFLength;
            AAssociateRJ::ResultType FailureResult;
            AAssociateRJ::SourceType FailureSource;
            AAssociateRJ::ReasonType FailureReason;
        };
        virtual AcceptanceResult IsAssociationAcceptable(const AAssociateRQ& pdu) = 0;

        virtual void OnData(PDataTF&& pdu) = 0;
    };

}