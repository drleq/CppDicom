#include "dicom_pch.h"
#include "dicom/data/detail/DefaultCharacterRepertoire.h"

namespace {
    [[nodiscard]] bool is_control_character(uint8_t c) {
        // There are five control characters:
        //   TAB (0x09)
        //   LF  (0x0A)
        //   FF  (0x0C)
        //   CR  (0x0D)
        //   ESC (0x1B)
        return (c == 0x09) || (c == 0x0A) || (c == 0x0C) || (c == 0x0D) || (c == 0x1B);
    }
}

namespace dicom::data::detail {

    bool validate_default_character_repertoire(const std::string_view& value) {
        for (uint8_t c : value) {
            // All characters from 0x20 to 0x7F are valid
            if (c > 0x7F) { return false; }
            if (c < 0x20) {
                // There are five exceptions to the control character set
                if (!is_control_character(c)) { return false; }
            }
        }

        return true;
    }

    //--------------------------------------------------------------------------------------------------------

    bool validate_excludes_control_characters(const std::string_view& value) {
        for (uint8_t c : value) {
            if (is_control_character(c)) { return false; }
        }

        return true;
    }

}