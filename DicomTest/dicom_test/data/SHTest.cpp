#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/SH.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct SHTest {};
}

namespace dicom_test::data {

    TEST_CASE(SHTest, Constructors) {
        // SH()
        SH sh0;
        REQUIRE(sh0.Validity() == ValidityType::Valid);
        REQUIRE(sh0.Value().Empty());
        REQUIRE(sh0.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh0.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh0.At(0)));

        // SH(encoded_string&&)
        SH sh1("Valid value");
        REQUIRE(sh1.Validity() == ValidityType::Valid);
        REQUIRE(sh1.Value().Parsed() == "Valid value");
        REQUIRE(sh1.Parsed().size() == 1);
        REQUIRE(sh1.Parsed()[0] == "Valid value");
        REQUIRE(sh1.First() == "Valid value");
        REQUIRE(sh1.At(0) == "Valid value");
        
        // SH(const encoded_string&)
        encoded_string value("Valid value");
        SH sh2(value);
        REQUIRE(sh2.Validity() == ValidityType::Valid);
        REQUIRE(sh2.Value().Parsed() == "Valid value");
        REQUIRE(sh2.Parsed().size() == 1);
        REQUIRE(sh2.Parsed()[0] == "Valid value");
        REQUIRE(sh2.First() == "Valid value");
        REQUIRE(sh2.At(0) == "Valid value");

        // SH(const vector<encoded_string>&)
        std::vector<encoded_string> values;
        values.push_back(value);
        values.push_back("Another");
        SH sh3(values);
        REQUIRE(sh3.Validity() == ValidityType::Valid);
        REQUIRE(sh3.Value().Parsed() == "Valid value\\Another");
        REQUIRE(sh3.Parsed().size() == 2);
        REQUIRE(sh3.Parsed()[0] == "Valid value");
        REQUIRE(sh3.Parsed()[1] == "Another");
        REQUIRE(sh3.First() == "Valid value");
        REQUIRE(sh3.At(0) == "Valid value");
        REQUIRE(sh3.At(1) == "Another");

        // SH(initializer_list<encoded_string>)
        SH sh4({ value, "Another" });
        REQUIRE(sh4.Validity() == ValidityType::Valid);
        REQUIRE(sh4.Value().Parsed() == "Valid value\\Another");
        REQUIRE(sh4.Parsed().size() == 2);
        REQUIRE(sh4.Parsed()[0] == "Valid value");
        REQUIRE(sh4.Parsed()[1] == "Another");
        REQUIRE(sh4.First() == "Valid value");
        REQUIRE(sh4.At(0) == "Valid value");
        REQUIRE(sh4.At(1) == "Another");

        // SH(const SH&)
        SH sh5(sh1);
        REQUIRE(sh5.Validity() == ValidityType::Valid);
        REQUIRE(sh5.Value().Parsed() == "Valid value");
        REQUIRE(sh5.Parsed().size() == 1);
        REQUIRE(sh5.Parsed()[0] == "Valid value");
        REQUIRE(sh5.First() == "Valid value");
        REQUIRE(sh5.At(0) == "Valid value");
        REQUIRE(sh1.Validity() == ValidityType::Valid);
        REQUIRE(sh1.Value().Parsed() == "Valid value");
        REQUIRE(sh1.Parsed().size() == 1);
        REQUIRE(sh1.Parsed()[0] == "Valid value");
        REQUIRE(sh1.First() == "Valid value");
        REQUIRE(sh1.At(0) == "Valid value");

