#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/encoded_string.h"

using namespace dicom::data;

namespace {
    struct encoded_string_test {};
}

namespace dicom_test::data {

    TEST_CASE(encoded_string_test, Constructors) {
        // encoded_string()
        encoded_string es0;
        REQUIRE(es0.Validity() == ValidityType::Valid);
        REQUIRE(es0.Empty());
        REQUIRE(es0.Parsed().empty());
        REQUIRE(es0.Encoding() == StringEncodingType::ISO_IEC_646);

        // encoded_string(const string_view&)
        encoded_string es1("");
        REQUIRE(es1.Validity() == ValidityType::Valid);
        REQUIRE(es1.Empty());
        REQUIRE(es1.Parsed().empty());
        REQUIRE(es1.Encoding() == StringEncodingType::UTF8);

        // encoded_string(const string_view&, StringEncodingType)
        encoded_string es2("", StringEncodingType::GB_18030);
        REQUIRE(es2.Validity() == ValidityType::Valid);
        REQUIRE(es2.Empty());
        REQUIRE(es2.Parsed().empty());
        REQUIRE(es2.Encoding() == StringEncodingType::GB_18030);

        // encoded_string(string&&)
        encoded_string es3(std::string(""));
        REQUIRE(es3.Validity() == ValidityType::Valid);
        REQUIRE(es3.Empty());
        REQUIRE(es3.Parsed().empty());
        REQUIRE(es3.Encoding() == StringEncodingType::UTF8);

        // encoded_string(string&&, StringEncodingType)
        encoded_string es4(std::string(""), StringEncodingType::GB_18030);
        REQUIRE(es4.Validity() == ValidityType::Valid);
        REQUIRE(es4.Empty());
        REQUIRE(es4.Parsed().empty());
        REQUIRE(es4.Encoding() == StringEncodingType::GB_18030);

        // encoded_string(const encoded_string&)
        encoded_string es5(es0);
        REQUIRE(es5.Validity() == es0.Validity());
        REQUIRE(es5.Empty() == es0.Empty());
        REQUIRE(es5.Parsed() == es0.Parsed());
        REQUIRE(es5.Encoding() == es0.Encoding());

        // encoded_string(encoded_string&&)
        encoded_string tmp(es2);
        encoded_string es6(std::move(tmp));
        REQUIRE(es6.Validity() == es2.Validity());
        REQUIRE(es6.Empty() == es2.Empty());
        REQUIRE(es6.Parsed() == es2.Parsed());
        REQUIRE(es6.Encoding() == es2.Encoding());
    }

}