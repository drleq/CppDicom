#pragma once

namespace dicom::data::string_converter {

    [[nodiscard]] bool gb_18030_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    [[nodiscard]] bool utf8_to_gb_18030(const std::string_view& utf8_source, std::string& encoded_dest);

    [[nodiscard]] bool gbk_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    [[nodiscard]] bool utf8_to_gbk(const std::string_view& utf8_source, std::string& encoded_dest);

    [[nodiscard]] bool gb_2312_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    [[nodiscard]] bool utf8_to_gb_2312(const std::string_view& utf8_source, std::string& encoded_dest);

}