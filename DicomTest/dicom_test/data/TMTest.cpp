#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/TM.h"

using namespace dicom::data;
using dicom_time = dicom::data::time;

namespace {
    struct TMTest {};
}

namespace dicom_test::data {

    TEST_CASE(TMTest, Construction) {
        // TM()
        TM tm0;
        CHECK_EQUAL(tm0.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm0.ParsedCount(), 0u);
        CHECK_EQUAL(tm0.Value(), "");
        CHECK(tm0.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(tm0.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(tm0.At(0)));

        // TM(const char*)
        const char* value_str = "101520.123456";
        const dicom_time value_time{ TimePrecision::Milliseconds, 10, 15, 20, 123456 };
        TM tm1(value_str);
        CHECK_EQUAL(tm1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm1.ParsedCount(), 1u);
        CHECK_EQUAL(tm1.Value(), value_str);
        CHECK_EQUAL(tm1.Parsed()[0], value_time);
        CHECK_EQUAL(tm1.First(), value_time);
        CHECK_EQUAL(tm1.At(0), value_time);

        // TM(const std::string_view&)
        TM tm2{ std::string_view(value_str) };
        CHECK_EQUAL(tm2.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm2.ParsedCount(), 1u);
        CHECK_EQUAL(tm2.Value(), value_str);
        CHECK_EQUAL(tm2.Parsed()[0], value_time);
        CHECK_EQUAL(tm2.First(), value_time);
        CHECK_EQUAL(tm2.At(0), value_time);

        // TM(std::string&&)
        TM tm3{ std::string(value_str) };
        CHECK_EQUAL(tm3.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm3.ParsedCount(), 1u);
        CHECK_EQUAL(tm3.Value(), value_str);
        CHECK_EQUAL(tm3.Parsed()[0], value_time);
        CHECK_EQUAL(tm3.First(), value_time);
        CHECK_EQUAL(tm3.At(0), value_time);

        // TM(const std::vector<std::string>&)
        std::vector<std::string> values_str = { "10", "1015" };
        std::vector<dicom_time> values_time = {
            dicom_time{ TimePrecision::Hours, 10 },
            dicom_time{ TimePrecision::Minutes, 10, 15 }
        };
        TM tm4(values_str);
        CHECK_EQUAL(tm4.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm4.ParsedCount(), 2u);
        CHECK_EQUAL(tm4.Value(), "10\\1015");
        CHECK_EQUAL(tm4.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm4.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm4.First(), values_time[0]);
        CHECK_EQUAL(tm4.At(0), values_time[0]);

        // TM(std::initializer_list<std::string_view>)
        TM tm5({
            std::string_view(values_str[0]),
            std::string_view(values_str[1])
        });
        CHECK_EQUAL(tm5.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm5.ParsedCount(), 2u);
        CHECK_EQUAL(tm5.Value(), "10\\1015");
        CHECK_EQUAL(tm5.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm5.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm5.First(), values_time[0]);
        CHECK_EQUAL(tm5.At(0), values_time[0]);

        // TM(const time&)
        TM tm6(value_time);
        CHECK_EQUAL(tm6.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm6.ParsedCount(), 1u);
        CHECK_EQUAL(tm6.Value(), value_str);
        CHECK_EQUAL(tm6.Parsed()[0], value_time);
        CHECK_EQUAL(tm6.First(), value_time);
        CHECK_EQUAL(tm6.At(0), value_time);

        // TM(const std::vector<time>&)
        TM tm7(values_time);
        CHECK_EQUAL(tm7.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm7.ParsedCount(), 2u);
        CHECK_EQUAL(tm7.Value(), "10\\1015");
        CHECK_EQUAL(tm7.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm7.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm7.First(), values_time[0]);
        CHECK_EQUAL(tm7.At(0), values_time[0]);

        // TM(std::initializer_list<time>)
        TM tm8({ values_time[0], values_time[1] });
        CHECK_EQUAL(tm8.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm8.ParsedCount(), 2u);
        CHECK_EQUAL(tm8.Value(), "10\\1015");
        CHECK_EQUAL(tm8.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm8.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm8.First(), values_time[0]);
        CHECK_EQUAL(tm8.At(0), values_time[0]);

        // TM(const TM&)
        TM tm9(tm8);
        CHECK_EQUAL(tm9.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm9.ParsedCount(), 2u);
        CHECK_EQUAL(tm9.Value(), "10\\1015");
        CHECK_EQUAL(tm9.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm9.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm9.First(), values_time[0]);
        CHECK_EQUAL(tm9.At(0), values_time[0]);

        // TM(TM&&)
        TM tm10(std::move(tm9));
        CHECK_EQUAL(tm10.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm10.ParsedCount(), 2u);
        CHECK_EQUAL(tm10.Value(), "10\\1015");
        CHECK_EQUAL(tm10.Parsed()[0], values_time[0]);
        CHECK_EQUAL(tm10.Parsed()[1], values_time[1]);
        CHECK_EQUAL(tm10.First(), values_time[0]);
        CHECK_EQUAL(tm10.At(0), values_time[0]);
        CHECK_EQUAL(tm9.Validity(), ValidityType::Deinitialized);
        CHECK_EQUAL(tm9.ParsedCount(), 0u);
        CHECK_EQUAL(tm9.Value(), "");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(tm9.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(tm9.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(tm9.At(0)));
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Construction_ACR_NEMA) {
        const char* value_str = "10:15:20.123456";
        const dicom_time value_time{ TimePrecision::Milliseconds, 10, 15, 20, 123456 };
        TM tm1(value_str);
        CHECK_EQUAL(tm1.Validity(), ValidityType::Acceptable);
        CHECK_EQUAL(tm1.ParsedCount(), 1u);
        CHECK_EQUAL(tm1.Value(), value_str);
        CHECK_EQUAL(tm1.Parsed()[0], value_time);
        CHECK_EQUAL(tm1.First(), value_time);
        CHECK_EQUAL(tm1.At(0), value_time);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Construction_InvalidChars) {
        TM invalid1("10-15-20.123456");
        CHECK_EQUAL(invalid1.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(invalid1.ParsedCount(), 0u);
        CHECK_EQUAL(invalid1.Value(), "10-15-20.123456");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.At(0)));

        TM invalid2({ "101520.123456", "10-15-20.123456" });
        CHECK_EQUAL(invalid2.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(invalid2.ParsedCount(), 0u);
        CHECK_EQUAL(invalid2.Value(), "101520.123456\\10-15-20.123456");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.At(0)));
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Construction_InvalidTime) {
        dicom_time time_invalid{ TimePrecision::Hours, 25 };
        dicom_time time_valid{ TimePrecision::Hours, 23 };

        TM invalid1(time_invalid);
        CHECK_EQUAL(invalid1.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(invalid1.ParsedCount(), 0u);
        CHECK_EQUAL(invalid1.Value(), "25");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid1.At(0)));

