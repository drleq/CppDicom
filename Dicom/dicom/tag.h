#pragma once

#include "dicom/data/VRType.h"
#include "dicom/tag_number.h"

namespace dicom {

    struct DICOM_EXPORT multiplicity_range
    {
        const int8_t Minimum;
        const int8_t Maximum;
    };

    struct DICOM_EXPORT tag
    {
        const std::string_view Keyword;
        const tag_number Number;
        const multiplicity_range Multiplicity;
        const data::VRType Type;
        const bool ContextBasedType;

        [[nodiscard]] constexpr uint16_t Group() const { return uint16_t(Number >> 16); }
        [[nodiscard]] constexpr uint16_t Element() const { return uint16_t(Number); }
        [[nodiscard]] constexpr operator tag_number() const { return Number; }
    };

    struct DICOM_EXPORT range_tag
    {
        const std::string_view Keyword;
        const tag_number RangeMin;
        const tag_number RangeMax;
        const tag_number RangeStep;
        const multiplicity_range Multiplicity;
        const data::VRType Type;
        const bool ContextBasedType;

        [[nodiscard]] constexpr uint32_t Length() const {
            return ((RangeMax - RangeMin) / RangeStep) + 1;
        }

        [[nodiscard]] constexpr std::optional<tag> FromIndex(uint32_t index) const {
            auto number = RangeMin + (index * RangeStep);
            if (number < RangeMin || number > RangeMax) { return std::nullopt; }
            tag _tag = { std::string_view(), number, Multiplicity, Type, ContextBasedType };
            return _tag;
        }

        [[nodiscard]] constexpr std::optional<tag> FromNumber(tag_number number) const {
            if (number < RangeMin || number > RangeMax) { return std::nullopt; }
            if (((number - RangeMin) % RangeStep) != 0) { return std::nullopt; }
            tag _tag = { std::string_view(), number, Multiplicity, Type, ContextBasedType };
            return _tag;
        }
    };

}
