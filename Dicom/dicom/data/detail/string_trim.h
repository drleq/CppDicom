#pragma once

#include "dicom/data/detail/StringTrimStrategy.h"

namespace dicom::data::detail {

    template <typename TTrimStrategy = trim_left_right>
    void string_trim(std::string& str) {
        std::string_view view = str;

        TTrimStrategy::TrimLeft(view);
        if (view.empty()) {
            // All whitespace. Clearing is faster.
            str.clear();
            return;
        }

        TTrimStrategy::TrimRight(view);
        if (view.size() == str.size()) {
            // No whitespace found. Do nothing.
            return;
        }

        str.assign(view);
    }

    //--------------------------------------------------------------------------------------------------------

    inline void string_trim_right(std::string& str) {
        string_trim<trim_right>(str);
    }

}