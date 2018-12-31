#pragma once

#include "dicom/data/VRType.h"
#include "dicom/io/file/detail/InputContext.h"

namespace dicom::data { class VR; }

namespace dicom::io::file::detail {

    DICOM_EXPORT [[nodiscard]] std::unique_ptr<data::VR> create_deferred_vr(
        InputContext& context,
        std::streamsize length,
        data::VRType vr_type
    );

}