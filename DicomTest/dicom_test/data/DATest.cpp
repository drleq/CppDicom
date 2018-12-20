#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/DA.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom::data;

namespace {
    struct DATest {};
}

namespace dicom_test::data {

    TEST_CASE(DATest, Constructors) {
        // DA()
        DA da0;
        REQUIRE(da0.Value() == "");
        REQUIRE(da0.Validity() == ValidityType::Invalid);
        REQUIRE(da0.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da0.Parsed()));

        // DA(const string_view&)
        DA da1("20121221");
        REQUIRE(da1.Value() == "20121221");
        REQUIRE(da1.Validity() == ValidityType::Valid);
        REQUIRE(da1.ParsedCount() == 1);
        REQUIRE(da1.Parsed()[0] == date(DatePrecision::Days, 2012, 12, 21));
        REQUIRE(da1.First() == date(2012, 12, 21));
        REQUIRE(da1.At(0) == date(2012, 12, 21));

        // DA(string&&)
        std::string value("20121221");
        DA da2{ std::string(value) };
        REQUIRE(da2.Value() == "20121221");
        REQUIRE(da2.Validity() == ValidityType::Valid);
        REQUIRE(da2.ParsedCount() == 1);
        REQUIRE(da2.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da2.First() == date(2012, 12, 21));
        REQUIRE(da2.At(0) == date(2012, 12, 21));

        // DA(const vector<string_view>&)
        std::vector<std::string_view> string_values = { "20121221", "21021221" };
        DA da3{ string_values };
        REQUIRE(da3.Value() == "20121221\\21021221");
        REQUIRE(da3.Validity() == ValidityType::Valid);
        REQUIRE(da3.ParsedCount() == 2);
        REQUIRE(da3.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da3.Parsed()[1] == date(2102, 12, 21));
        REQUIRE(da3.First() == date(2012, 12, 21));
        REQUIRE(da3.At(0) == date(2012, 12, 21));
        REQUIRE(da3.At(1) == date(2102, 12, 21));

        // DA(initializer_list<string_view>)
        DA da4({ "20121221", "21021221" });
        REQUIRE(da4.Value() == "20121221\\21021221");
        REQUIRE(da4.Validity() == ValidityType::Valid);
        REQUIRE(da4.ParsedCount() == 2);
        REQUIRE(da4.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da4.Parsed()[1] == date(2102, 12, 21));
        REQUIRE(da4.First() == date(2012, 12, 21));
        REQUIRE(da4.At(0) == date(2012, 12, 21));
        REQUIRE(da4.At(1) == date(2102, 12, 21));

        // DA(const date&)
        DA da5(date(2012, 12, 21));
        REQUIRE(da5.Value() == "20121221");
        REQUIRE(da5.Validity() == ValidityType::Valid);
        REQUIRE(da5.ParsedCount() == 1);
        REQUIRE(da5.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da5.First() == date(2012, 12, 21));
        REQUIRE(da5.At(0) == date(2012, 12, 21));

        // DA(const vector<date>&)
        std::vector<date> date_values = { date(2012, 12, 21), date(2102, 12, 21) };
        DA da6(date_values);
        REQUIRE(da6.Value() == "20121221\\21021221");
        REQUIRE(da6.Validity() == ValidityType::Valid);
        REQUIRE(da6.ParsedCount() == 2);
        REQUIRE(da6.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da6.Parsed()[1] == date(2102, 12, 21));
        REQUIRE(da6.First() == date(2012, 12, 21));
        REQUIRE(da6.At(0) == date(2012, 12, 21));
        REQUIRE(da6.At(1) == date(2102, 12, 21));

        // DA(initializer_list<date>)
        DA da7({ date(2012, 12, 21), date(2102, 12, 21) });
        REQUIRE(da7.Value() == "20121221\\21021221");
        REQUIRE(da7.Validity() == ValidityType::Valid);
        REQUIRE(da7.ParsedCount() == 2);
        REQUIRE(da7.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da7.Parsed()[1] == date(2102, 12, 21));
        REQUIRE(da7.First() == date(2012, 12, 21));
        REQUIRE(da7.At(0) == date(2012, 12, 21));
        REQUIRE(da7.At(1) == date(2102, 12, 21));

