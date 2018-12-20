#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/LO.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct LOTest {};
}

namespace dicom_test::data {

    TEST_CASE(LOTest, Constructors) {
        // LO()
        LO lo0;
        REQUIRE(lo0.Validity() == ValidityType::Valid);
        REQUIRE(lo0.Value().Empty());
        REQUIRE(lo0.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(lo0.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(lo0.At(0)));

        // LO(encoded_string&&)
        LO lo1("Valid value");
        REQUIRE(lo1.Validity() == ValidityType::Valid);
        REQUIRE(lo1.Value().Parsed() == "Valid value");
        REQUIRE(lo1.Parsed().size() == 1);
        REQUIRE(lo1.Parsed()[0] == "Valid value");
        REQUIRE(lo1.First() == "Valid value");
        REQUIRE(lo1.At(0) == "Valid value");
        
        // LO(const encoded_string&)
        encoded_string value("Valid value");
        LO lo2(value);
        REQUIRE(lo2.Validity() == ValidityType::Valid);
        REQUIRE(lo2.Value().Parsed() == "Valid value");
        REQUIRE(lo2.Parsed().size() == 1);
        REQUIRE(lo2.Parsed()[0] == "Valid value");
        REQUIRE(lo2.First() == "Valid value");
        REQUIRE(lo2.At(0) == "Valid value");

        // LO(const vector<encoded_string>&)
        std::vector<encoded_string> values;
        values.push_back(value);
        values.push_back("Another");
        LO lo3(values);
        REQUIRE(lo3.Validity() == ValidityType::Valid);
        REQUIRE(lo3.Value().Parsed() == "Valid value\\Another");
        REQUIRE(lo3.Parsed().size() == 2);
        REQUIRE(lo3.Parsed()[0] == "Valid value");
        REQUIRE(lo3.Parsed()[1] == "Another");
        REQUIRE(lo3.First() == "Valid value");
        REQUIRE(lo3.At(0) == "Valid value");
        REQUIRE(lo3.At(1) == "Another");

        // LO(initializer_list<encoded_string>)
        LO lo4({ value, "Another" });
        REQUIRE(lo4.Validity() == ValidityType::Valid);
        REQUIRE(lo4.Value().Parsed() == "Valid value\\Another");
        REQUIRE(lo4.Parsed().size() == 2);
        REQUIRE(lo4.Parsed()[0] == "Valid value");
        REQUIRE(lo4.Parsed()[1] == "Another");
        REQUIRE(lo4.First() == "Valid value");
        REQUIRE(lo4.At(0) == "Valid value");
        REQUIRE(lo4.At(1) == "Another");

        // LO(const LO&)
        LO lo5(lo1);
        REQUIRE(lo5.Validity() == ValidityType::Valid);
        REQUIRE(lo5.Value().Parsed() == "Valid value");
        REQUIRE(lo5.Parsed().size() == 1);
        REQUIRE(lo5.Parsed()[0] == "Valid value");
        REQUIRE(lo5.First() == "Valid value");
        REQUIRE(lo5.At(0) == "Valid value");
        REQUIRE(lo1.Validity() == ValidityType::Valid);
        REQUIRE(lo1.Value().Parsed() == "Valid value");
        REQUIRE(lo1.Parsed().size() == 1);
        REQUIRE(lo1.Parsed()[0] == "Valid value");
        REQUIRE(lo1.First() == "Valid value");
        REQUIRE(lo1.At(0) == "Valid value");

        // LO(LO&&)
        LO lo6(std::move(lo2));
        REQUIRE(lo6.Validity() == ValidityType::Valid);
        REQUIRE(lo6.Value().Parsed() == "Valid value");
        REQUIRE(lo6.Parsed().size() == 1);
        REQUIRE(lo6.Parsed()[0] == "Valid value");
        REQUIRE(lo6.First() == "Valid value");
        REQUIRE(lo6.At(0) == "Valid value");
        REQUIRE(lo2.Validity() == ValidityType::Deinitialized);
        REQUIRE(lo2.Value().Empty());
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Construction_Valid) {
        LO lo_single("Valid value 1");
        REQUIRE(lo_single.Validity() == ValidityType::Valid);
        REQUIRE(lo_single.Value().Parsed() == "Valid value 1");
        REQUIRE(lo_single.Parsed().size() == 1);
        REQUIRE(lo_single.Parsed()[0] == "Valid value 1");
        REQUIRE(lo_single.First() == "Valid value 1");

        LO lo_multiple("Value 1\\2nd Value");
        REQUIRE(lo_multiple.Validity() == ValidityType::Valid);
        REQUIRE(lo_multiple.Value().Parsed() == "Value 1\\2nd Value");
        REQUIRE(lo_multiple.Parsed().size() == 2);
        REQUIRE(lo_multiple.Parsed()[0] == "Value 1");
        REQUIRE(lo_multiple.Parsed()[1] == "2nd Value");
        REQUIRE(lo_multiple.First() == "Value 1");

        LO lo_empty1("    ");
        REQUIRE(lo_empty1.Validity() == ValidityType::Valid);
        REQUIRE(lo_empty1.Value().Parsed() == "    ");
//        REQUIRE(lo_empty1.Parsed().empty());
//        REQUIRE_THROW(lo_empty1.First(), value_empty_error);
//        REQUIRE_THROW(lo_empty1.At(0), value_empty_error);

        LO lo_empty2("");
        REQUIRE(lo_empty2.Validity() == ValidityType::Valid);
        REQUIRE(lo_empty2.Value().Parsed() == "");
        REQUIRE(lo_empty2.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(lo_empty2.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(lo_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Construction_Overlong) {
        encoded_string value("This value is longer than 64 characters in length. Do you want to count them?");
        LO lo(value);
        REQUIRE(lo.Validity() == ValidityType::Acceptable);
        REQUIRE(lo.Value().Value() == value.Value());
        REQUIRE(lo.Parsed().size() == 1);
        REQUIRE(lo.Parsed()[0] == value.Parsed());
        REQUIRE(lo.First() == value.Parsed());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Construction_InvalidCharacters) {
        LO lo_newline("\x0A");
        REQUIRE(lo_newline.Validity() == ValidityType::Invalid);
        REQUIRE(lo_newline.Value() == encoded_string("\x0A"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo_newline.Parsed()));

        LO lo_newpage("\x0C");
        REQUIRE(lo_newpage.Validity() == ValidityType::Invalid);
        REQUIRE(lo_newpage.Value() == encoded_string("\x0C"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo_newpage.Parsed()));

        LO lo_carriagereturn("\x0D");
        REQUIRE(lo_carriagereturn.Validity() == ValidityType::Invalid);
        REQUIRE(lo_carriagereturn.Value() == encoded_string("\x0D"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo_carriagereturn.Parsed()));

        LO lo_multiple("Valid\\\x0A");
        REQUIRE(lo_multiple.Validity() == ValidityType::Invalid);
        REQUIRE(lo_multiple.Value() == encoded_string("Valid\\\x0A"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(lo_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Equality_SingleValue) {
        LO lo1("Valid 1");
        LO lo2("Valid 2");

        REQUIRE(lo1 == &lo1);
        REQUIRE(lo1 != &lo2);
        REQUIRE(lo2 != &lo1);

        REQUIRE(lo1 <  &lo2);
        REQUIRE(lo1 <= &lo2);
        REQUIRE(lo2 >  &lo1);
        REQUIRE(lo2 >= &lo1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Equality_MultipleValue) {
        LO lo1("Identical\\Valid 1");
        LO lo2("Identical\\Valid 2");

        REQUIRE(lo1 == &lo1);
        REQUIRE(lo1 != &lo2);
        REQUIRE(lo2 != &lo1);

        REQUIRE(lo1 <  &lo2);
        REQUIRE(lo1 <= &lo2);
        REQUIRE(lo2 >  &lo1);
        REQUIRE(lo2 >= &lo1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Equality_DifferentMultiplicity) {
        LO lo1("Identical");
        LO lo2("Identical\\Valid");

        REQUIRE(lo1 == &lo1);
        REQUIRE(lo1 != &lo2);
        REQUIRE(lo2 != &lo1);

        REQUIRE(lo1 <  &lo2);
        REQUIRE(lo1 <= &lo2);
        REQUIRE(lo2 >  &lo1);
        REQUIRE(lo2 >= &lo1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Empty) {
        LO lo1;
        REQUIRE(lo1.Empty());

        LO lo2("Valid");
        REQUIRE(!lo2.Empty());

        LO lo3("");
        REQUIRE(lo3.Empty());

//        LO lo4(L"   ");
//        REQUIRE(lo4.Empty());

        LO lo5("\\");
        REQUIRE(!lo5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(LOTest, Copy) {
        LO lo_orig("Valid\\Values");
        std::unique_ptr<VR> vr_copy(lo_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto lo_copy = dynamic_cast<LO*>(vr_copy.get());
        REQUIRE(lo_copy != nullptr);

        REQUIRE(lo_orig.Value() == lo_copy->Value());
        REQUIRE(lo_orig == lo_copy);
    }

}