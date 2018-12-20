#pragma once

namespace dicom::data::detail {

    constexpr char MultiplicityChar = 0x5C;

    [[nodiscard]] bool validate_default_character_repertoire(const std::string_view& value);
    [[nodiscard]] bool validate_excludes_control_characters(const std::string_view& value);

}