#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_5_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool iso_iec_8859_5_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-5 directly maps to BMP, but may use three-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* /*end_it*/, char32_t& decoded) {
                if (*next_it < 0xA0) {
                    // ASCII. Direct mapping to BMP
                    decoded = *next_it;
                } else {
                    // ISO/IEC 8859-5.
                    switch (*next_it) {
                    case 0xA0: decoded = 0x00A0; break; // Non-breaking space
                    case 0xAD: decoded = 0x00AD; break; // Soft hyphen
                    case 0xF0: decoded = 0x2116; break; // Numero sign
                    case 0xFD: decoded = 0x00A7; break; // Section sign
                    default:
                        decoded = 0x0401 + (*next_it - 0xA1);
                        break;
                    }
                }

                ++next_it;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_5(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-5 directly maps to BMP, but may use three-byte UTF-8 sequences.
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

                // ISO/IEC 8859-5
                switch (c) {
                case 0x00A0: *next_it = 0xA0; break; // Non-breaking space
                case 0x00AD: *next_it = 0xAD; break; // Soft hyphen
                case 0x2116: *next_it = 0xF0; break; // Numero sign
                case 0x00A7: *next_it = 0xFD; break; // Section sign
                default:
                    // Check the range is correct.
                    if (c < 0x0401 || c > 0x045F) { return false; }

                    // Check the values replaced by the above special cases.
                    switch (c) {
                    case 0x040D:
                    case 0x0450:
                    case 0x045D:
                        return false;
                    }

                    // Linear mapping.
                    *next_it = static_cast<uint8_t>((c + 0xA1) - 0x0401);
                    break;
                }

                ++next_it;
                return true;
            }
        );
    }

}