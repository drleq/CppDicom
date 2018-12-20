#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/ST.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct STTest {};
}

namespace dicom_test::data {

    TEST_CASE(STTest, Constructors) {
        // ST()
        ST st0;
        REQUIRE(st0.Validity() == ValidityType::Valid);
        REQUIRE(st0.Value().Empty());

        // ST(encoded_string&&)
        ST st1("Valid value");
        REQUIRE(st1.Value() == "Valid value");
        REQUIRE(st1.Validity() == ValidityType::Valid);
        
        // ST(const encoded_string&)
        encoded_string value("Valid value");
        ST st2(value);
        REQUIRE(st2.Value() == "Valid value");
        REQUIRE(st2.Validity() == ValidityType::Valid);

        // ST(const ST&)
        ST st3(st1);
        REQUIRE(st3.Value() == "Valid value");
        REQUIRE(st3.Validity() == ValidityType::Valid);
        REQUIRE(st1.Value() == "Valid value");
        REQUIRE(st1.Validity() == ValidityType::Valid);

        // ST(ST&&)
        ST st5(std::move(st2));
        REQUIRE(st5.Value() == "Valid value");
        REQUIRE(st5.Validity() == ValidityType::Valid);
        REQUIRE(st2.Value().Empty());
        REQUIRE(st2.Validity() == ValidityType::Deinitialized);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Construction_Valid) {
        ST st_single("Valid value 1");
        REQUIRE(st_single.Value() == "Valid value 1");
        REQUIRE(st_single.Validity() == ValidityType::Valid);

        ST st_mustiple("Value 1\\2nd Value");
        REQUIRE(st_mustiple.Value() == "Value 1\\2nd Value");
        REQUIRE(st_mustiple.Validity() == ValidityType::Valid);

        ST st_empty1("    ");
//        REQUIRE(st_empty1.Value() == L"");
        REQUIRE(st_empty1.Validity() == ValidityType::Valid);

        ST st_empty2("");
        REQUIRE(st_empty2.Value() == "");
        REQUIRE(st_empty2.Validity() == ValidityType::Valid);

        ST st_trim_right("  a  ");
//        REQUIRE(st_trim_right.Value() == L"  a");
        REQUIRE(st_trim_right.Validity() == ValidityType::Valid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Construction_Overlong) {
        std::string value(1025, 'a');
        ST st{ encoded_string(value) };
        REQUIRE(st.Validity() == ValidityType::Acceptable);
        REQUIRE(st.Value().Parsed() == value);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Construction_InvalidCharacters) {
        std::string str("Invalid ");
        for (char c : detail::InvalidControlChars) {
            str[7] = c;
            ST st{ encoded_string(str) };
            REQUIRE(st.Value().Parsed() == str);
            REQUIRE(st.Validity() == ValidityType::Invalid);
        }
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Equality) {
        ST st1("Valid 1");
        ST st2("Valid 2");

        REQUIRE(st1 == &st1);
        REQUIRE(st1 != &st2);
        REQUIRE(st2 != &st1);

        REQUIRE(st1 <  &st2);
        REQUIRE(st1 <= &st2);
        REQUIRE(st2 >  &st1);
        REQUIRE(st2 >= &st1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Empty) {
        ST st1;
        REQUIRE(st1.Empty());

        ST st2("Valid");
        REQUIRE(!st2.Empty());

        ST st3("");
        REQUIRE(st3.Empty());

//        ST st4("   ");
//        REQUIRE(st4.Empty());

        ST st5("\\");
        REQUIRE(!st5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(STTest, Copy) {
        ST st_orig("Valid value");
        std::unique_ptr<VR> vr_copy(st_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto st_copy = dynamic_cast<ST*>(vr_copy.get());
        REQUIRE(st_copy != nullptr);

        REQUIRE(st_orig.Value() == st_copy->Value());
        REQUIRE(st_orig == st_copy);
    }

}