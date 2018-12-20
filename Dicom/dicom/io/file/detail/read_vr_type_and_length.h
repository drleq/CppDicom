#pragma once

#include "dicom/tag_number.h"
#include "dicom/data/VRType.h"
namespace dicom::data { class AttributeSet; }
namespace dicom::io::file::detail { class InputContext; }

namespace dicom::io::file::detail {

    void read_vr_type_and_length(
        InputContext& context,
        const data::AttributeSet* attribute_set,
        tag_number tag,
        std::streamoff end_position,
        data::VRType* vr_type,
        std::streamsize* length
    );

}