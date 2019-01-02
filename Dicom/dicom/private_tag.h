#pragma once

#include "dicom/tag.h"

namespace dicom {
    
    [[nodiscard]] inline constexpr bool is_creator_tag(tag_number tag) { return (tag & 0x1FF00) == 0x10000; }
    [[nodiscard]] inline constexpr bool is_private_tag(tag_number tag) { return (tag & 0x10000) != 0; }

    [[nodiscard]] inline constexpr tag_number creator_tag_to_mask(tag_number creator_tag) {
        return (creator_tag & 0xFFFF0000) | ((creator_tag << 8) & 0xFF00);
    }
    [[nodiscard]] inline constexpr tag_number creator_mask_to_tag(tag_number mask) {
        return (mask & 0xFFFF0000) | ((mask >> 8) & 0xFF);
    }

    [[nodiscard]] inline constexpr tag_number make_creator_tag(tag_group group, uint8_t i) {
        return make_tag_number(group, tag_group(i));
    }
    [[nodiscard]] inline constexpr tag_number make_creator_mask(tag_group group, uint8_t i) {
        return make_tag_number(group, tag_group(i) << 8);
    }

    //--------------------------------------------------------------------------------------------------------
    
    struct DICOM_EXPORT private_tag_creator
    {
        const std::string_view Name;
        const tag_group Group;
    };

    //--------------------------------------------------------------------------------------------------------

    struct DICOM_EXPORT private_tag
    {
        const private_tag_creator*const Creator;
        const uint8_t Element;
        const multiplicity_range Multiplicity;
        const data::VRType Type;
        const bool ContextBasedType;

        [[nodiscard]] constexpr tag_group Group() const { return Creator->Group; }
        [[nodiscard]] constexpr const std::string_view& CreatorName() const { return Creator->Name; }
    };

}
