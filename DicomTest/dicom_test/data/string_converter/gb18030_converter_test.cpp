#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/gb18030_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class gb18030_converter_test : public CommonFixture {
    public:
        gb18030_converter_test() {
            m_mapping = LoadMapping("dicom_test/data/string_converter/gb-18030-2000.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE_WITH_TAGS(gb18030_converter_test, ValidToUTF8, "string_converter") {
        REQUIRE(m_mapping->CheckValidByteSequences(gb_18030_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE_WITH_TAGS(gb18030_converter_test, InvalidToUTF8, "string_converter") {
        REQUIRE(m_mapping->CheckInvalidByteSequences(gb_18030_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE_WITH_TAGS(gb18030_converter_test, ValidFromUTF8, "string_converter") {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_gb_18030));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE_WITH_TAGS(gb18030_converter_test, InvalidFromUTF8, "string_converter") {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_gb_18030));
    }

}