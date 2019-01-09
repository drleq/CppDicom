#pragma once

namespace dicom::data { class AttributeSet; }
namespace dicom::io { struct TransferSyntax; }
#include "dicom/data/VRType.h"

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool derive_pixel_data_vrtype(
        const dicom::data::AttributeSet* metadata,
        const dicom::io::TransferSyntax* transfer_syntax,
        dicom::data::VRType* type
    );

}