#pragma once

namespace dicom::data::string_converter {

    DICOM_EXPORT [[nodiscard]] bool iso_iec_8859_2_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    DICOM_EXPORT [[nodiscard]] bool utf8_to_iso_iec_8859_2(const std::string_view& utf8_source, std::string& encoded_dest);

}