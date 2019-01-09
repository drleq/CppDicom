#pragma once

#include "dicom/tag.h"
namespace dicom::data { class VR; }
namespace dicom::data { class AttributeSet; }
namespace dicom::io::part10::detail { class InputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT [[nodiscard]] std::unique_ptr<data::VR> read_data_element(
        InputContext& context,
        const data::AttributeSet* attribute_set,
        tag_number* tag
    );

}