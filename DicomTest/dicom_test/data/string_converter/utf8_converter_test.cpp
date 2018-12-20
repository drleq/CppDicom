#include "dicomtest_pch.h"
#include "boost/test/unit_test.hpp"

#include "dicom/data/string_converter/utf8_converter.h"
using namespace dicom::data::string_converter;

namespace {
    void SetUTF16(uint32_t utf32, std::wstring& str) {
        if (utf32 < 0x10000) {
            str.resize(1);
            str[0] = wchar_t(utf32);
        } else {
            str.resize(2);
            utf32 -= 0x10000;
            str[0] = wchar_t((utf32 >> 10) + 0xD800);
            str[1] = wchar_t((utf32 & 0x3FF) + 0xDC00);
        }
    }

    //--------------------------------------------------------------------------------------------------------

    bool CheckUTF16(uint32_t utf32, const std::wstring& str) {
        if (utf32 < 0x10000) {
            return str.size() == 1 && str[0] == wchar_t(utf32);
        } else {
            utf32 -= 0x10000;
            auto first = wchar_t((utf32 >> 10) + 0xD800);
            auto second = wchar_t((utf32 & 0x3FF) + 0xDC00);
            return str.size() == 2 && str[0] == first && str[1] == second;
        }
    }
}

namespace dicom_test::data::string_converter {

    BOOST_AUTO_TEST_SUITE(utf8_converter_test)

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(ValidReflexiveConversion) {
        std::wstring source_utf16(2, L'\0');
        std::wstring returned_utf16;
        std::string utf8;

        for (uint32_t i = 0; i < 0xD800; ++i) {
            utf8.clear();
            returned_utf16.clear();

            SetUTF16(i, source_utf16);
            BOOST_REQUIRE(utf16_to_utf8(source_utf16, utf8));
            BOOST_REQUIRE(utf8_to_utf16(utf8, returned_utf16));
            BOOST_REQUIRE(source_utf16 == returned_utf16);
        }
        for (uint32_t i = 0xE000; i <= 0x10FFFF; ++i) {
            utf8.clear();
            returned_utf16.clear();

            SetUTF16(i, source_utf16);
            BOOST_REQUIRE(utf16_to_utf8(source_utf16, utf8));
            BOOST_REQUIRE(utf8_to_utf16(utf8, returned_utf16));
            BOOST_REQUIRE(source_utf16 == returned_utf16);
        }
    }

    //------------------------------------------------------------------------------------------------------------

    //BOOST_AUTO_TEST_CASE(InvalidToUTF16) {
        // This test is complicated to run and has limited usefulness so is ignored for now.
    //}

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_CASE(InvalidFromUTF16) {
        std::wstring source_utf16(2, L'\0');
        std::string utf8;

        for (uint32_t i = 0xD800; i <= 0xDFFF; ++i) {
            utf8.clear();

            SetUTF16(i, source_utf16);
            BOOST_REQUIRE(!utf16_to_utf8(source_utf16, utf8));
        }
    }

    //------------------------------------------------------------------------------------------------------------

    BOOST_AUTO_TEST_SUITE_END()

}