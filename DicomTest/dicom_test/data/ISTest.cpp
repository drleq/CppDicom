#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/IS.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct ISTest {};
}

namespace dicom_test::data {

    TEST_CASE(ISTest, Constructors) {
        // IS()
        IS is0;
        REQUIRE(is0.Validity() == ValidityType::Valid);
        REQUIRE(is0.Value().empty());
        REQUIRE(is0.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is0.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is0.At(0)));

        // IS(const string_view&)
        IS is1("1");
        REQUIRE(is1.Value() == "1");
        REQUIRE(is1.Validity() == ValidityType::Valid);
        REQUIRE(is1.Parsed().size() == 1);
        REQUIRE(is1.Parsed()[0] == 1);
        REQUIRE(is1.First() == 1);
        REQUIRE(is1.At(0) == 1);
        
        // IS(string&&)
        IS is2(std::string("1"));
        REQUIRE(is2.Value() == "1");
        REQUIRE(is2.Validity() == ValidityType::Valid);
        REQUIRE(is2.Parsed().size() == 1);
        REQUIRE(is2.Parsed()[0] == 1);
        REQUIRE(is2.First() == 1);
        REQUIRE(is2.At(0) == 1);

        // IS(const vector<int32_t>&)
        std::vector<int32_t> values;
        values.push_back(1);
        values.push_back(2);
        IS is3(values);
        REQUIRE(is3.Value() == "1\\2");
        REQUIRE(is3.Validity() == ValidityType::Valid);
        REQUIRE(is3.Parsed().size() == 2);
        REQUIRE(is3.Parsed()[0] == 1);
        REQUIRE(is3.Parsed()[1] == 2);
        REQUIRE(is3.First() == 1);
        REQUIRE(is3.At(0) == 1);
        REQUIRE(is3.At(1) == 2);

        // IS(initializer_list<int32_t>)
        IS is4({ 1, 2 });
        REQUIRE(is4.Value() == "1\\2");
        REQUIRE(is4.Validity() == ValidityType::Valid);
        REQUIRE(is4.Parsed().size() == 2);
        REQUIRE(is4.Parsed()[0] == 1);
        REQUIRE(is4.Parsed()[1] == 2);
        REQUIRE(is4.First() == 1);
        REQUIRE(is4.At(0) == 1);
        REQUIRE(is4.At(1) == 2);

        // IS(const IS&)
        IS is5(is1);
        REQUIRE(is5.Value() == "1");
        REQUIRE(is5.Validity() == ValidityType::Valid);
        REQUIRE(is5.Parsed().size() == 1);
        REQUIRE(is5.Parsed()[0] == 1);
        REQUIRE(is5.First() == 1);
        REQUIRE(is5.At(0) == 1);
        REQUIRE(is1.Value() == "1");
        REQUIRE(is1.Validity() == ValidityType::Valid);
        REQUIRE(is1.Parsed().size() == 1);
        REQUIRE(is1.Parsed()[0] == 1);
        REQUIRE(is1.First() == 1);
        REQUIRE(is1.At(0) == 1);

