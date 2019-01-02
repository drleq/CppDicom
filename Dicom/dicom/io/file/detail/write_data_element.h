#pragma once

#include "dicom/tag.h"
namespace dicom::data { class VR; }
namespace dicom::data { class AttributeSet; }
namespace dicom::io::file::detail { class OutputContext; }

namespace dicom::io::file::detail {

    DICOM_EXPORT void write_data_element(
        OutputContext* context,
        tag_number tag,
        const data::VR* attribute
    );

}