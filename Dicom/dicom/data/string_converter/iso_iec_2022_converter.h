#pragma once

#include "dicom/data/StringEncodingType.h"

namespace dicom::data::string_converter {

    // Converters
    DICOM_EXPORT [[nodiscard]] bool iso_iec_2022_to_utf8(
        const std::string_view& encoded_source,
        std::string& utf8_dest,
        data::StringEncodingType string_encoding
    );
    DICOM_EXPORT [[nodiscard]] bool utf8_to_iso_iec_2022(
        const std::string_view& utf8_source,
        std::string& encoded_dest,
        data::StringEncodingType string_encoding
    );

    // Helper to get the ISO/IEC 2022 escape sequence for a string encoding
    DICOM_EXPORT [[nodiscard]] bool get_code_extension_bytes(
        data::StringEncodingType string_encoding,
        std::string_view* extension_bytes
    );

    // Helper to extract all the string encodings used in [string]
    DICOM_EXPORT [[nodiscard]] bool extract_string_encodings(
        const std::string_view& string,
        std::set<data::StringEncodingType>& string_encodings
    );

}