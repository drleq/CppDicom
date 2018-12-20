#pragma once

#include "dicom/tag_number.h"

namespace dicom::io::file {

    enum class AttributeFilterResult
    {
        Drop,
        Defer,
        Load
    };

    using AttributeFilter = std::function<AttributeFilterResult (tag_number)>;
    using PrivateAttributeFilter = std::function<AttributeFilterResult (const std::string_view*, tag_number)>;

}