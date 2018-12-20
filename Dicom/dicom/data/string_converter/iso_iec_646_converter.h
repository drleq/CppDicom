#pragma once

namespace dicom::data::string_converter {

    [[nodiscard]] bool iso_iec_646_to_utf8(const std::string_view& string, std::string& dest);
    [[nodiscard]] bool utf8_to_iso_iec_646(const std::string_view& string, std::string& dest);

}