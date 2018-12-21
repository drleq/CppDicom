#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/ks_x_1001_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;
    using namespace dicom_test::data::string_converter::detail;

    class ks_x_1001_converter_test : public CommonFixture {
    public:
        ks_x_1001_converter_test() {
            CodePoints valid_ranges = {
                CodePointRange {
                    0xA1, 0xA1,
                    { {0xA1, 0xFE} }
                },
                CodePointRange {
                    0xA2, 0xA2,
                    { {0xA1, 0xE5} }
                },
                CodePointRange {
                    0xA3, 0xA4,
                    { {0xA1, 0xFE} }
                },
                CodePointRange {
                    0xA5, 0xA5,
                    { {0xA1, 0xAA}, {0xB0, 0xB9}, {0xC1, 0xD8}, {0xE1, 0xF8} }
                },
                CodePointRange {
                    0xA6, 0xA6,
                    { {0xA1, 0xE4} }
                },
                CodePointRange {
                    0xA7, 0xA7,
                    { {0xA1, 0xEF} }
                },
                CodePointRange {
                    0xA8, 0xA8,
                    { {0xA1, 0xA4}, {0xA6, 0xA6}, {0xA8, 0xAF}, {0xB1, 0xFE} }
                },
                CodePointRange {
                    0xA9, 0xA9,
                    { {0xA1, 0xFE} }
                },
                CodePointRange {
                    0xAA, 0xAA,
                    { {0xA1, 0xF3} }
                },
                CodePointRange {
                    0xAB, 0xAB,
                    { {0xA1, 0xF6} }
                },
                CodePointRange {
                    0xAC, 0xAC,
                    { {0xA1, 0xC1}, {0xD1, 0xF1} }
                },
                CodePointRange {
                    0xB0, 0xC8,
                    { {0xA1, 0xFE} }
                },
                CodePointRange {
                    0xCA, 0xFD,
                    { {0xA1, 0xFE} }
                }
            };

            m_mapping = LoadMapping("dicom_test/data/string_converter/KSX1001.TXT", valid_ranges, MoveToG1Plane);
        }

    protected:
        detail::CharacterMappingPtr m_mapping;

        static bool MoveToG1Plane(std::string& seq) {
            if (seq.size() != 2) { return false; }

            // KS X 1001: (s1,s2)
            // EUC_KR:    (c1,c2) <-- used as code extensions G1 plane
            //
            // c1 = s1 + 0x80
            // c2 = s2 + 0x80

            seq[0] += 0x80;
            seq[1] += 0x80;
            return true;
        }
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(ks_x_1001_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(ks_x_1001_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ks_x_1001_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(ks_x_1001_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ks_x_1001_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_ks_x_1001));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ks_x_1001_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_ks_x_1001));
    }

}