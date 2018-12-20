#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/gb18030_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class gb2312_converter_test : public CommonFixture {
    public:
        gb2312_converter_test() {
            m_mapping = LoadMapping(L"dicom_test/data/string_converter/glibc-EUC_CN-2.1.2.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(gb2312_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(gb_2312_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(gb2312_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(gb_2312_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(gb2312_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_gb_2312));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(gb2312_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_gb_2312));
    }

}