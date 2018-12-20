#pragma once

#include <filesystem>

#include "dicom_test/data/string_converter/detail/ByteRangeGroup.h"
#include "dicom_test/data/string_converter/detail/RangeAssignment.h"

namespace dicom_test::data::string_converter::detail {

    class CharacterMapping
    {
    public:
        CharacterMapping(const std::filesystem::path& xml_file);
        CharacterMapping(
            const std::filesystem::path& txt_file,
            const ByteRangeGroupPtr& valid_ranges,
            std::function<bool (std::string&)> filter00 = nullptr
        );

        //----------------------------------------------------------------------------------------------------

        bool CheckValidByteSequences(StringConverterToUTF8 converter) const;
        bool CheckValidUnicodeValues(StringConverterFromUTF8 converter) const;

        bool CheckInvalidByteSequences(StringConverterToUTF8 converter) const;
        bool CheckInvalidUnicodeValues(StringConverterFromUTF8 converter) const;

    private:
        ByteRangeGroupPtr m_root_valid_range;

        std::map<uint32_t, std::string> m_valid_unicode_values;
        std::vector<RangeAssignment> m_valid_unicode_ranges;
    };

    using CharacterMappingPtr = std::shared_ptr<CharacterMapping>;

}