        // DA(const DA&)
        DA da8(da1);
        REQUIRE(da8.Value() == "20121221");
        REQUIRE(da8.Validity() == ValidityType::Valid);
        REQUIRE(da8.ParsedCount() == 1);
        REQUIRE(da8.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da8.First() == date(2012, 12, 21));
        REQUIRE(da8.At(0) == date(2012, 12, 21));
        REQUIRE(da1.Value() == "20121221");
        REQUIRE(da1.Validity() == ValidityType::Valid);
        REQUIRE(da1.ParsedCount() == 1);
        REQUIRE(da1.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da1.First() == date(2012, 12, 21));
        REQUIRE(da1.At(0) == date(2012, 12, 21));

        // DA(DA&&)
        DA da9(std::move(da2));
        REQUIRE(da9.Value() == "20121221");
        REQUIRE(da9.Validity() == ValidityType::Valid);
        REQUIRE(da9.ParsedCount() == 1);
        REQUIRE(da9.Parsed()[0] == date(2012, 12, 21));
        REQUIRE(da9.First() == date(2012, 12, 21));
        REQUIRE(da9.At(0) == date(2012, 12, 21));
        REQUIRE(da2.Value().empty());
        REQUIRE(da2.Validity() == ValidityType::Deinitialized);
        REQUIRE(da2.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da2.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Construction_Valid) {
        DA da_dicom("20121221");
        REQUIRE(da_dicom.Value() == "20121221");
        REQUIRE(da_dicom.Validity() == ValidityType::Valid);
        REQUIRE(da_dicom.First() == date(2012, 12, 21));

        DA da_acrnema("2012.12.21");
        REQUIRE(da_acrnema.Value() == "2012.12.21");
        REQUIRE(da_acrnema.Validity() == ValidityType::Acceptable);
        REQUIRE(da_acrnema.First() == date(2012, 12, 21));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Construction_Empty) {
        DA da_default;
        REQUIRE(da_default.Value().empty());
        REQUIRE(da_default.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da_default.Parsed()));

        DA da_empty("");
        REQUIRE(da_empty.Value().empty());
        REQUIRE(da_empty.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da_empty.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Construction_InvalidDate) {
        DA da1("12345678");
        REQUIRE(da1.Value() == "12345678");
        REQUIRE(da1.Validity() == ValidityType::Invalid);
        REQUIRE(da1.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da1.Parsed()));

        date not_a_date;
        DA da2(not_a_date);
        REQUIRE(da2.Value().empty());
        REQUIRE(da2.Validity() == ValidityType::Invalid);
        REQUIRE(da2.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da2.Parsed()));

        DA da3({ "20121221", "12345678" });
        REQUIRE(da3.Value() == "20121221\\12345678");
        REQUIRE(da3.Validity() == ValidityType::Invalid);
        REQUIRE(da3.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(da3.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Equality) {
        DA da1("2012.12.21");
        DA da2(date(2012, 12, 22));
        REQUIRE(da1 == &da1);
        REQUIRE(da1 != &da2);
        REQUIRE(da2 != &da1);

        REQUIRE(da1 <  &da2);
        REQUIRE(da1 <= &da2);
        REQUIRE(da2 >  &da1);
        REQUIRE(da2 >= &da1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Empty) {
        DA da1;
        REQUIRE(da1.Empty());

        DA da2("20121221");
        REQUIRE(!da2.Empty());

        DA da3("NotADate");
        REQUIRE(!da3.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DATest, Copy) {
        DA da_orig(date(2012, 12, 22));
        std::unique_ptr<VR> vr_copy(da_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto da_copy = dynamic_cast<DA*>(vr_copy.get());
        REQUIRE(da_copy != nullptr);

        REQUIRE(da_orig.Value() == da_copy->Value());
        REQUIRE(da_orig.Parsed() == da_copy->Parsed());
        REQUIRE(da_orig == da_copy);
    }

}