#pragma once

namespace dicom::data { class AttributeSet; }
namespace dicom::io { struct TransferSyntax; }
#include "dicom/data/VRType.h"

namespace dicom::io::file::detail {

    [[nodiscard]] bool derive_pixel_data_vrtype(
        const dicom::data::AttributeSet* metadata,
        const dicom::io::TransferSyntax* transfer_syntax,
        dicom::data::VRType* type
    );

}