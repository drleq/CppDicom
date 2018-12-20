#pragma once

namespace dicom::io::file::detail { class InputContext; }
#include "dicom/tag_number.h"

namespace dicom::io::file::detail {

    struct FragmentInfo
    {
        dicom::tag_number m_tag;
        uint32_t m_byte_length;
    };

    [[nodiscard]] std::vector<FragmentInfo> discover_pixel_data_fragments(
        InputContext* context,
        size_t raw_length,
        size_t* real_length
    );

}