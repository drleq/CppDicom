#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/jis_x_0201_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class jis_x_0201_converter_test : public CommonFixture {
    public:
        jis_x_0201_converter_test() {
            m_mapping = LoadMapping("dicom_test/data/string_converter/aix-JISX0201.1976_0-4.3.6.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(jis_x_0201_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(jis_x_0201_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0201_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(jis_x_0201_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0201_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_jis_x_0201));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0201_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_jis_x_0201));
    }

}