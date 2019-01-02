#include "dicom_pch.h"
#include "dicom/data/string_converter/iso_iec_8859_1_converter.h"

#include "dicom/data/string_converter/detail/utf8_helpers.h"

namespace dicom::data::string_converter {

    bool iso_iec_8859_1_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest) {
        // ISO/IEC 8859-1 directly maps to BMP, but may use two-byte UTF-8 sequences.
        return detail::encoded_to_utf8(
            encoded_source,
            utf8_dest,
            [](const uint8_t*& next_it, const uint8_t* /*end_it*/, char32_t& decoded) {
                decoded = *next_it;
                next_it++;
                return true;
            }
        );
    }

    //--------------------------------------------------------------------------------------------------------

    bool utf8_to_iso_iec_8859_1(const std::string_view& utf8_source, std::string& encoded_dest) {
        // ISO/IEC 8859-1 directly maps to BMP, but may use two-byte UTF-8 sequences.
        encoded_dest.resize(utf8_source.size());

        return detail::utf8_to_8bit_encoded<1>(
            utf8_source,
            encoded_dest,
            [](char32_t c, uint8_t*& next_it) {
                if (c > 0xFF) { return false; }

                *next_it++ = static_cast<uint8_t>(c);
                return true;
            }
        );
    }

}