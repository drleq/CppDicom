#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/LT.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct LTTest {};
}

namespace dicom_test::data {

    TEST_CASE(LTTest, Constructors) {
        // LT()
        LT lt0;
        REQUIRE(lt0.Validity() == ValidityType::Valid);
        REQUIRE(lt0.Value().Empty());

        // LT(encoded_string&&)
        LT lt1("Valid value");
        REQUIRE(lt1.Value() == "Valid value");
        REQUIRE(lt1.Validity() == ValidityType::Valid);

        // LT(const encoded_string&)
        encoded_string value("Valid value");
        LT lt2{ value };
        REQUIRE(lt2.Value() == "Valid value");
        REQUIRE(lt2.Validity() == ValidityType::Valid);

        // LT(const LT&)
        LT lt3(lt1);
        REQUIRE(lt3.Value() == "Valid value");
        REQUIRE(lt3.Validity() == ValidityType::Valid);
        REQUIRE(lt1.Value() == "Valid value");
        REQUIRE(lt1.Validity() == ValidityType::Valid);

        // LT(LT&&)
        LT lt5(std::move(lt2));
        REQUIRE(lt5.Value() == "Valid value");
        REQUIRE(lt5.Validity() == ValidityType::Valid);
        REQUIRE(lt2.Value().Empty());
        REQUIRE(lt2.Validity() == ValidityType::Deinitialized);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Construction_Valid) {
        LT lt_single("Valid value 1");
        REQUIRE(lt_single.Value() == "Valid value 1");
        REQUIRE(lt_single.Validity() == ValidityType::Valid);

        LT lt_multiple("Value 1\\2nd Value");
        REQUIRE(lt_multiple.Value() == "Value 1\\2nd Value");
        REQUIRE(lt_multiple.Validity() == ValidityType::Valid);

        LT lt_empty1("    ");
//        REQUIRE(lt_empty1.Value() == L"");
        REQUIRE(lt_empty1.Validity() == ValidityType::Valid);

        LT lt_empty2("");
        REQUIRE(lt_empty2.Value() == "");
        REQUIRE(lt_empty2.Validity() == ValidityType::Valid);

        LT lt_trim_right("  a  ");
//        REQUIRE(lt_trim_right.Value() == L"  a");
        REQUIRE(lt_trim_right.Validity() == ValidityType::Valid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Construction_Overlong) {
        std::string value(10241, 'a');
        LT lt{ encoded_string(value) };
        REQUIRE(lt.Validity() == ValidityType::Acceptable);
        REQUIRE(lt.Value().Parsed() == value);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Construction_InvalidCharacters) {
        std::string str("Invalid ");
        for (char c : detail::InvalidControlChars) {
            str[7] = c;
            LT lt{ encoded_string(str) };
            REQUIRE(lt.Validity() == ValidityType::Invalid);
            REQUIRE(lt.Value() == encoded_string(str));
        }
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Equality) {
        LT lt1("Valid 1");
        LT lt2("Valid 2");

        REQUIRE(lt1 == &lt1);
        REQUIRE(lt1 != &lt2);
        REQUIRE(lt2 != &lt1);

        REQUIRE(lt1 <  &lt2);
        REQUIRE(lt1 <= &lt2);
        REQUIRE(lt2 >  &lt1);
        REQUIRE(lt2 >= &lt1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Empty) {
        LT lt1;
        REQUIRE(lt1.Empty());

        LT lt2("Valid");
        REQUIRE(!lt2.Empty());

        LT lt3("");
        REQUIRE(lt3.Empty());

//        LT lt4(L"   ");
//        REQUIRE(lt4.Empty());

        LT lt5("\\");
        REQUIRE(!lt5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LTTest, Copy) {
        LT lt_orig("Valid value");
        std::unique_ptr<VR> vr_copy(lt_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto lt_copy = dynamic_cast<LT*>(vr_copy.get());
        REQUIRE(lt_copy != nullptr);

        REQUIRE(lt_orig.Value() == lt_copy->Value());
        REQUIRE(lt_orig == lt_copy);
    }

}