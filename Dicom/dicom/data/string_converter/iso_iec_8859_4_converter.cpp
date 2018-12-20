#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_4_converter.h"

#include "dicom/data/string_converter/detail/find_codepoint.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace {
    // UTF-32 code points stored as UTF-16 for efficiency.
    constexpr uint16_t s_lut[6*16] = {
        // 0xA0 to 0xAF
        0x00A0, 0x0104, 0x0138, 0x0156, 0x00A4, 0x0128, 0x013B, 0x00A7,
        0x00A8, 0x0160, 0x0112, 0x0122, 0x0166, 0x00AD, 0x017D, 0x00AF,
        // 0xB0 to 0xBF
        0x00B0, 0x0105, 0x02DB, 0x0157, 0x00B4, 0x0129, 0x013C, 0x02C7,
        0x00B8, 0x0161, 0x0113, 0x0123, 0x0167, 0x014A, 0x017E, 0x014B,
        // 0xC0 to 0xCF
        0x0100, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x012E,
        0x010C, 0x00C9, 0x0118, 0x00CB, 0x0116, 0x00CD, 0x00CE, 0x012A,
        // 0xD0 to 0xDF
        0x0110, 0x0145, 0x014C, 0x0136, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
        0x00D8, 0x0172, 0x00DA, 0x00DB, 0x00DC, 0x0168, 0x016A, 0x00DF,
        // 0xE0 to 0xEF
        0x0101, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x012F,
        0x010D, 0x00E9, 0x0119, 0x00EB, 0x0117, 0x00ED, 0x00EE, 0x012B,
        // 0xF0 to 0xFF
        0x0111, 0x0146, 0x014D, 0x0137, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
        0x00F8, 0x0173, 0x00FA, 0x00FB, 0x00FC, 0x0169, 0x016B, 0x02D9
    };
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::data::string_converter {

    bool iso_iec_8859_4_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-4 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-4. Non-trivial conversion; use a LUT
                    decoded = s_lut[*next_it - 0xA0];
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_4(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-4 directly maps to BMP, but may use two-byte UTF-8 sequences.
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

                // ISO/IEC 8859-4. Non-trivial conversion; use a LUT
                auto it = detail::find_codepoint00(s_lut, c);
                if (it == nullptr) { return false; }

                *next_it++ = static_cast<uint8_t>(0xA0 + std::distance(std::begin(s_lut), it));
                return true;
            }
        );
    }

}