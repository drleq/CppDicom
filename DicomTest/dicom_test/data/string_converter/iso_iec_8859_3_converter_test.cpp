#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/iso_iec_8859_3_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class iso_iec_8859_3_converter_test : public CommonFixture {
    public:
        iso_iec_8859_3_converter_test() {
            m_mapping = LoadMapping(L"dicom_test/data/string_converter/iso-8859_3-1999.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(iso_iec_8859_3_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(iso_iec_8859_3_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(iso_iec_8859_3_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(iso_iec_8859_3_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(iso_iec_8859_3_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_iso_iec_8859_3));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(iso_iec_8859_3_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_iso_iec_8859_3));
    }

}