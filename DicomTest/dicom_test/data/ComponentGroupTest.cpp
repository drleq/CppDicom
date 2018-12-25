#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/ComponentGroup.h"
#include "dicom_test/data/detail/constants.h"
#include "dicom/data/value_invalid.h"

using namespace dicom::data;

namespace {
    struct ComponentGroupTest {};
}

namespace dicom_test::data {

    TEST_CASE(ComponentGroupTest, Construction) {
        // ComponentGroup()
        ComponentGroup cg0;
        CHECK_EQUAL(cg0.Validity(), ValidityType::Valid);
        CHECK(cg0.Empty());
        CHECK_EQUAL(cg0.Value(), encoded_string());
        CHECK_EQUAL(cg0.FamilyName(), "");
        CHECK_EQUAL(cg0.GivenName(), "");
        CHECK_EQUAL(cg0.MiddleName(), "");
        CHECK_EQUAL(cg0.Prefix(), "");
        CHECK_EQUAL(cg0.Suffix(), "");

        // ComponentGroup(const encoded_string&)
        encoded_string value("Tables^Bobby^Drop^Mr^PhD");
        ComponentGroup cg1(value);
        CHECK_EQUAL(cg1.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg1.Empty());
        CHECK_EQUAL(cg1.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg1.FamilyName(), "Tables");
        CHECK_EQUAL(cg1.GivenName(), "Bobby");
        CHECK_EQUAL(cg1.MiddleName(), "Drop");
        CHECK_EQUAL(cg1.Prefix(), "Mr");
        CHECK_EQUAL(cg1.Suffix(), "PhD");

        // ComponentGroup(encoded_string&&)
        ComponentGroup cg2{ encoded_string(value) };
        CHECK_EQUAL(cg2.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg2.Empty());
        CHECK_EQUAL(cg2.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg2.FamilyName(), "Tables");
        CHECK_EQUAL(cg2.GivenName(), "Bobby");
        CHECK_EQUAL(cg2.MiddleName(), "Drop");
        CHECK_EQUAL(cg2.Prefix(), "Mr");
        CHECK_EQUAL(cg2.Suffix(), "PhD");

        // ComponentGroup(const std::array<encoded_string, 5>&)
        std::array<encoded_string, 5> values = {
            "Tables", "Bobby", "Drop", "Mr", "PhD"
        };
        ComponentGroup cg3(values);
        CHECK_EQUAL(cg3.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg3.Empty());
        CHECK_EQUAL(cg3.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg3.FamilyName(), "Tables");
        CHECK_EQUAL(cg3.GivenName(), "Bobby");
        CHECK_EQUAL(cg3.MiddleName(), "Drop");
        CHECK_EQUAL(cg3.Prefix(), "Mr");
        CHECK_EQUAL(cg3.Suffix(), "PhD");

        // ComponentGroup(std::initializer_list<encoded_string>)
        ComponentGroup cg4({ "Tables", "Bobby", "Drop", "Mr", "PhD" });
        CHECK_EQUAL(cg4.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg4.Empty());
        CHECK_EQUAL(cg4.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg4.FamilyName(), "Tables");
        CHECK_EQUAL(cg4.GivenName(), "Bobby");
        CHECK_EQUAL(cg4.MiddleName(), "Drop");
        CHECK_EQUAL(cg4.Prefix(), "Mr");
        CHECK_EQUAL(cg4.Suffix(), "PhD");

        // ComponentGroup(const ComponentGroup&)
        ComponentGroup cg5(cg4);
        CHECK_EQUAL(cg5.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg5.Empty());
        CHECK_EQUAL(cg5.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg5.FamilyName(), "Tables");
        CHECK_EQUAL(cg5.GivenName(), "Bobby");
        CHECK_EQUAL(cg5.MiddleName(), "Drop");
        CHECK_EQUAL(cg5.Prefix(), "Mr");
        CHECK_EQUAL(cg5.Suffix(), "PhD");

        // ComponentGroup(ComponentGroup&&)
        ComponentGroup cg6(std::move(cg5));
        CHECK_EQUAL(cg6.Validity(), ValidityType::Valid);
        CHECK_FALSE(cg6.Empty());
        CHECK_EQUAL(cg6.Value(), "Tables^Bobby^Drop^Mr^PhD");
        CHECK_EQUAL(cg6.FamilyName(), "Tables");
        CHECK_EQUAL(cg6.GivenName(), "Bobby");
        CHECK_EQUAL(cg6.MiddleName(), "Drop");
        CHECK_EQUAL(cg6.Prefix(), "Mr");
        CHECK_EQUAL(cg6.Suffix(), "PhD");
        CHECK_EQUAL(cg5.Validity(), ValidityType::Deinitialized);
        CHECK(cg5.Empty());
        CHECK_EQUAL(cg5.Value().Validity(), ValidityType::Deinitialized);
        CHECK_EQUAL(cg5.FamilyName(), "");
        CHECK_EQUAL(cg5.GivenName(), "");
        CHECK_EQUAL(cg5.MiddleName(), "");
        CHECK_EQUAL(cg5.Prefix(), "");
        CHECK_EQUAL(cg5.Suffix(), "");
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(ComponentGroupTest, Construction_InvalidChars) {
        ComponentGroup invalid1("Tables=Bobby");
        CHECK_EQUAL(invalid1.Validity(), ValidityType::Invalid);
        CHECK_FALSE(invalid1.Empty());
        CHECK_EQUAL(invalid1.Value(), "Tables=Bobby");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.FamilyName()));

        ComponentGroup invalid2("Tables\\Bobby");
        CHECK_EQUAL(invalid2.Validity(), ValidityType::Invalid);
        CHECK_FALSE(invalid2.Empty());
        CHECK_EQUAL(invalid2.Value(), "Tables\\Bobby");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.FamilyName()));
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(ComponentGroupTest, Empty) {
        ComponentGroup empty0;
        CHECK(empty0.Empty());

        ComponentGroup empty1("");
        CHECK(empty1.Empty());

        ComponentGroup empty2({});
        CHECK(empty2.Empty());
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(ComponentGroupTest, Equality_SingleValue) {
        ComponentGroup cg1("Valid1");
        ComponentGroup cg2("Valid2");

        CHECK(cg1 == cg1);
        CHECK(cg1 != cg2);
        CHECK(cg2 != cg1);

        CHECK(cg1 <  cg2);
        CHECK(cg1 <= cg2);
        CHECK(cg2 >  cg1);
        CHECK(cg2 >= cg1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ComponentGroupTest, Equality_MultipleValue) {
        ComponentGroup cg1("Identical\\Valid1");
        ComponentGroup cg2("Identical\\Valid2");

        CHECK(cg1 == cg1);
        CHECK(cg1 != cg2);
        CHECK(cg2 != cg1);

        CHECK(cg1 <  cg2);
        CHECK(cg1 <= cg2);
        CHECK(cg2 >  cg1);
        CHECK(cg2 >= cg1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ComponentGroupTest, Equality_DifferentMultiplicity) {
        ComponentGroup cg1("Identical");
        ComponentGroup cg2("Identical\\Valid");

        CHECK(cg1 == cg1);
        CHECK(cg1 != cg2);
        CHECK(cg2 != cg1);

        CHECK(cg1 <  cg2);
        CHECK(cg1 <= cg2);
        CHECK(cg2 >  cg1);
        CHECK(cg2 >= cg1);
    }

}