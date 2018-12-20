#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/AE.h"
#include "dicom_test/data/detail/constants.h"

using namespace CppUnitTestFramework;
using namespace dicom::data;

namespace {
    struct AETest {};
}

namespace dicom_test::data {

    TEST_CASE(AETest, Constructors) {
        AE ae0;
        REQUIRE_EQUAL(ae0.Value(), "");
        REQUIRE_EQUAL(ae0.Validity(), ValidityType::Invalid);

        // AE(std::string&&)
        AE ae1("ValidAE 123");
        REQUIRE_EQUAL(ae1.Value(), "ValidAE 123");
        REQUIRE_EQUAL(ae1.Validity(), ValidityType::Valid);

        // AE(const std::string&)
        std::string value("ValidAE 123");
        AE ae2(value);
        REQUIRE_EQUAL(ae2.Value(), "ValidAE 123");
        REQUIRE_EQUAL(ae2.Validity(), ValidityType::Valid);

        // AE(const AE&)
        AE ae3(ae1);
        REQUIRE_EQUAL(ae3.Value(), "ValidAE 123");
        REQUIRE_EQUAL(ae3.Validity(), ValidityType::Valid);
        REQUIRE_EQUAL(ae1.Value(), "ValidAE 123");
        REQUIRE_EQUAL(ae1.Validity(), ValidityType::Valid);

        // AE(AE&&)
        AE ae4(std::move(ae2));
        REQUIRE_EQUAL(ae4.Value(), "ValidAE 123");
        REQUIRE_EQUAL(ae4.Validity(), ValidityType::Valid);
        REQUIRE(ae2.Value().empty());
        REQUIRE_EQUAL(ae2.Validity(), ValidityType::Deinitialized);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_ValidOverlong) {
        AE ae("This is longer than 16 characters");
        REQUIRE_EQUAL(ae.Value(), "This is longer than 16 characters");
        REQUIRE_EQUAL(ae.Validity(), ValidityType::Acceptable);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_Empty) {
        AE ae("");
        REQUIRE_EQUAL(ae.Value(), "");
        REQUIRE_EQUAL(ae.Validity(), ValidityType::Invalid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_EmptyWhiteSpace) {
        AE ae("    ");
        REQUIRE_EQUAL(ae.Value(), "");
        REQUIRE_EQUAL(ae.Validity(), ValidityType::Invalid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_DefaultRepertoire) {
        std::string str("Valid AE");
        for (char c : detail::ValidControlChars) {
            str[5] = c;
            AE ae(str);
            REQUIRE_EQUAL(ae.Value(), str);
            REQUIRE_EQUAL(ae.Validity(), ValidityType::Valid);
        }
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_NonDefaultRepertoire) {
        std::string str("Invalid AE");
        for (char c : detail::InvalidControlChars) {
            str[7] = c;
            AE ae(str);
            REQUIRE_EQUAL(ae.Value(), str);
            REQUIRE_EQUAL(ae.Validity(), ValidityType::Invalid);
        }
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Construction_Multiplicity) {
        AE ae("Invalid\\AE");
        REQUIRE_EQUAL(ae.Value(), "Invalid\\AE");
        REQUIRE_EQUAL(ae.Validity(), ValidityType::Invalid);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Equality) {
        AE ae1("ValidAE1");
        AE ae2("ValidAE2");
        REQUIRE(ae1 == &ae1);
        REQUIRE(ae1 != &ae2);
        REQUIRE(ae2 != &ae1);

        REQUIRE(ae1 <  &ae2);
        REQUIRE(ae1 <= &ae2);
        REQUIRE(ae2 >  &ae1);
        REQUIRE(ae2 >= &ae1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Empty) {
        AE ae0;
        REQUIRE(ae0.Empty());

        AE ae1("Valid AE");
        REQUIRE_FALSE(ae1.Empty());

        AE ae2("Invalid\\AE");
        REQUIRE_FALSE(ae2.Empty());

        AE ae3("");
        REQUIRE(ae3.Empty());

        AE ae4("    ");
        REQUIRE(ae4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(AETest, Copy) {
        AE ae_orig("ValidAE");
        std::unique_ptr<VR> vr_copy(ae_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto ae_copy = dynamic_cast<AE*>(vr_copy.get());
        REQUIRE(ae_copy != nullptr);

        REQUIRE_EQUAL(ae_orig.Value(), ae_copy->Value());
        REQUIRE(ae_orig == ae_copy);
    }

}