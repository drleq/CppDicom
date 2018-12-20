#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_646_converter.h"

namespace dicom::data::string_converter {

    bool iso_iec_646_to_utf8(const std::string_view& string, std::string& dest) {
        // ISO/IEC 646 is just ASCII, which has a direct mapping to UTF-8.
        dest.resize(string.size());

        auto dest_it = dest.begin();
        for (uint8_t c : string) {
            if (c > 0x7F) {
                // Verify the character is in the correct range.
                return false;
            }

            *dest_it++ = c;
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_646(const std::string_view& string, std::string& dest) {
        // ISO/IEC 646 is just ASCII, which has a direct mapping to UTF-8.
        dest.resize(string.size());

        auto dest_it = dest.data();
        for (uint8_t c : string) {
            if (c > 0x7F) {
                // Verify the character is in the correct range.
                return false;
            }

            *dest_it++ = c;
        }

        return true;
    }

}