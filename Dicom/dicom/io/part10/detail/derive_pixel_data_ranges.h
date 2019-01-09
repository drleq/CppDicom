#pragma once

#include "dicom/io/part10/PixelDataRange.h"
#include "dicom/io/part10/detail/InputContext.h"

namespace dicom::data { class AttributeSet; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool derive_pixel_data_ranges(
        InputContext& context,
        const data::AttributeSet* metadata,
        std::vector<PixelDataRange>* ranges
    );

}