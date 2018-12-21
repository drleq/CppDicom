#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/jis_x_0212_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;
    using namespace dicom_test::data::string_converter::detail;

    class jis_x_0212_converter_test : public CommonFixture {
    public:
        jis_x_0212_converter_test() {
            CodePoints valid_ranges = {
                CodePointRange {
                    0x22, 0x22,
                    { {0x2F, 0x39}, {0x42, 0x44}, {0x6B, 0x71} }
                },
                CodePointRange {
                    0x26, 0x26,
                    { {0x61, 0x65}, {0x67, 0x67}, {0x69, 0x6A}, {0x6C, 0x6C}, {0x71, 0x7C} }
                },
                CodePointRange {
                    0x27, 0x27,
                    { {0x42, 0x4E}, {0x72, 0x7E} }
                },
                CodePointRange {
                    0x29, 0x29,
                    { {0x21, 0x22}, {0x24, 0x24}, {0x26, 0x26}, {0x28, 0x29}, {0x2B, 0x2D}, {0x2F, 0x30}, {0x41, 0x50} }
                },
                CodePointRange {
                    0x2A, 0x2A,
                    { {0x21, 0x38}, {0x3A, 0x77} }
                },
                CodePointRange {
                    0x2B, 0x2B,
                    { {0x21, 0x3B}, {0x3D, 0x43}, {0x45, 0x77} }
                },
                CodePointRange {
                    0x30, 0x6C,
                    { {0x21, 0x7E} }
                },
                CodePointRange {
                    0x6D, 0x6D,
                    { {0x21, 0x63} }
                }
            };

            m_mapping = LoadMapping("dicom_test/data/string_converter/JIS0212.TXT", valid_ranges);
        }

    protected:
        detail::CharacterMappingPtr m_mapping;
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(jis_x_0212_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(jis_x_0212_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0212_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(jis_x_0212_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0212_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_jis_x_0212));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0212_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_jis_x_0212));
    }

}