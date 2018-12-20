#pragma once

namespace dicom::data::string_converter::detail {

    [[nodiscard]] const uint16_t* find_codepoint00(const uint16_t* ptr, const uint16_t* end_ptr, uint16_t cp);

    template <size_t N>
    [[nodiscard]] const uint16_t* find_codepoint00(const uint16_t (&ptr)[N], uint16_t cp) {
        return find_codepoint00(std::begin(ptr), std::end(ptr), cp);
    }

}