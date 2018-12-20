#pragma once

#include "dicom/data/detail/atoi.h"

namespace dicom::data::detail {

    template <typename T>
    struct string_to_int {
        [[nodiscard]] static T Convert(const std::string_view& str) {
            return detail::unchecked_atoi<T>(str);
        }
    };

    template <typename T>
    struct checked_string_to_int {
        [[nodiscard]] static T Convert(const std::string_view& str) {
            return detail::checked_atoi<T>(str);
        }
    };

}