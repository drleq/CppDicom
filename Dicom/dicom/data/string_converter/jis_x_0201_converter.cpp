#include "dicom_pch.h"
#include "dicom/data/string_converter/jis_x_0201_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool jis_x_0201_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // JIS X 0201 maps to BMP, but may use three-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // JIS X 0201: Romaji
                         if (*next_it == 0x5C) { decoded = 0x00A5; } // backslash -> yen
                    else if (*next_it == 0x7E) { decoded = 0x00AF; } // tilde -> macron
                    else { decoded = *next_it; }                     // direct mapping to BMP
                } else {
                    // JIS X 0201: Katakana
                    decoded = 0xFF61 + (*next_it - 0xA1); // Map to halfwidth and fullwidth forms segment of BMP
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_jis_x_0201(const std::string_view& utf8_source, std::string& encoded_dest) {
        // JIS X 0201 maps to BMP, but may use three-byte UTF-8 sequences.
        encoded_dest.resize(utf8_source.size());

        return detail::utf8_to_8bit_encoded<1>(
            utf8_source,
            encoded_dest,
            [](char32_t c, uint8_t*& next_it) {
                switch (c) {
                case 0x005C:
                case 0x007E:
                    return false;

                case 0x00A5: *next_it = 0x5C; break; // Yen
                case 0x00AF: *next_it = 0x7E; break; // Macron
                default:
                    if (c > 0x007F && c < 0xFF61) {
                        return false;
                    }
                    if (c > 0xFF9F) {
                        return false;
                    }

                    if (c <= 0x007F) {
                        // JIS X 0201: Romaji
                        *next_it = static_cast<uint8_t>(c);
                    } else {
                        // JIS X 0201: Katakana
                        *next_it = static_cast<uint8_t>((c - 0xFF61) + 0xA1);
                    }
                }

                ++next_it;
                return true;
            }
        );
    }

}