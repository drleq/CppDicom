#pragma once

#include "dicom/data/encoded_string.h"

namespace dicom::data::detail {

    DICOM_EXPORT void locate_separators(std::vector<size_t>& dest, const std::string_view& src, char split_on);
    DICOM_EXPORT [[nodiscard]] bool locate_separators(std::vector<size_t>& dest, const encoded_string& src, char split_on);

}