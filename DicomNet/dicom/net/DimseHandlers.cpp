#include "dicomnet_pch.h"
#include "dicom/net/DimseHandlers.h"

namespace dicom::net {

    DimseHandlers::DimseHandlers() = default;

    //--------------------------------------------------------------------------------------------------------

    DimseHandlers::~DimseHandlers() = default;

    //--------------------------------------------------------------------------------------------------------

    DimseResultCode DimseHandlers::OnCEcho([[maybe_unused]] const data::AttributeSet& command_set) {
        // C-ECHO should always return Success if it is available.
        return DimseResultCode::Success;
    }

}