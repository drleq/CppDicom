#include "dicom_pch.h"
#include "dicom/data/detail/locate_separators.h"

#include "dicom/data/detail/DefaultCharacterRepertoire.h"

namespace dicom::data::detail {

    void locate_separators(std::vector<size_t>& dest, const std::string_view& src, char split_on) {
        auto s_ptr = src.begin();
        auto s_end = src.end();

        while (s_ptr < s_end) {
            auto match = std::find(s_ptr, s_end, split_on);
            if (match == s_end) {
                break;
            }

            auto index = std::distance(src.begin(), match);
            dest.push_back(static_cast<size_t>(index));
            s_ptr = match + 1;
        }
    }

    //--------------------------------------------------------------------------------------------------------

    bool locate_separators(std::vector<size_t>& dest, const encoded_string& src, char split_on) {
        if (src.Validity() != ValidityType::Valid) { return false; }
        auto& parsed = src.Parsed();

        char split_char = split_on;
        if (split_on == MultiplicityChar && src.Encoding() == StringEncodingType::JIS_X_0201) {
            // In JIS X 0201 the multiplicity character is translated to Yen. Search for that instead.
            // We don't do this for CodeExtension_JISX0201 as that ought to be escaped back to something
            // more sensible before hand.
            constexpr uint8_t Yen = 0xA5;
            split_char = static_cast<char>(Yen);
        }

        auto s_ptr = parsed.begin();
        auto s_end = parsed.end();

        while (s_ptr < s_end) {
            auto match = std::find(s_ptr, s_end, split_char);
            if (match == s_end) {
                break;
            }

            auto index = std::distance(parsed.begin(), match);
            dest.push_back(static_cast<size_t>(index));
            s_ptr = match + 1;
        }

        return true;
    }

}