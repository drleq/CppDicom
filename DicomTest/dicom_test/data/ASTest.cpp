#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/AS.h"
#include "dicom_test/data/detail/constants.h"

using namespace CppUnitTestFramework;
using namespace dicom::data;

namespace {
    struct ASTest {};
}

namespace dicom_test::data {

    TEST_CASE(ASTest, Constructors) {
        // AS()
        AS as0;
        REQUIRE(as0.Value() == "");
        REQUIRE(as0.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as0.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as0.Units()));

        // AS(std::string&&)
        AS as1("030Y");
        REQUIRE(as1.Value() == "030Y");
        REQUIRE(as1.Validity() == ValidityType::Valid);
        REQUIRE(as1.Age() == 30);
        REQUIRE(as1.Units() == AS::Years);

        // AS(const std::string&)
        std::string value("030Y");
        AS as2(value);
        REQUIRE(as2.Value() == "030Y");
        REQUIRE(as2.Validity() == ValidityType::Valid);
        REQUIRE(as2.Age() == 30);
        REQUIRE(as2.Units() == AS::Years);

        // AS(int32_t, UnitType)
        AS as3(30, AS::Years);
        REQUIRE(as3.Value() == "030Y");
        REQUIRE(as3.Validity() == ValidityType::Valid);
        REQUIRE(as3.Age() == 30);
        REQUIRE(as3.Units() == AS::Years);

        // AS(const AS&)
        AS as4(as1);
        REQUIRE(as4.Value() == "030Y");
        REQUIRE(as4.Validity() == ValidityType::Valid);
        REQUIRE(as4.Age() == 30);
        REQUIRE(as4.Units() == AS::Years);
        REQUIRE(as1.Value() == "030Y");
        REQUIRE(as1.Validity() == ValidityType::Valid);
        REQUIRE(as1.Age() == 30);
        REQUIRE(as1.Units() == AS::Years);

        // AS(AS&&)
        AS as5(std::move(as2));
        REQUIRE(as5.Value() == "030Y");
        REQUIRE(as5.Validity() == ValidityType::Valid);
        REQUIRE(as5.Age() == 30);
        REQUIRE(as5.Units() == AS::Years);
        REQUIRE(as2.Value().empty());
        REQUIRE(as2.Validity() == ValidityType::Deinitialized);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as2.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as2.Units()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Construction_Valid) {
        AS as_days("012D");
        REQUIRE(as_days.Value() == "012D");
        REQUIRE(as_days.Validity() == ValidityType::Valid);
        REQUIRE(as_days.Age() == 12);
        REQUIRE(as_days.Units() == AS::Days);

        AS as_weeks("009W");
        REQUIRE(as_weeks.Value() == "009W");
        REQUIRE(as_weeks.Validity() == ValidityType::Valid);
        REQUIRE(as_weeks.Age() == 9);
        REQUIRE(as_weeks.Units() == AS::Weeks);

        AS as_months("123M");
        REQUIRE(as_months.Value() == "123M");
        REQUIRE(as_months.Validity() == ValidityType::Valid);
        REQUIRE(as_months.Age() == 123);
        REQUIRE(as_months.Units() == AS::Months);

        AS as_years("100Y");
        REQUIRE(as_years.Value() == "100Y");
        REQUIRE(as_years.Validity() == ValidityType::Valid);
        REQUIRE(as_years.Age() == 100);
        REQUIRE(as_years.Units() == AS::Years);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Construction_BadLength) {
        AS as_short("34Y");
        REQUIRE(as_short.Value() == "34Y");
        REQUIRE(as_short.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_short.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_short.Units()));

        AS as_long("1234M");
        REQUIRE(as_long.Value() == "1234M");
        REQUIRE(as_long.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_long.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_long.Units()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Construction_BadFormat) {
        AS as_units("123Z");
        REQUIRE(as_units.Value() == "123Z");
        REQUIRE(as_units.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_units.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_units.Units()));

        AS as_number("Y123");
        REQUIRE(as_number.Value() == "Y123");
        REQUIRE(as_number.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_number.Age()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(as_number.Units()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Equality_Age) {
        AS as1("003M");
        AS as2("004M");
        REQUIRE(as1 == &as1);
        REQUIRE(as1 != &as2);
        REQUIRE(as2 != &as1);

        REQUIRE(as1 <  &as2);
        REQUIRE(as1 <= &as2);
        REQUIRE(as2 >  &as1);
        REQUIRE(as2 >= &as1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Equality_Units) {
        // In ASCII 'M' < 'W' but in age terms Weeks < Months.
        AS as1("123W");
        AS as2("123M");
        REQUIRE(as1 == &as1);
        REQUIRE(as1 != &as2);
        REQUIRE(as2 != &as1);

        REQUIRE(as1 <  &as2);
        REQUIRE(as1 <= &as2);
        REQUIRE(as2 >  &as1);
        REQUIRE(as2 >= &as1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Empty) {
        AS as0;
        REQUIRE(as0.Empty());

        AS as1("123W");
        REQUIRE(!as1.Empty());

        AS as2("12Y");
        REQUIRE(!as2.Empty());

        AS as3("123Z");
        REQUIRE(!as3.Empty());

        AS as4("");
        REQUIRE(as4.Empty());

        AS as5("  ");
        REQUIRE(!as5.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ASTest, Copy) {
        AS as_orig("123M");
        std::unique_ptr<VR> vr_copy(as_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto as_copy = dynamic_cast<AS*>(vr_copy.get());
        REQUIRE(as_copy != nullptr);

        REQUIRE(as_orig.Value() == as_copy->Value());
        REQUIRE(as_orig.Age() == as_copy->Age());
        REQUIRE(as_orig.Units() == as_copy->Units());
        REQUIRE(as_orig == as_copy);
    }

}