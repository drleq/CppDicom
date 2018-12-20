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
            ByteRangeGroupPtr range_0x21(new ByteRangeGroup);
            range_0x21->Add(0xA1, 0xFE);

            ByteRangeGroupPtr range_0x22(new ByteRangeGroup);
            range_0x22->Add(0xA1, 0xE5);

            ByteRangeGroupPtr range_0x23_24(new ByteRangeGroup);
            range_0x23_24->Add(0xA1, 0xFE);

            ByteRangeGroupPtr range_0x25(new ByteRangeGroup);
            range_0x25->Add(0xA1, 0xAA);
            range_0x25->Add(0xB0, 0xB9);
            range_0x25->Add(0xC1, 0xD8);
            range_0x25->Add(0xE1, 0xF8);

            ByteRangeGroupPtr range_0x26(new ByteRangeGroup);
            range_0x26->Add(0xA1, 0xE4);

            ByteRangeGroupPtr range_0x27(new ByteRangeGroup);
            range_0x27->Add(0xA1, 0xEF);

            ByteRangeGroupPtr range_0x28(new ByteRangeGroup);
            range_0x28->Add(0xA1, 0xA4);
            range_0x28->Add(0xA6, 0xA6);
            range_0x28->Add(0xA8, 0xAF);
            range_0x28->Add(0xB1, 0xFE);

            ByteRangeGroupPtr range_0x29(new ByteRangeGroup);
            range_0x29->Add(0xA1, 0xFE);

            ByteRangeGroupPtr range_0x2A(new ByteRangeGroup);
            range_0x2A->Add(0xA1, 0xF3);

            ByteRangeGroupPtr range_0x2B(new ByteRangeGroup);
            range_0x2B->Add(0xA1, 0xF6);

            ByteRangeGroupPtr range_0x2C(new ByteRangeGroup);
            range_0x2C->Add(0xA1, 0xC1);
            range_0x2C->Add(0xD1, 0xF1);

            ByteRangeGroupPtr range_0x30_48(new ByteRangeGroup);
            range_0x30_48->Add(0xA1, 0xFE);

            ByteRangeGroupPtr range_0x4A_7D(new ByteRangeGroup);
            range_0x4A_7D->Add(0xA1, 0xFE);

            ByteRangeGroupPtr root_range(new ByteRangeGroup);
            root_range->Add(0xA1, 0xA1, range_0x21);
            root_range->Add(0xA2, 0xA2, range_0x22);
            root_range->Add(0xA3, 0xA4, range_0x23_24);
            root_range->Add(0xA5, 0xA5, range_0x25);
            root_range->Add(0xA6, 0xA6, range_0x26);
            root_range->Add(0xA7, 0xA7, range_0x27);
            root_range->Add(0xA8, 0xA8, range_0x28);
            root_range->Add(0xA9, 0xA9, range_0x29);
            root_range->Add(0xAA, 0xAA, range_0x2A);
            root_range->Add(0xAB, 0xAB, range_0x2B);
            root_range->Add(0xAC, 0xAC, range_0x2C);
            root_range->Add(0xB0, 0xC8, range_0x30_48);
            root_range->Add(0xCA, 0xFD, range_0x4A_7D);

            m_mapping = LoadMapping("dicom_test/data/string_converter/KSX1001.TXT", root_range, MoveToG1Plane);
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