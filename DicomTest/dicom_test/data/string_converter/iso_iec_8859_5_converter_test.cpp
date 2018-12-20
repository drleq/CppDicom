#include "dicomtest_pch.h"
#include "boost/test/unit_test.hpp"

#include "dicom/data/string_converter/iso_iec_8859_5_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;

    class TestFixture : public CommonFixture {
    public:
        TestFixture() {
            m_mapping = LoadMapping(L"dicom_test/data/string_converter/iso-8859_5-1999.xml");
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    BOOST_FIXTURE_TEST_SUITE(iso_iec_8859_5_converter_test, TestFixture)

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(ValidToUTF16) {
        BOOST_REQUIRE(m_mapping->CheckValidByteSequences(iso_iec_8859_5_to_utf16));
    }

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(InvalidToUTF16) {
        BOOST_REQUIRE(m_mapping->CheckInvalidByteSequences(iso_iec_8859_5_to_utf16));
    }

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(ValidFromUTF16) {
        BOOST_REQUIRE(m_mapping->CheckValidUnicodeValues(utf16_to_iso_iec_8859_5));
    }

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(InvalidFromUTF16) {
        BOOST_REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf16_to_iso_iec_8859_5));
    }

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_SUITE_END()

}