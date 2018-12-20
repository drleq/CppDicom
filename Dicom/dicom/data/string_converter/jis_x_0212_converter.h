#pragma once

namespace dicom::data::string_converter {

    [[nodiscard]] bool jis_x_0212_to_utf8(const std::string_view& encoded_source, std::string& utf8_dest);
    [[nodiscard]] bool utf8_to_jis_x_0212(const std::string_view& utf8_source, std::string& encoded_dest);

}