#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_8_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

//------------------------------------------------------------------------------------------------------------

namespace dicom::data::string_converter {

    bool iso_iec_8859_8_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-8 directly maps to BMP, but may use three-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    decoded = *next_it++;
                    return true;
                }

                // ISO/IEC 8859-8.
                switch (*next_it) {
                case 0xA1: return false;
                case 0xAA: decoded = 0x00D7; break;
                case 0xBA: decoded = 0x00F7; break;
                case 0xDF: decoded = 0x2017; break;
                case 0xFD: decoded = 0x200E; break;
                case 0xFE: decoded = 0x200F; break;
                default:
                    if (*next_it > 0xBE && *next_it < 0xDF) {
                        return false;
                    }
                    if (*next_it > 0xFA) {
                        return false;
                    }

                    if (*next_it <= 0xBE) {
                        // 0xA0 to 0xBE is a direct mapping to BMP
                        decoded = *next_it;
                    } else {
                        // Linear mapping
                        decoded = 0x05D0 + (*next_it - 0xE0);
                    }
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_8(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-8 directly maps to BMP, but may use three-byte UTF-8 sequences.
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

                // ISO/IEC 8859-8
                switch (c) {
                case 0x00A1:
                case 0x00AA:
                case 0x00BA:
                    return false;

                case 0x00D7: *next_it = 0xAA; break;
                case 0x00F7: *next_it = 0xBA; break;
                case 0x2017: *next_it = 0xDF; break;
                case 0x200E: *next_it = 0xFD; break;
                case 0x200F: *next_it = 0xFE; break;
                default:
                    if (c > 0x05EA) { return false; }
                    if (c > 0x00BE && c < 0x05D0) { return false; }
                    if (c < 0xBF) {
                        // Direct mapping to BMP
                        *next_it = static_cast<uint8_t>(c);
                    } else {
                        // Linear mapping.
                        *next_it = static_cast<uint8_t>(0xE0 + (c - 0x05D0));
                    }
                }

                ++next_it;
                return true;
            }
        );
    }

}