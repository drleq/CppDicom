#include "dicom_pch.h"
#include "dicom/data/detail/validate_separator_locations.h"

namespace dicom::data::detail {

    bool validate_separator_locations(
        const std::string_view& value,
        const std::vector<size_t>& offsets,
        size_t max_length
    ) {
        size_t prev_offset = 0;
        for (size_t offset : offsets) {
            if ((offset - prev_offset) > max_length) { return false; }
            prev_offset = offset + 1;
        }
        return (value.size() - prev_offset) <= max_length;
    }

}