#pragma once

#include "dicom_test/data/string_converter/detail/CharacterMapping.h"

namespace dicom_test::data::string_converter {

    using detail::CodePointRange;
    using detail::CodePointRangeList;
    using detail::CodePoints;

    class CommonFixture
    {
    public:
        static void ReleaseStatics() {
            s_mapping.reset();
            s_mapping_file.clear();
        }

    protected:
        detail::CharacterMappingPtr LoadMapping(const std::filesystem::path& character_mapping) {
            if (s_mapping_file != character_mapping.string()) {
                s_mapping_file = character_mapping.string();
                s_mapping.reset(new detail::CharacterMapping(character_mapping));
            }
            return s_mapping;
        }

        detail::CharacterMappingPtr LoadMapping(
            const std::filesystem::path& character_mapping,
            const detail::CodePoints& root_valid_range,
            std::function<bool (std::string&)> filter00 = nullptr
        ) {
            if (s_mapping_file != character_mapping.string()) {
                s_mapping_file = character_mapping.string();
                s_mapping.reset(new detail::CharacterMapping(character_mapping, root_valid_range, filter00));
            }
            return s_mapping;
        }

    private:
        static std::string s_mapping_file;
        static detail::CharacterMappingPtr s_mapping;
    };

}