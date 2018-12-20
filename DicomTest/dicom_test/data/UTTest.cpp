#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UT.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct UTTest {};
}

namespace dicom_test::data {

    TEST_CASE(UTTest, Constructors) {
        // UT()
        UT ut0;
        REQUIRE(ut0.Validity() == ValidityType::Valid);
        REQUIRE(ut0.Value().Empty());

        // UT(encoded_string&&)
        UT ut1("Valid value");
        REQUIRE(ut1.Value() == "Valid value");
        REQUIRE(ut1.Validity() == ValidityType::Valid);
        
        // UT(const encoded_string&)
        encoded_string value("Valid value");
        UT ut2(value);
        REQUIRE(ut2.Value() == "Valid value");
        REQUIRE(ut2.Validity() == ValidityType::Valid);

        // UT(const UT&)
        UT ut3(ut1);
        REQUIRE(ut3.Value() == "Valid value");
        REQUIRE(ut3.Validity() == ValidityType::Valid);
        REQUIRE(ut1.Value() == "Valid value");
        REQUIRE(ut1.Validity() == ValidityType::Valid);

        // UT(UT&&)
        UT ut5(std::move(ut2));
        REQUIRE(ut5.Value() == "Valid value");
        REQUIRE(ut5.Validity() == ValidityType::Valid);
        REQUIRE(ut2.Value().Empty());
        REQUIRE(ut2.Validity() == ValidityType::Deinitialized);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UTTest, Construction_Valid) {
        UT ut_single("Valid value 1");
        REQUIRE(ut_single.Value() == "Valid value 1");
        REQUIRE(ut_single.Validity() == ValidityType::Valid);

        UT ut_multiple("Value 1\\2nd Value");
        REQUIRE(ut_multiple.Value() == "Value 1\\2nd Value");
        REQUIRE(ut_multiple.Validity() == ValidityType::Valid);

        UT ut_empty1("    ");
//        REQUIRE(ut_empty1.Value() == "");
        REQUIRE(ut_empty1.Validity() == ValidityType::Valid);

        UT ut_empty2("");
        REQUIRE(ut_empty2.Value() == "");
        REQUIRE(ut_empty2.Validity() == ValidityType::Valid);

        UT ut_trim_right("  a  ");
//        REQUIRE(ut_trim_right.Value() == "  a");
        REQUIRE(ut_trim_right.Validity() == ValidityType::Valid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UTTest, Construction_InvalidCharacters) {
        std::string str("Invalid ");
        for (char c : detail::InvalidControlChars) {
            str[7] = c;
            UT ut{ encoded_string(str) };
            REQUIRE(ut.Value() == encoded_string(str));
            REQUIRE(ut.Validity() == ValidityType::Invalid);
        }
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UTTest, Equality) {
        UT ut1("Valid 1");
        UT ut2("Valid 2");

        REQUIRE(ut1 == &ut1);
        REQUIRE(ut1 != &ut2);
        REQUIRE(ut2 != &ut1);

        REQUIRE(ut1 <  &ut2);
        REQUIRE(ut1 <= &ut2);
        REQUIRE(ut2 >  &ut1);
        REQUIRE(ut2 >= &ut1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UTTest, Empty) {
        UT ut1;
        REQUIRE(ut1.Empty());

        UT ut2("Valid");
        REQUIRE(!ut2.Empty());

        UT ut3("");
        REQUIRE(ut3.Empty());

//        UT ut4("   ");
//        REQUIRE(ut4.Empty());

        UT ut5("\\");
        REQUIRE(!ut5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UTTest, Copy) {
        UT ut_orig("Valid value");
        std::unique_ptr<VR> vr_copy(ut_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto ut_copy = dynamic_cast<UT*>(vr_copy.get());
        REQUIRE(ut_copy != nullptr);

        REQUIRE(ut_orig.Value() == ut_copy->Value());
        REQUIRE(ut_orig == ut_copy);
    }

}