#pragma once

#include "dicom/data/encoded_string.h"

namespace dicom::data::detail {

    DICOM_EXPORT void combine_strings(const std::vector<std::string>& parts, std::string* dest);
    DICOM_EXPORT void combine_strings(std::initializer_list<std::string> parts, std::string* dest);

    DICOM_EXPORT void combine_strings(const std::vector<std::string_view>& parts, std::string* dest);
    DICOM_EXPORT void combine_strings(std::initializer_list<std::string_view> parts, std::string* dest);

    DICOM_EXPORT bool combine_strings(const std::vector<encoded_string>& parts, encoded_string* dest);
    DICOM_EXPORT bool combine_strings(std::initializer_list<encoded_string> parts, encoded_string* dest);

    DICOM_EXPORT [[nodiscard]] bool combine_strings(
        const std::vector<encoded_string>& parts,
        char separator_character,
        encoded_string* dest
    );
    DICOM_EXPORT [[nodiscard]] bool combine_strings(
        std::initializer_list<encoded_string> parts,
        char separator_character,
        encoded_string* dest
    );

}