#pragma once

namespace dicom::data::string_converter {

    DICOM_EXPORT [[nodiscard]] bool ks_x_1001_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    DICOM_EXPORT [[nodiscard]] bool utf8_to_ks_x_1001(const std::string_view& utf8_source, std::string& encoded_dest);

}