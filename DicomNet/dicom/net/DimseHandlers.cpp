#include "dicomnet_pch.h"
#include "dicom/net/DimseHandlers.h"

namespace dicom::net {

    DimseHandlers::DimseHandlers() = default;

    //--------------------------------------------------------------------------------------------------------

    DimseHandlers::~DimseHandlers() = default;

    //--------------------------------------------------------------------------------------------------------

    DimseResultCode DimseHandlers::OnCEcho(
        [[maybe_unused]] const DimseHandlerContext& context
    ) {
        // C-ECHO should always return Success if it is available.
        return DimseResultCode::Success;
    }

    //--------------------------------------------------------------------------------------------------------

    DimseResultCode DimseHandlers::OnCFind(
        [[maybe_unused]] const DimseHandlerContext& context,
        [[maybe_unused]] const CFindCallback& match_callback
    ) {
        return DimseResultCode::SOPClassNotSupported;
    }

}