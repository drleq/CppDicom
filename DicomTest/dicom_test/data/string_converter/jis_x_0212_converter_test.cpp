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
            ByteRangeGroupPtr range_0x22(new ByteRangeGroup);
            range_0x22->Add(0x2F, 0x39);
            range_0x22->Add(0x42, 0x44);
            range_0x22->Add(0x6B, 0x71);

            ByteRangeGroupPtr range_0x26(new ByteRangeGroup);
            range_0x26->Add(0x61, 0x65);
            range_0x26->Add(0x67, 0x67);
            range_0x26->Add(0x69, 0x6A);
            range_0x26->Add(0x6C, 0x6C);
            range_0x26->Add(0x71, 0x7C);

            ByteRangeGroupPtr range_0x27(new ByteRangeGroup);
            range_0x27->Add(0x42, 0x4E);
            range_0x27->Add(0x72, 0x7E);

            ByteRangeGroupPtr range_0x29(new ByteRangeGroup);
            range_0x29->Add(0x21, 0x22);
            range_0x29->Add(0x24, 0x24);
            range_0x29->Add(0x26, 0x26);
            range_0x29->Add(0x28, 0x29);
            range_0x29->Add(0x2B, 0x2D);
            range_0x29->Add(0x2F, 0x30);
            range_0x29->Add(0x41, 0x50);

            ByteRangeGroupPtr range_0x2A(new ByteRangeGroup);
            range_0x2A->Add(0x21, 0x38);
            range_0x2A->Add(0x3A, 0x77);

            ByteRangeGroupPtr range_0x2B(new ByteRangeGroup);
            range_0x2B->Add(0x21, 0x3B);
            range_0x2B->Add(0x3D, 0x43);
            range_0x2B->Add(0x45, 0x77);

            ByteRangeGroupPtr range_0x30_6C(new ByteRangeGroup);
            range_0x30_6C->Add(0x21, 0x7E);

            ByteRangeGroupPtr range_0x6D(new ByteRangeGroup);
            range_0x6D->Add(0x21, 0x63);

            ByteRangeGroupPtr root_range(new ByteRangeGroup);
            root_range->Add(0x22, 0x22, range_0x22);
            root_range->Add(0x26, 0x26, range_0x26);
            root_range->Add(0x27, 0x27, range_0x27);
            root_range->Add(0x29, 0x29, range_0x29);
            root_range->Add(0x2A, 0x2A, range_0x2A);
            root_range->Add(0x2B, 0x2B, range_0x2B);
            root_range->Add(0x30, 0x6C, range_0x30_6C);
            root_range->Add(0x6D, 0x6D, range_0x6D);
           
            m_mapping = LoadMapping("dicom_test/data/string_converter/JIS0212.TXT", root_range);
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