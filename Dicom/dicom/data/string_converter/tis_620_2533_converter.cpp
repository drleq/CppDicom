#include "dicom_pch.h"
#include "dicom/data/string_converter/tis_620_2533_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool tis_620_2533_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // TIS 620-2533 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // TIS 620-2533. Linear mapping to BMP
                    decoded = 0x0E01 + (*next_it - 0xA1);
                }
                
                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_tis_620_2533(const std::string_view& utf8_source, std::string& encoded_dest) {
        // TIS 620-2533 directly maps to BMP, but may use two-byte UTF-8 sequences.
        encoded_dest.resize(utf8_source.size());

        return detail::utf8_to_8bit_encoded<1>(
            utf8_source,
            encoded_dest,
            [](char32_t c, uint8_t*& next_it) {
                if (c < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    *next_it++ = static_cast<uint8_t>(c);
                    return true;
                }

                // TIS 620-2533. Linear mapping to BMP.
                if (c < 0x0E01 || c > 0x0E5B) { return false; }
                *next_it++ = static_cast<uint8_t>(0xA1 + (c - 0x0E01));
                return true;
            }
        );
    }

}