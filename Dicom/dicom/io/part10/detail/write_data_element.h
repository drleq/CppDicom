#pragma once

#include "dicom/tag.h"
namespace dicom::data { class VR; }
namespace dicom::data { class AttributeSet; }
namespace dicom::io::part10::detail { class OutputContext; }

namespace dicom::io::part10::detail {

    DICOM_EXPORT void write_data_element(
        OutputContext* context,
        tag_number tag,
        const data::VR* attribute
    );

}