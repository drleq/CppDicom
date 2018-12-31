#pragma once

#include "dicom/data/buffer.h"
#include "dicom/data/StringEncodingType.h"

namespace dicom::data::string_converter {
    
    DICOM_EXPORT [[nodiscard]] StringEncodingType convert_to_string_encoding(
        const std::vector<std::string_view>& character_sets
    );

    DICOM_EXPORT [[nodiscard]] bool convert_from_string_encoding(
        StringEncodingType encoding,
        std::vector<std::string_view>& character_sets
    );

    DICOM_EXPORT [[nodiscard]] bool convert_to_utf8(
        StringEncodingType string_encoding,
        const std::string_view& encoded_source,
        std::string& utf8_dest
    );

    DICOM_EXPORT [[nodiscard]] bool convert_from_utf8(
        StringEncodingType string_encoding,
        const std::string& utf8_source,
        data::buffer<char>& encoded_dest
    );

}