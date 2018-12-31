#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_2_converter.h"

#include "dicom/data/string_converter/detail/find_codepoint.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace {
    // UTF-32 code points stored as UTF-16 for efficiency.
    constexpr uint16_t s_lut[6*16] = {
        // 0xA0 to 0xAF
        0x00A0, 0x0104, 0x02D8, 0x0141, 0x00A4, 0x013D, 0x015A, 0x00A7,
        0x00A8, 0x0160, 0x015E, 0x0164, 0x0179, 0x00AD, 0x017D, 0x017B,
        // 0xB0 to 0xBF
        0x00B0, 0x0105, 0x02DB, 0x0142, 0x00B4, 0x013E, 0x015B, 0x02C7,
        0x00B8, 0x0161, 0x015F, 0x0165, 0x017A, 0x02DD, 0x017E, 0x017C,
        // 0xC0 to 0xCF
        0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7,
        0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
        // 0xD0 to 0xDF
        0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7,
        0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
        // 0xE0 to 0xEF
        0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7,
        0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
        // 0xF0 to 0xFF
        0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7,
        0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9
    };
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::data::string_converter {

    bool iso_iec_8859_2_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-2 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* /*end_it*/, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-2. Non-trivial conversion; use a LUT
                    decoded = s_lut[*next_it - 0xA0];
                }

                next_it++;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_2(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-2 directly maps to BMP, but may use two-byte UTF-8 sequences.
        encoded_dest.resize(utf8_source.size());

        return detail::utf8_to_8bit_encoded<1>(
            utf8_source,
            encoded_dest,
            [](char32_t c, uint8_t*& next_it) {
                if (c < 0xA0) {
                    // ASCII. Direct mapping to BMP.
                    *next_it++ = static_cast<uint8_t>(c);
                    return true;
                }

                if (c >= 0x10000) {
                    return false;
                }

                // ISO/IEC 8859-2. Non-trivial conversion; use a LUT
                auto it = detail::find_codepoint00(s_lut, static_cast<uint16_t>(c));
                if (it == nullptr) { return false; }

                *next_it++ = static_cast<uint8_t>(0xA0 + std::distance(std::begin(s_lut), it));
                return true;
            }
        );
    }

}