#pragma once

namespace dicom::data::detail {
    
    struct trim_none
    {
        static void TrimLeft(std::string_view& /*str*/) { }
        static void TrimRight(std::string_view& /*str*/) { }
    };

    //--------------------------------------------------------------------------------------------------------

    struct trim_left : trim_none
    {
        static void TrimLeft(std::string_view& str) {
            auto it = str.begin();
            while (it != str.end()) {
                if (*it != ' ') { break; }
                ++it;
            }
            str.remove_prefix(std::distance(str.begin(), it));
        }
    };

    //--------------------------------------------------------------------------------------------------------

    struct trim_right : trim_none
    {
        static void TrimRight(std::string_view& str) {
            auto it = str.rbegin();
            while (it != str.rend()) {
                if (*it != ' ') { break; }
                ++it;
            }
            str.remove_suffix(std::distance(str.rbegin(), it));
        }
    };

    //--------------------------------------------------------------------------------------------------------

    struct trim_left_right : trim_left, trim_right
    {
        using trim_left::TrimLeft;
        using trim_right::TrimRight;
    };

}