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
            ByteRangeGroupPtr range_0x21(new ByteRangeGroup);
            range_0x21->Add(0x21, 0x7E);

            ByteRangeGroupPtr range_0x22(new ByteRangeGroup);
            range_0x22->Add(0x21, 0x2E);
            range_0x22->Add(0x3A, 0x41);
            range_0x22->Add(0x4A, 0x50);
            range_0x22->Add(0x5C, 0x6A);
            range_0x22->Add(0x72, 0x79);
            range_0x22->Add(0x7E, 0x7E);

            ByteRangeGroupPtr range_0x23(new ByteRangeGroup);
            range_0x23->Add(0x30, 0x39);
            range_0x23->Add(0x41, 0x5A);
            range_0x23->Add(0x61, 0x7A);

            ByteRangeGroupPtr range_0x24(new ByteRangeGroup);
            range_0x24->Add(0x21, 0x73);

            ByteRangeGroupPtr range_0x25(new ByteRangeGroup);
            range_0x25->Add(0x21, 0x76);

            ByteRangeGroupPtr range_0x26(new ByteRangeGroup);
            range_0x26->Add(0x21, 0x38);
            range_0x26->Add(0x41, 0x58);

            ByteRangeGroupPtr range_0x27(new ByteRangeGroup);
            range_0x27->Add(0x21, 0x41);
            range_0x27->Add(0x51, 0x71);

            ByteRangeGroupPtr range_0x28(new ByteRangeGroup);
            range_0x28->Add(0x21, 0x40);

            ByteRangeGroupPtr range_0x2D(new ByteRangeGroup);
            range_0x2D->Add(0x21, 0x3E);
            range_0x2D->Add(0x40, 0x56);
            range_0x2D->Add(0x5F, 0x7C);

            ByteRangeGroupPtr range_0x30_4E(new ByteRangeGroup);
            range_0x30_4E->Add(0x21, 0x7E);

            ByteRangeGroupPtr range_0x4F(new ByteRangeGroup);
            range_0x4F->Add(0x21, 0x53);

            ByteRangeGroupPtr range_0x50_73(new ByteRangeGroup);
            range_0x50_73->Add(0x21, 0x7E);

            ByteRangeGroupPtr range_0x74(new ByteRangeGroup);
            range_0x74->Add(0x21, 0x26);

            ByteRangeGroupPtr root_range(new ByteRangeGroup);
            root_range->Add(0x21, 0x21, range_0x21);
            root_range->Add(0x22, 0x22, range_0x22);
            root_range->Add(0x23, 0x23, range_0x23);
            root_range->Add(0x24, 0x24, range_0x24);
            root_range->Add(0x25, 0x25, range_0x25);
            root_range->Add(0x26, 0x26, range_0x26);
            root_range->Add(0x27, 0x27, range_0x27);
            root_range->Add(0x28, 0x28, range_0x28);
            root_range->Add(0x2D, 0x2D, range_0x2D);
            root_range->Add(0x30, 0x4E, range_0x30_4E);
            root_range->Add(0x4F, 0x4F, range_0x4F);
            root_range->Add(0x50, 0x73, range_0x50_73);
            root_range->Add(0x74, 0x74, range_0x74);

            m_mapping = LoadMapping("dicom_test/data/string_converter/CP932.TXT", root_range, ShiftJISToJISX0208);
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