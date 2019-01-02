#pragma once

namespace dicom::data::detail {

    DICOM_EXPORT [[nodiscard]] bool validate_separator_locations(
        const std::string_view& value,
        const std::vector<size_t>& offsets,
        size_t max_length
    );

}