        TM invalid2({ time_valid, time_invalid });
        CHECK_EQUAL(invalid2.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(invalid2.ParsedCount(), 0u);
        CHECK_EQUAL(invalid2.Value(), "23\\25");
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(invalid2.At(0)));
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Equality_SingleValue) {
        TM tm1("1");
        TM tm2("2");

        CHECK(tm1 == &tm1);
        CHECK(tm1 != &tm2);
        CHECK(tm2 != &tm1);

        CHECK(tm1 <  &tm2);
        CHECK(tm1 <= &tm2);
        CHECK(tm2 >  &tm1);
        CHECK(tm2 >= &tm1);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Equality_MultipleValue) {
        TM tm1("1\\1");
        TM tm2("1\\2");

        CHECK(tm1 == &tm1);
        CHECK(tm1 != &tm2);
        CHECK(tm2 != &tm1);

        CHECK(tm1 <= &tm2);
        CHECK(tm1 <  &tm2);
        CHECK(tm2 >  &tm1);
        CHECK(tm2 >= &tm1);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Equality_DifferentMultiplicity) {
        TM tm1("1");
        TM tm2("1\\2");

        CHECK(tm1 == &tm1);
        CHECK(tm1 != &tm2);
        CHECK(tm2 != &tm1);

        CHECK(tm1 <  &tm2);
        CHECK(tm1 <= &tm2);
        CHECK(tm2 >  &tm1);
        CHECK(tm2 >= &tm1);
    }
    
    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Empty) {
        TM empty0;
        CHECK(empty0.Empty());

        TM empty1("");
        CHECK(empty1.Empty());

        TM empty2(empty0);
        CHECK(empty2.Empty());

        TM empty3(std::move(empty0));
        CHECK(empty3.Empty());
        CHECK(empty0.Empty());
    }
        
    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(TMTest, Copy) {
        TM tm_orig("10\\101520.123456");
        std::unique_ptr<VR> vr_copy(tm_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto tm_copy = dynamic_cast<TM*>(vr_copy.get());
        REQUIRE(tm_copy != nullptr);

        REQUIRE(tm_orig.Value() == tm_copy->Value());
        REQUIRE(tm_orig == tm_copy);
    }

}