        // IS(IS&&)
        IS is6(std::move(is2));
        REQUIRE(is6.Value() == "1");
        REQUIRE(is6.Validity() == ValidityType::Valid);
        REQUIRE(is6.Parsed().size() == 1);
        REQUIRE(is6.Parsed()[0] == 1);
        REQUIRE(is6.First() == 1);
        REQUIRE(is6.At(0) == 1);
        REQUIRE(is2.Value().empty());
        REQUIRE(is2.Validity() == ValidityType::Deinitialized);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Construction_Valid) {
        IS is_single("5");
        REQUIRE(is_single.Value() == "5");
        REQUIRE(is_single.Validity() == ValidityType::Valid);
        REQUIRE(is_single.Parsed().size() == 1);
        REQUIRE(is_single.Parsed()[0] == 5);
        REQUIRE(is_single.First() == 5);

        IS is_multiple("5\\7");
        REQUIRE(is_multiple.Value() == "5\\7");
        REQUIRE(is_multiple.Validity() == ValidityType::Valid);
        REQUIRE(is_multiple.Parsed().size() == 2);
        REQUIRE(is_multiple.Parsed()[0] == 5);
        REQUIRE(is_multiple.Parsed()[1] == 7);
        REQUIRE(is_multiple.First() == 5);

        IS is_empty1("    ");
        REQUIRE(is_empty1.Value() == "");
        REQUIRE(is_empty1.Validity() == ValidityType::Valid);
        REQUIRE(is_empty1.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is_empty1.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is_empty1.At(0)));

        IS is_empty2("");
        REQUIRE(is_empty2.Value() == "");
        REQUIRE(is_empty2.Validity() == ValidityType::Valid);
        REQUIRE(is_empty2.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is_empty2.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(is_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Construction_ValueRange) {
        // A valid number that is too large for int32_t
        IS is_overflow("1234567890123456789");
        REQUIRE(is_overflow.Value() == "1234567890123456789");
        REQUIRE(is_overflow.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_overflow.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_overflow.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_overflow.At(0)));

        // Largest positive number that is valid
        IS is_just_ok1("2147483647");
        REQUIRE(is_just_ok1.Value() == "2147483647");
        REQUIRE(is_just_ok1.Validity() == ValidityType::Valid);
        REQUIRE(is_just_ok1.Parsed().size() == 1);
        REQUIRE(is_just_ok1.Parsed()[0] == 2147483647);
        REQUIRE(is_just_ok1.First() == 2147483647);

        // Smallest positive number that overflows
        IS is_just_overflow1("2147483648");
        REQUIRE(is_just_overflow1.Value() == "2147483648");
        REQUIRE(is_just_overflow1.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow1.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow1.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow1.At(0)));

        // Largest negative number that is valid
        IS is_just_ok2("-2147483648");
        REQUIRE(is_just_ok2.Value() == "-2147483648");
        REQUIRE(is_just_ok2.Validity() == ValidityType::Valid);
        REQUIRE(is_just_ok2.Parsed().size() == 1);
        REQUIRE(is_just_ok2.Parsed()[0] == -2147483648);
        REQUIRE(is_just_ok2.First() == -2147483648);

        // Smallest negative number that underflows
        IS is_just_overflow2("-2147483649");
        REQUIRE(is_just_overflow2.Value() == "-2147483649");
        REQUIRE(is_just_overflow2.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_just_overflow2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Construction_Invalid) {
        IS is_single("invalid");
        REQUIRE(is_single.Value() == "invalid");
        REQUIRE(is_single.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_single.Parsed()));

        IS is_multiple("1\\invalid");
        REQUIRE(is_multiple.Value() == "1\\invalid");
        REQUIRE(is_multiple.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Construction_InvalidCharacters) {
        IS is_single("1.1");
        REQUIRE(is_single.Value() == "1.1");
        REQUIRE(is_single.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_single.Parsed()));

        IS is_multiple("1\\1.1");
        REQUIRE(is_multiple.Value() == "1\\1.1");
        REQUIRE(is_multiple.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(is_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Equality_SingleValue) {
        IS is1("1");
        IS is2("2");

        REQUIRE(is1 == &is1);
        REQUIRE(is1 != &is2);
        REQUIRE(is2 != &is1);

        REQUIRE(is1 <  &is2);
        REQUIRE(is1 <= &is2);
        REQUIRE(is2 >  &is1);
        REQUIRE(is2 >= &is1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Equality_MultipleValue) {
        IS is1("1\\1");
        IS is2("1\\2");

        REQUIRE(is1 == &is1);
        REQUIRE(is1 != &is2);
        REQUIRE(is2 != &is1);

        REQUIRE(is1 <  &is2);
        REQUIRE(is1 <= &is2);
        REQUIRE(is2 >  &is1);
        REQUIRE(is2 >= &is1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Equality_DifferentMultiplicity) {
        IS is1("1");
        IS is2("1\\2");

        REQUIRE(is1 == &is1);
        REQUIRE(is1 != &is2);
        REQUIRE(is2 != &is1);

        REQUIRE(is1 <  &is2);
        REQUIRE(is1 <= &is2);
        REQUIRE(is2 >  &is1);
        REQUIRE(is2 >= &is1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Empty) {
        IS is1;
        REQUIRE(is1.Empty());

        IS is2("1");
        REQUIRE(!is2.Empty());

        IS is3("");
        REQUIRE(is3.Empty());

        IS is4("   ");
        REQUIRE(is4.Empty());

        IS is5("\\");
        REQUIRE(!is5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ISTest, Copy) {
        IS is_orig("1\\2");
        std::unique_ptr<VR> vr_copy(is_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto is_copy = dynamic_cast<IS*>(vr_copy.get());
        REQUIRE(is_copy != nullptr);

        REQUIRE(is_orig.Value() == is_copy->Value());
        REQUIRE(is_orig == is_copy);
    }

}