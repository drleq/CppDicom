#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_9_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool iso_iec_8859_9_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-9 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* end_it, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-9. There are 6 Turkish specializations. All other characters map directly
                    // to the BMP.
                         if (*next_it == 0xD0) { decoded = 0x011E; }
                    else if (*next_it == 0xDD) { decoded = 0x0130; }
                    else if (*next_it == 0xDE) { decoded = 0x015E; }
                    else if (*next_it == 0xF0) { decoded = 0x011F; }
                    else if (*next_it == 0xFD) { decoded = 0x0131; }
                    else if (*next_it == 0xFE) { decoded = 0x015F; }
                    else { decoded = *next_it; }
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_9(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-9 directly maps to BMP, but may use two-byte UTF-8 sequences.
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

                // ISO/IEC 8859-9
                // There are 6 Turkish specializations. All other characters map directly to the BMP.
                switch (c) {
                case 0x00D0:
                case 0x00DD:
                case 0x00DE:
                case 0x00F0:
                case 0x00FD:
                case 0x00FE:
                    return false;

                case 0x011E: *next_it = 0xD0; break;
                case 0x0130: *next_it = 0xDD; break;
                case 0x015E: *next_it = 0xDE; break;
                case 0x011F: *next_it = 0xF0; break;
                case 0x0131: *next_it = 0xFD; break;
                case 0x015F: *next_it = 0xFE; break;
                default:
                    if (c > 0x00FF) { return false; }
                    *next_it = static_cast<uint8_t>(c);
                }

                ++next_it;
                return true;
            }
        );
    }

}