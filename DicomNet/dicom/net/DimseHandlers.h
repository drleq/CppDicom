#pragma once

namespace dicom::data { class AttributeSet; }

namespace dicom::net {

    enum class DimseOp : uint16_t {
        CStoreRQ = 0x0001,
        CStoreRSP = 0x8001,
        CGetRQ = 0x0010,
        CGetRSP = 0x8010,
        CFindRQ = 0x0020,
        CFindRSP = 0x8020,
        CMoveRQ = 0x0021,
        CMoveRSP = 0x8021,
        CEchoRQ = 0x0030,
        CEchoRSP = 0x8030,
        NEventReportRQ = 0x0100,
        NEventReportRSP = 0x8100,
        NGetRQ = 0x0110,
        NGetRSP = 0x8110,
        NSetRQ = 0x0120,
        NSetRSP = 0x8120,
        NActionRQ = 0x0130,
        NActionRSP = 0x8130,
        NCreateRQ = 0x0140,
        NCreateRSP = 0x8140,
        NDeleteRQ = 0x0150,
        NDeleteRSP = 0x8150,
        CCancelRQ = 0x0FFF
    };

    enum class DimseResultCode : uint16_t {
        Success = 0x0000,
        SOPClassNotSupported = 0x0122,
        DuplicateInvocation = 0x0210,
        UnrecognisedOperation = 0x0211,
        MistypedArgument = 0x0212,
        OutOfResources = 0xA700,
        IdentifierDoesNotMatchSOPClass = 0xA900,
        UnableToProcess = 0xC000,
        UnableToProcess_Last = 0xCFFF,
        Cancel = 0xFE00,
        Pending = 0xFF00,
        PendingPartialMatch = 0xFF01
    };

    class DICOMNET_EXPORT DimseHandlers
    {
    public:
        DimseHandlers();
        virtual ~DimseHandlers();

        virtual DimseResultCode OnCEcho(
            const data::AttributeSet& command_set
        );
    };

}