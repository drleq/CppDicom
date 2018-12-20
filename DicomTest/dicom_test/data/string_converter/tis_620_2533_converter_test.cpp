#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/tis_620_2533_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class tis_620_2533_converter_test : public CommonFixture {
    public:
        tis_620_2533_converter_test() {
            m_mapping = LoadMapping("dicom_test/data/string_converter/aix-TIS_620-4.3.6.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(tis_620_2533_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(tis_620_2533_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(tis_620_2533_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(tis_620_2533_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(tis_620_2533_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_tis_620_2533));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(tis_620_2533_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_tis_620_2533));
    }

}