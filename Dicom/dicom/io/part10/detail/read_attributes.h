#pragma once

namespace dicom::io::part10::detail { class InputContext; }
namespace dicom::io::part10 { class PixelDataRange; }
namespace dicom::data { class AttributeSet; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] bool read_attributes(
        InputContext& context,
        data::AttributeSet* dest,
        std::vector<PixelDataRange>* pixel_data_ranges
    );

}