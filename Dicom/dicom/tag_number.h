#pragma once

namespace dicom {

    using tag_number  = uint32_t;
    using tag_group   = uint16_t;
    using tag_element = uint16_t;

    [[nodiscard]] inline constexpr tag_group get_tag_group(tag_number tag) {
        return tag_group(tag >> 16);
    }

    [[nodiscard]] inline constexpr tag_element get_tag_element(tag_number tag) {
        return tag_element(tag);
    }

    [[nodiscard]] inline constexpr tag_number make_tag_number(tag_group group, tag_element element) {
        return (tag_number(group) << 16) | element;
    }

    [[nodiscard]] inline constexpr bool is_group_length(tag_number tag) {
        return get_tag_element(tag) == 0x0000;
    }

    [[nodiscard]] inline constexpr bool is_private_group(tag_group group) {
        return (group & 1) != 0;
    }

}
