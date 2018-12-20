#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/DS.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct DSTest {};
}

namespace dicom_test::data {

    TEST_CASE(DSTest, Constructors) {
        // DS()
        DS ds0;
        REQUIRE(ds0.Value().empty());
        REQUIRE(ds0.Validity() == ValidityType::Valid);
        REQUIRE(ds0.ParsedCount() == 0);
        REQUIRE(ds0.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(ds0.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(ds0.At(0)));

        // DS(const string_view&)
        DS ds1("1.0");
        REQUIRE(ds1.Value() == "1.0");
        REQUIRE(ds1.Validity() == ValidityType::Valid);
        REQUIRE(ds1.ParsedCount() == 1);
        REQUIRE(ds1.Parsed().size() == 1);
        REQUIRE(ds1.Parsed()[0] == 1.0);
        REQUIRE(ds1.First() == 1.0);
        REQUIRE(ds1.At(0) == 1.0);
        
        // DS(string&&)
        std::string value("1.0");
        DS ds2{ std::string(value) };
        REQUIRE(ds2.Value() == "1.0");
        REQUIRE(ds2.Validity() == ValidityType::Valid);
        REQUIRE(ds2.ParsedCount() == 1);
        REQUIRE(ds2.Parsed().size() == 1);
        REQUIRE(ds2.Parsed()[0] == 1.0);
        REQUIRE(ds2.First() == 1.0);
        REQUIRE(ds2.At(0) == 1.0);

        // DS(double)
        DS ds3(-1.5);
        REQUIRE(ds3.Value() == "-1.5");
        REQUIRE(ds3.Validity() == ValidityType::Valid);
        REQUIRE(ds3.ParsedCount() == 1);
        REQUIRE(ds3.Parsed().size() == 1);
        REQUIRE(ds3.Parsed()[0] == -1.5);
        REQUIRE(ds3.First() == -1.5);
        REQUIRE(ds3.At(0) == -1.5);

        // DS(const vector<double>&)
        std::vector<double> values;
        values.push_back(1.0);
        values.push_back(2.5);
        DS ds4(values);
        REQUIRE(ds4.Value() == "1\\2.5");
        REQUIRE(ds4.Validity() == ValidityType::Valid);
        REQUIRE(ds4.ParsedCount() == 2);
        REQUIRE(ds4.Parsed().size() == 2);
        REQUIRE(ds4.Parsed()[0] == 1.0);
        REQUIRE(ds4.Parsed()[1] == 2.5);
        REQUIRE(ds4.First() == 1.0);
        REQUIRE(ds4.At(0) == 1.0);
        REQUIRE(ds4.At(1) == 2.5);
        
        // DS(const DS&)
        DS ds5(ds1);
        REQUIRE(ds5.Value() == "1.0");
        REQUIRE(ds5.Validity() == ValidityType::Valid);
        REQUIRE(ds5.ParsedCount() == 1);
        REQUIRE(ds5.Parsed().size() == 1);
        REQUIRE(ds5.Parsed()[0] == 1.0);
        REQUIRE(ds5.First() == 1.0);
        REQUIRE(ds5.At(0) == 1.0);
        REQUIRE(ds1.Value() == "1.0");
        REQUIRE(ds1.Validity() == ValidityType::Valid);
        REQUIRE(ds1.ParsedCount() == 1);
        REQUIRE(ds1.Parsed().size() == 1);
        REQUIRE(ds1.Parsed()[0] == 1.0);
        REQUIRE(ds1.First() == 1.0);
        REQUIRE(ds1.At(0) == 1.0);

        // DS(DS&&)
        DS ds6(std::move(ds2));
        REQUIRE(ds6.Value() == "1.0");
        REQUIRE(ds6.Validity() == ValidityType::Valid);
        REQUIRE(ds6.ParsedCount() == 1);
        REQUIRE(ds6.Parsed().size() == 1);
        REQUIRE(ds6.Parsed()[0] == 1.0);
        REQUIRE(ds6.First() == 1.0);
        REQUIRE(ds6.At(0) == 1.0);
        REQUIRE(ds2.Value().empty());
        REQUIRE(ds2.Validity() == ValidityType::Deinitialized);
        REQUIRE(ds2.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Construction_Valid) {
        DS ds_simple("1");
        REQUIRE(ds_simple.Value() == "1");
        REQUIRE(ds_simple.Validity() == ValidityType::Valid);
        REQUIRE(ds_simple.ParsedCount() == 1);
        REQUIRE(ds_simple.Parsed().size() == 1);
        REQUIRE(ds_simple.Parsed()[0] == 1.0);
        REQUIRE(ds_simple.First() == 1.0);
        REQUIRE(ds_simple.At(0) == 1.0);

        DS ds_complex("-0.2\\1\\+2.3");
        REQUIRE(ds_complex.Value() == "-0.2\\1\\+2.3");
        REQUIRE(ds_complex.Validity() == ValidityType::Valid);
        REQUIRE(ds_complex.ParsedCount() == 3);
        REQUIRE(ds_complex.Parsed().size() == 3);
        REQUIRE(ds_complex.Parsed()[0] == -0.2);
        REQUIRE(ds_complex.Parsed()[1] == 1);
        REQUIRE(ds_complex.Parsed()[2] == 2.3);
        REQUIRE(ds_complex.First() == -0.2);
        REQUIRE(ds_complex.At(0) == -0.2);
        REQUIRE(ds_complex.At(1) == 1);
        REQUIRE(ds_complex.At(2) == 2.3);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Construction_Empty) {
        DS ds_empty("");
        REQUIRE(ds_empty.Value().empty());
        REQUIRE(ds_empty.Validity() == ValidityType::Valid);
        REQUIRE(ds_empty.ParsedCount() == 0);
        REQUIRE(ds_empty.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(ds_empty.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(ds_empty.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Construction_Overlong) {
        DS ds_simple("1.0000000000000000");
        REQUIRE(ds_simple.Value() == "1.0000000000000000");
        REQUIRE(ds_simple.Validity() == ValidityType::Acceptable);
        REQUIRE(ds_simple.ParsedCount() == 1);
        REQUIRE(ds_simple.Parsed().size() == 1);
        REQUIRE(ds_simple.Parsed()[0] == 1.0);
        REQUIRE(ds_simple.First() == 1.0);
        REQUIRE(ds_simple.At(0) == 1.0);

        DS ds_complex("-0.2\\1.0000000000000000\\+2.3");
        REQUIRE(ds_complex.Value() == "-0.2\\1.0000000000000000\\+2.3");
        REQUIRE(ds_complex.Validity() == ValidityType::Acceptable);
        REQUIRE(ds_complex.ParsedCount() == 3);
        REQUIRE(ds_complex.Parsed().size() == 3);
        REQUIRE(ds_complex.Parsed()[0] == -0.2);
        REQUIRE(ds_complex.Parsed()[1] == 1);
        REQUIRE(ds_complex.Parsed()[2] == 2.3);
        REQUIRE(ds_complex.First() == -0.2);
        REQUIRE(ds_complex.At(0) == -0.2);
        REQUIRE(ds_complex.At(1) == 1);
        REQUIRE(ds_complex.At(2) == 2.3);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Construction_InvalidCharacters) {
        DS ds("1,0");
        REQUIRE(ds.Value() == "1,0");
        REQUIRE(ds.Validity() == ValidityType::Invalid);
        REQUIRE(ds.ParsedCount() == 0);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(ds.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Equality_SingleValue) {
        DS ds1(-2.0);
        DS ds2(1.0);

        REQUIRE(ds1 == &ds1);
        REQUIRE(ds1 != &ds2);
        REQUIRE(ds2 != &ds1);

        REQUIRE(ds1 <  &ds2);
        REQUIRE(ds1 <= &ds2);
        REQUIRE(ds2 >  &ds1);
        REQUIRE(ds2 >= &ds1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Equality_MultipleValue) {
        DS ds1("1.0\\-2.0");
        DS ds2("1.0\\1.0");

        REQUIRE(ds1 == &ds1);
        REQUIRE(ds1 != &ds2);
        REQUIRE(ds2 != &ds1);

        REQUIRE(ds1 <  &ds2);
        REQUIRE(ds1 <= &ds2);
        REQUIRE(ds2 >  &ds1);
        REQUIRE(ds2 >= &ds1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Equality_DifferentMultiplicity) {
        DS ds1("1.0");
        DS ds2("1.0\\1.0");

        REQUIRE(ds1 == &ds1);
        REQUIRE(ds1 != &ds2);
        REQUIRE(ds2 != &ds1);

        REQUIRE(ds1 <  &ds2);
        REQUIRE(ds1 <= &ds2);
        REQUIRE(ds2 >  &ds1);
        REQUIRE(ds2 >= &ds1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Empty) {
        DS ds1;
        REQUIRE(ds1.Empty());

        DS ds2("1.0");
        REQUIRE(!ds2.Empty());

        DS ds3("invalid");
        REQUIRE(!ds3.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(DSTest, Copy) {
        DS ds_orig("1.0\\-0.5");
        std::unique_ptr<VR> vr_copy(ds_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto ds_copy = dynamic_cast<DS*>(vr_copy.get());
        REQUIRE(ds_copy != nullptr);

        REQUIRE(ds_orig.Value() == ds_copy->Value());
        REQUIRE(ds_orig == ds_copy);
    }
 
}