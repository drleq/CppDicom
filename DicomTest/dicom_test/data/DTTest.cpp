#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/DT.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom::data;

namespace {
    struct DTTest {};
}

namespace dicom_test::data {

    TEST_CASE(DTTest, Constructors) {
        date_time datetime(DateTimePrecision::Days, 2012, 12, 21);
        time_offset offset_zero(0, 0);
        time_offset offset_3h30(3, 30);

        // DT()
        DT dt0;
        REQUIRE(dt0.Value() == "");
        REQUIRE(dt0.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt0.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt0.ParsedOffset()));

        // DT(const string_view&)
        DT dt1("20121221");
        REQUIRE(dt1.Value() == "20121221");
        REQUIRE(dt1.Validity() == ValidityType::Valid);
        REQUIRE(dt1.ParsedDateTime() == datetime);
        REQUIRE(dt1.ParsedOffset() == offset_zero);

        // DT(string&&)
        std::string value("20121221");
        DT dt2{ std::string(value) };
        REQUIRE(dt2.Value() == "20121221");
        REQUIRE(dt2.Validity() == ValidityType::Valid);
        REQUIRE(dt2.ParsedDateTime() == datetime);
        REQUIRE(dt2.ParsedOffset() == offset_zero);

        // DT(const ptime&)
        DT dt3(datetime);
        REQUIRE(dt3.Value() == "20121221");
        REQUIRE(dt3.Validity() == ValidityType::Valid);
        REQUIRE(dt3.ParsedDateTime() == datetime);
        REQUIRE(dt3.ParsedOffset() == offset_zero);

        // DT(const ptime&, const time_duration&)
        DT dt4(datetime, offset_3h30);
        REQUIRE(dt4.Value() == "20121221+0330");
        REQUIRE(dt4.Validity() == ValidityType::Valid);
        REQUIRE(dt4.ParsedDateTime() == datetime);
        REQUIRE(dt4.ParsedOffset() == offset_3h30);

        // DT(const DT&)
        DT dt5(dt1);
        REQUIRE(dt5.Value() == "20121221");
        REQUIRE(dt5.Validity() == ValidityType::Valid);
        REQUIRE(dt5.ParsedDateTime() == datetime);
        REQUIRE(dt5.ParsedOffset() == offset_zero);
        REQUIRE(dt1.Value() == "20121221");
        REQUIRE(dt1.Validity() == ValidityType::Valid);
        REQUIRE(dt1.ParsedDateTime() == datetime);
        REQUIRE(dt1.ParsedOffset() == offset_zero);

        // DT(DT&&)
        DT dt6(std::move(dt2));
        REQUIRE(dt6.Value() == "20121221");
        REQUIRE(dt6.Validity() == ValidityType::Valid);
        REQUIRE(dt6.ParsedDateTime() == datetime);
        REQUIRE(dt6.ParsedOffset() == offset_zero);
        REQUIRE(dt2.Value().empty());
        REQUIRE(dt2.Validity() == ValidityType::Deinitialized);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt2.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt2.ParsedOffset()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Construction_Valid) {
        DT dt1("20121221");
        REQUIRE(dt1.Value() == "20121221");
        REQUIRE(dt1.Validity() == ValidityType::Valid);
        REQUIRE(dt1.ParsedDateTime() == date_time(DateTimePrecision::Days, 2012, 12, 21));
        REQUIRE(dt1.ParsedOffset() == time_offset(0, 0, 0));

        DT dt2("20121221003000.123456");
        REQUIRE(dt2.Value() == "20121221003000.123456");
        REQUIRE(dt2.Validity() == ValidityType::Valid);
        REQUIRE(dt2.ParsedDateTime() == date_time(DateTimePrecision::Milliseconds, 2012, 12, 21, 0, 30, 0, 123456));
        REQUIRE(dt2.ParsedOffset() == time_offset(0, 0, 0));

        DT dt3("20121221-1234");
        REQUIRE(dt3.Value() == "20121221-1234");
        REQUIRE(dt3.Validity() == ValidityType::Valid);
        REQUIRE(dt3.ParsedDateTime() == date_time(DateTimePrecision::Days, 2012, 12, 21));
        REQUIRE(dt3.ParsedOffset() == time_offset(12, 34, true));

        DT dt4("20121221003000.123456+2345");
        REQUIRE(dt4.Value() == "20121221003000.123456+2345");
        REQUIRE(dt4.Validity() == ValidityType::Valid);
        REQUIRE(dt4.ParsedDateTime() == date_time(DateTimePrecision::Milliseconds, 2012, 12, 21, 0, 30, 0, 123456));
        REQUIRE(dt4.ParsedOffset() == time_offset(23, 45, 0));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Construction_Empty) {
        DT dt_default;
        REQUIRE(dt_default.Value().empty());
        REQUIRE(dt_default.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt_default.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt_default.ParsedOffset()));

        DT dt_empty("");
        REQUIRE(dt_empty.Value().empty());
        REQUIRE(dt_empty.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt_empty.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt_empty.ParsedOffset()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Construction_InvalidDate) {
        DT dt1("12345678");
        REQUIRE(dt1.Value() == "12345678");
        REQUIRE(dt1.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedOffset()));

        date_time not_a_date_time;
        DT dt2(not_a_date_time);
        REQUIRE(dt2.Value().empty());
        REQUIRE(dt2.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt2.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt2.ParsedOffset()));

        time_offset not_an_offset;
        DT dt3(date_time(DateTimePrecision::Days, 2012, 12, 21), not_an_offset);
        REQUIRE(dt3.Value().empty());
        REQUIRE(dt3.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt3.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt3.ParsedOffset()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Construction_InvalidOffset) {
        DT dt1("20121221+6789");
        REQUIRE(dt1.Value() == "20121221+6789");
        REQUIRE(dt1.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedOffset()));

        // The date is valid but the offset is not. This still results in a valid value.
        date_time datetime(DateTimePrecision::Days, 2012, 12, 21);
        time_offset not_an_offset;
        DT dt2(datetime, not_an_offset);
        REQUIRE(dt2.Value() == "");
        REQUIRE(dt2.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedDateTime()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(dt1.ParsedOffset()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Equality) {
        DT dt1("20121221");
        DT dt2("20121221000000.000001");
        REQUIRE(dt1 == &dt1);
        REQUIRE(dt1 != &dt2);
        REQUIRE(dt2 != &dt1);

        REQUIRE(dt1 <  &dt2);
        REQUIRE(dt1 <= &dt2);
        REQUIRE(dt2 >  &dt1);
        REQUIRE(dt2 >= &dt1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Empty) {
        DT dt1;
        REQUIRE(dt1.Empty());

        DT dt2("");
        REQUIRE(dt2.Empty());

        DT dt3("20121221");
        REQUIRE(!dt3.Empty());

        DT dt4("invalid");
        REQUIRE(!dt4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DTTest, Copy) {
        DT dt_orig(date_time(DateTimePrecision::Hours, 2012, 12, 21, 17));
        std::unique_ptr<VR> vr_copy(dt_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto dt_copy = dynamic_cast<DT*>(vr_copy.get());
        REQUIRE(dt_copy != nullptr);

        REQUIRE(dt_orig.Value() == dt_copy->Value());
        REQUIRE(dt_orig.ParsedDateTime() == dt_copy->ParsedDateTime());
        REQUIRE(dt_orig.ParsedOffset() == dt_copy->ParsedOffset());
        REQUIRE(dt_orig == dt_copy);
    }

}