#pragma once

namespace dicom::io::file::detail { class InputContext; }
namespace dicom::io::file { class PixelDataRange; }
namespace dicom::data { class AttributeSet; }

namespace dicom::io::file::detail {

    [[nodiscard]] bool read_attributes(
        InputContext& context,
        data::AttributeSet* dest,
        std::vector<PixelDataRange>* pixel_data_ranges
    );

}