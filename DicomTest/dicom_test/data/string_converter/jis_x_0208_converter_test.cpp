#include "dicomtest_pch.h"
#include "CppUnitTestFramework.hpp"

#include "dicom/data/string_converter/jis_x_0208_converter.h"
#include "dicom_test/data/string_converter/CommonFixture.h"
using namespace dicom::data::string_converter;

namespace {
    using namespace dicom_test::data::string_converter;
    using namespace dicom_test::data::string_converter::detail;

    class jis_x_0208_converter_test : public CommonFixture {
    public:
        jis_x_0208_converter_test() {
            CodePoints valid_ranges = {
                CodePointRange {
                    0x21, 0x21,
                    { {0x21, 0x7E} }
                },
                CodePointRange {
                    0x22, 0x22,
                    { {0x21, 0x2E}, {0x3A, 0x41}, {0x4A, 0x50}, {0x5C, 0x6A}, {0x72, 0x79}, {0x7E, 0x7E} }
                },
                CodePointRange {
                    0x23, 0x23,
                    { {0x30, 0x39}, {0x41, 0x5A}, {0x61, 0x7A} }
                },
                CodePointRange {
                    0x24, 0x24,
                    { {0x21, 0x73} }
                },
                CodePointRange {
                    0x25, 0x25,
                    { {0x21, 0x76} }
                },
                CodePointRange {
                    0x26, 0x26,
                    { {0x21, 0x38}, {0x41, 0x58} }
                },
                CodePointRange {
                    0x27, 0x27,
                    { {0x21, 0x41}, {0x51, 0x71} }
                },
                CodePointRange {
                    0x28, 0x28,
                    { {0x21, 0x40} }
                },
                CodePointRange {
                    0x2D, 0x2D,
                    { {0x21, 0x3E}, {0x40, 0x56}, {0x5F, 0x7C} }
                },
                CodePointRange {
                    0x30, 0x4E,
                    { {0x21, 0x7E} }
                },
                CodePointRange {
                    0x4F, 0x4F,
                    { {0x21, 0x53} }
                },
                CodePointRange {
                    0x50, 0x73,
                    { {0x21, 0x7E} }
                },
                CodePointRange {
                    0x74, 0x74,
                    { {0x21, 0x26} }
                },
            };

            m_mapping = LoadMapping("dicom_test/data/string_converter/CP932.TXT", valid_ranges, ShiftJISToJISX0208);
        }

    protected:
        detail::CharacterMappingPtr m_mapping;

        static bool ShiftJISToJISX0208(std::string& seq) {
            if (seq.size() != 2) { return false; }

            // Shift JIS:  (s1,s2)
            // JIS X 0208: (c1,c2)
            // 
            // s1 = floor((c1 + 1) / 2) + 112   IF 33 <= c1 <= 94
            //    = floor((c1 + 1) / 2) + 176   IF 95 <= c1 <= 126
            // s2 = c2 + 31 + floor(c2 / 96)    IF odd(c1)
            //    = c2 + 126                    IF even(c1)
            
            uint32_t s1 = uint8_t(seq[0]);
            uint32_t s2 = uint8_t(seq[1]);

            // Ignore mappings that aren't for JIS X 0208.
            bool in_range = (s1 >= 0x81 && s1 <= 0x9F);
            in_range |= (s1 == 0x87);
            in_range |= (s1 >= 0xE0 && s1 <= 0xEA);
            if (!in_range) { return false; }

            uint32_t t1 = (s1 < 0xE0) ? (s1 - 0x81) : (s1 - 0xC1);
            uint32_t t2 = (s2 < 0x80) ? (s2 - 0x40) : (s2 - 0x41);
            uint32_t c1 = (2 * t1) + ((t2 < 0x5E) ? 0 : 1) + 0x21;
            uint32_t c2 = ((t2 < 0x5E) ? t2 : (t2 - 0x5E)) + 0x21;

            seq[0] = uint8_t(c1);
            seq[1] = uint8_t(c2);
            return true;
        }
    };
}

namespace dicom_test::data::string_converter {

    TEST_CASE(jis_x_0208_converter_test, ValidToUTF8) {
        REQUIRE(m_mapping->CheckValidByteSequences(jis_x_0208_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0208_converter_test, InvalidToUTF8) {
        REQUIRE(m_mapping->CheckInvalidByteSequences(jis_x_0208_to_utf8));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0208_converter_test, ValidFromUTF8) {
        REQUIRE(m_mapping->CheckValidUnicodeValues(utf8_to_jis_x_0208));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(jis_x_0208_converter_test, InvalidFromUTF8) {
        REQUIRE(m_mapping->CheckInvalidUnicodeValues(utf8_to_jis_x_0208));
    }

}