#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_7_converter.h"

#include "dicom/data/string_converter/detail/find_codepoint.h"
#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace {
    // UTF-32 code points stored as UTF-16 for efficiency.
    constexpr uint16_t s_lut[2*16] = {
        // 0xA0 to 0xAF
        0x00A0, 0x2018, 0x2019, 0x00A3, 0x20AC, 0x20AF, 0x00A6, 0x00A7,
        0x00A8, 0x00A9, 0x037A, 0x00AB, 0x00AC, 0x00AD, 0x0000, 0x2015,
        // 0xB0 to 0xBF
        0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x0384, 0x0385, 0x0386, 0x00B7,
        0x0388, 0x0389, 0x038A, 0x00BB, 0x038C, 0x00BD, 0x038E, 0x038F
    };
}

//------------------------------------------------------------------------------------------------------------

namespace dicom::data::string_converter {

    bool iso_iec_8859_7_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-2 directly maps to BMP, but may use three-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-7.
                    if (*next_it < 0xC0) { decoded = s_lut[*next_it - 0xA0]; } // 0xA0 to 0xBF is non-trivial; use a lut
                    else { decoded = 0x0390 + (*next_it - 0xC0); }             // Linear mapping
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_7(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-2 directly maps to BMP, but may use three-byte UTF-8 sequences.
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

                // ISO/IEC 8859-7
                if (c >= 0x0390 && c <= 0x03CE) {
                    if (c == 0x03A2) { return false; }

                    // Linear mapping
                    *next_it++ = static_cast<uint8_t>((c - 0x0390) + 0xC0);
                    return true;
                }

                // Non-trivial. Check the LUT.
                auto it = detail::find_codepoint00(s_lut, c);
                if (it == nullptr) { return false; }
                *next_it++ = static_cast<uint8_t>(0xA0 + std::distance(std::begin(s_lut), it));

                return true;
            }
        );
    }

}