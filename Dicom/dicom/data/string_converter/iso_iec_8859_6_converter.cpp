#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_6_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool iso_iec_8859_6_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-6 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* /*end_it*/, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it++;
                    return true;
                }

                // ISO/IEC 8859-6.
                switch (*next_it) {
                // Special case mappings
                case 0xAC: decoded = 0x060C; break; // Comma
                case 0xBB: decoded = 0x061B; break; // Semicolon
                case 0xBF: decoded = 0x061F; break; // Question mark

                // Isolated linear mappings
                case 0xA0: decoded = 0x00A0; break;
                case 0xA4: decoded = 0x00A4; break;
                case 0xAD: decoded = 0x00AD; break;

                default:
                    if (*next_it < 0xC1 || *next_it > 0xF2) {
                        return false;
                    }
                    if (*next_it > 0xDA && *next_it < 0xE0) {
                        return false;
                    }

                    // Linear mapping
                    decoded= 0x0621 + (*next_it - 0xC1);
                }
                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_6(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-6 directly maps to BMP, but may use two-byte UTF-8 sequences.
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

                // ISO/IEC 8859-6
                switch (c) {
                // Special case mappings
                case 0x060C: *next_it = 0xAC; break; // Comma
                case 0x061B: *next_it = 0xBB; break; // Semicolon
                case 0x061F: *next_it = 0xBF; break; // Question mark

                // Isolated linear mappings
                case 0x00A0: *next_it = 0xA0; break;
                case 0x00A4: *next_it = 0xA4; break;
                case 0x00AD: *next_it = 0xAD; break;

                default:
                    if (c < 0x0621 || c > 0x0652) {
                        return false;
                    }
                    if (c > 0x063A && c < 0x0640) {
                        return false;
                    }

                    // Linear mapping.
                    *next_it = static_cast<uint8_t>(0xC1 + (c - 0x0621));
                }

                ++next_it;
                return true;
            }
        );
    }

}