        // SH(SH&&)
        SH sh6(std::move(sh2));
        REQUIRE(sh6.Validity() == ValidityType::Valid);
        REQUIRE(sh6.Value() == "Valid value");
        REQUIRE(sh6.Parsed().size() == 1);
        REQUIRE(sh6.Parsed()[0] == "Valid value");
        REQUIRE(sh6.First() == "Valid value");
        REQUIRE(sh6.At(0) == "Valid value");
        REQUIRE(sh2.Validity() == ValidityType::Deinitialized);
        REQUIRE(sh2.Value().Empty());
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Construction_Valid) {
        SH sh_single("Valid value 1");
        REQUIRE(sh_single.Value() == "Valid value 1");
        REQUIRE(sh_single.Validity() == ValidityType::Valid);
        REQUIRE(sh_single.Parsed().size() == 1);
        REQUIRE(sh_single.Parsed()[0] == "Valid value 1");
        REQUIRE(sh_single.First() == "Valid value 1");

        SH sh_multiple("Value 1\\2nd Value");
        REQUIRE(sh_multiple.Value() == "Value 1\\2nd Value");
        REQUIRE(sh_multiple.Validity() == ValidityType::Valid);
        REQUIRE(sh_multiple.Parsed().size() == 2);
        REQUIRE(sh_multiple.Parsed()[0] == "Value 1");
        REQUIRE(sh_multiple.Parsed()[1] == "2nd Value");
        REQUIRE(sh_multiple.First() == "Value 1");

        SH sh_empty1("    ");
//        REQUIRE(sh_empty1.Value() == "");
        REQUIRE(sh_empty1.Validity() == ValidityType::Valid);
//        REQUIRE(sh_empty1.Parsed().empty());
//        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh_empty1.First()));
//        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh_empty1.At(0)));

        SH sh_empty2("");
        REQUIRE(sh_empty2.Value() == "");
        REQUIRE(sh_empty2.Validity() == ValidityType::Valid);
        REQUIRE(sh_empty2.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh_empty2.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(sh_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Construction_Overlong) {
        std::string value("This value is longer than 16 characters.");
        SH sh{ encoded_string(value) };
        REQUIRE(sh.Validity() == ValidityType::Acceptable);
        REQUIRE(sh.Value().Parsed() == value);
        REQUIRE(sh.Parsed().size() == 1);
        REQUIRE(sh.Parsed()[0] == value);
        REQUIRE(sh.First() == value);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Construction_InvalidCharacters) {
        SH sh_newline("\x0A");
        REQUIRE(sh_newline.Validity() == ValidityType::Invalid);
        REQUIRE(sh_newline.Value() == encoded_string("\x0A"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh_newline.Parsed()));

        SH sh_newpage("\x0C");
        REQUIRE(sh_newpage.Validity() == ValidityType::Invalid);
        REQUIRE(sh_newpage.Value() == encoded_string("\x0C"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh_newpage.Parsed()));

        SH sh_carriagereturn("\x0D");
        REQUIRE(sh_carriagereturn.Validity() == ValidityType::Invalid);
        REQUIRE(sh_carriagereturn.Value() == encoded_string("\x0D"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh_carriagereturn.Parsed()));

        SH sh_multiple("Valid\\\x0A");
        REQUIRE(sh_multiple.Validity() == ValidityType::Invalid);
        REQUIRE(sh_multiple.Value() == encoded_string("Valid\\\x0A"));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(sh_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Equality_SingleValue) {
        SH sh1("Valid 1");
        SH sh2("Valid 2");

        REQUIRE(sh1 == &sh1);
        REQUIRE(sh1 != &sh2);
        REQUIRE(sh2 != &sh1);

        REQUIRE(sh1 <  &sh2);
        REQUIRE(sh1 <= &sh2);
        REQUIRE(sh2 >  &sh1);
        REQUIRE(sh2 >= &sh1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Equality_MultipleValue) {
        SH sh1("Identical\\Valid 1");
        SH sh2("Identical\\Valid 2");

        REQUIRE(sh1 == &sh1);
        REQUIRE(sh1 != &sh2);
        REQUIRE(sh2 != &sh1);

        REQUIRE(sh1 <  &sh2);
        REQUIRE(sh1 <= &sh2);
        REQUIRE(sh2 >  &sh1);
        REQUIRE(sh2 >= &sh1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Equality_DifferentMultiplicity) {
        SH sh1("Identical");
        SH sh2("Identical\\Valid");

        REQUIRE(sh1 == &sh1);
        REQUIRE(sh1 != &sh2);
        REQUIRE(sh2 != &sh1);

        REQUIRE(sh1 <  &sh2);
        REQUIRE(sh1 <= &sh2);
        REQUIRE(sh2 >  &sh1);
        REQUIRE(sh2 >= &sh1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Empty) {
        SH sh1;
        REQUIRE(sh1.Empty());

        SH sh2("Valid");
        REQUIRE(!sh2.Empty());

        SH sh3("");
        REQUIRE(sh3.Empty());

//        SH sh4("   ");
//        REQUIRE(sh4.Empty());

        SH sh5("\\");
        REQUIRE(!sh5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SHTest, Copy) {
        SH sh_orig("Valid\\Values");
        std::unique_ptr<VR> vr_copy(sh_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto sh_copy = dynamic_cast<SH*>(vr_copy.get());
        REQUIRE(sh_copy != nullptr);

        REQUIRE(sh_orig.Value() == sh_copy->Value());
        REQUIRE(sh_orig == sh_copy);
    }
 
}