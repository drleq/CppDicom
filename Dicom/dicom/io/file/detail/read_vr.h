#pragma once

#include "dicom/data/VRType.h"
namespace dicom::data { class VR; }
namespace dicom::io::file::detail { class InputContext; }

namespace dicom::io::file::detail {

    DICOM_EXPORT [[nodiscard]] std::unique_ptr<data::VR> read_vr(
        InputContext& context,
        std::streamsize length,
        data::VRType vr_type
    );

}