#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_3_converter.h"

#include "dicom/data/string_converter/detail/find_codepoint.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace {
    // UTF-32 code points stored as UTF-16 for efficiency.
    constexpr uint16_t s_lut[6*16] = {
        // 0xA0 to 0xAF
        0x00A0, 0x0126, 0x02D8, 0x00A3, 0x00A4, 0x0000, 0x0124, 0x00A7,
        0x00A8, 0x0130, 0x015E, 0x011E, 0x0134, 0x00AD, 0x0000, 0x017B,
        // 0xB0 to 0xBF
        0x00B0, 0x0127, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x0125, 0x00B7,
        0x00B8, 0x0131, 0x015F, 0x011F, 0x0135, 0x00BD, 0x0000, 0x017C,
        // 0xC0 to 0xCF
        0x00C0, 0x00C1, 0x00C2, 0x0000, 0x00C4, 0x010A, 0x0108, 0x00C7,
        0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
        // 0xD0 to 0xDF
        0x0000, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x0120, 0x00D6, 0x00D7,
        0x011C, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x016C, 0x015C, 0x00DF,
        // 0xE0 to 0xEF
        0x00E0, 0x00E1, 0x00E2, 0x0000, 0x00E4, 0x010B, 0x0109, 0x00E7,
        0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
        // 0xF0 to 0xFF
        0x0000, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x0121, 0x00F6, 0x00F7,
        0x011D, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x016D, 0x015D, 0x02D9
    };
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::data::string_converter {

    bool iso_iec_8859_3_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-3 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* /*end_it*/, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-3. Non-trivial conversion; use a LUT
                    decoded = s_lut[*next_it - 0xA0];
                }
                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_3(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-3 directly maps to BMP, but may use two-byte UTF-8 sequences.
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

                if (c >= 0x10000) {
                    return false;
                }

                // ISO/IEC 8859-3. Non-trivial conversion; use a LUT
                auto it = detail::find_codepoint00(s_lut, static_cast<uint16_t>(c));
                if (it == nullptr) { return false; }
                
                *next_it++ = static_cast<uint8_t>(0xA0 + std::distance(std::begin(s_lut), it));
                return true;
            }
        );
    }

}