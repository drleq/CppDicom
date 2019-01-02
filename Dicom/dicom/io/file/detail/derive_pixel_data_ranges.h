#pragma once

#include "dicom/io/file/PixelDataRange.h"
#include "dicom/io/file/detail/InputContext.h"

namespace dicom::data { class AttributeSet; }

namespace dicom::io::file::detail {

    DICOM_EXPORT [[nodiscard]] bool derive_pixel_data_ranges(
        InputContext& context,
        const data::AttributeSet* metadata,
        std::vector<PixelDataRange>* ranges
    );

}