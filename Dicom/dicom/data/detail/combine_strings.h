#pragma once

#include "dicom/data/encoded_string.h"

namespace dicom::data::detail {

    void combine_strings(const std::vector<std::string>& parts, std::string* dest);
    void combine_strings(std::initializer_list<std::string> parts, std::string* dest);

    void combine_strings(const std::vector<std::string_view>& parts, std::string* dest);
    void combine_strings(std::initializer_list<std::string_view> parts, std::string* dest);

    bool combine_strings(const std::vector<encoded_string>& parts, encoded_string* dest);
    bool combine_strings(std::initializer_list<encoded_string> parts, encoded_string* dest);

    [[nodiscard]] bool combine_strings(
        const std::vector<encoded_string>& parts,
        char separator_character,
        encoded_string* dest
    );
    [[nodiscard]] bool combine_strings(
        std::initializer_list<encoded_string> parts,
        char separator_character,
        encoded_string* dest
    );

}