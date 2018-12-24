#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UC.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct UCTest {};
}

namespace dicom_test::data {

    TEST_CASE(UCTest, Constructors) {
        // UC()
        UC uc0;
        CHECK_EQUAL(uc0.Validity(), ValidityType::Valid);
        CHECK(uc0.Value().Empty());
        CHECK(uc0.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(uc0.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(uc0.At(0)));

        // UC(encoded_string&&)
        UC uc1("Valid value");
        CHECK_EQUAL(uc1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc1.Value().Parsed(), "Valid value");
        CHECK_EQUAL(uc1.Parsed().size(), 1u);
        CHECK_EQUAL(uc1.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc1.First(), "Valid value");
        CHECK_EQUAL(uc1.At(0), "Valid value");

        // UC(const encoded_string&)
        encoded_string value("Valid value");
        UC uc2(value);
        CHECK_EQUAL(uc2.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc2.Value().Parsed(), "Valid value");
        CHECK_EQUAL(uc2.Parsed().size(), 1u);
        CHECK_EQUAL(uc2.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc2.First(), "Valid value");
        CHECK_EQUAL(uc2.At(0), "Valid value");

        // UC(const vector<encoded_string>&)
        std::vector<encoded_string> values;
        values.push_back(value);
        values.push_back("Another");
        UC uc3(values);
        CHECK_EQUAL(uc3.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc3.Value().Parsed(), "Valid value\\Another");
        CHECK_EQUAL(uc3.Parsed().size(), 2u);
        CHECK_EQUAL(uc3.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc3.Parsed()[1], "Another");
        CHECK_EQUAL(uc3.First(), "Valid value");
        CHECK_EQUAL(uc3.At(0), "Valid value");
        CHECK_EQUAL(uc3.At(1), "Another");

        // UC(initializer_list<encoded_string>)
        UC uc4({ value, "Another" });
        CHECK_EQUAL(uc4.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc4.Value().Parsed(), "Valid value\\Another");
        CHECK_EQUAL(uc4.Parsed().size(), 2u);
        CHECK_EQUAL(uc4.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc4.Parsed()[1], "Another");
        CHECK_EQUAL(uc4.First(), "Valid value");
        CHECK_EQUAL(uc4.At(0), "Valid value");
        CHECK_EQUAL(uc4.At(1), "Another");

        // UC(const UC&)
        UC uc5(uc1);
        CHECK_EQUAL(uc5.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc5.Value().Parsed(), "Valid value");
        CHECK_EQUAL(uc5.Parsed().size(), 1u);
        CHECK_EQUAL(uc5.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc5.First(), "Valid value");
        CHECK_EQUAL(uc5.At(0), "Valid value");
        CHECK_EQUAL(uc1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc1.Value().Parsed(), "Valid value");
        CHECK_EQUAL(uc1.Parsed().size(), 1u);
        CHECK_EQUAL(uc1.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc1.First(), "Valid value");
        CHECK_EQUAL(uc1.At(0), "Valid value");

        // UC(UC&&)
        UC uc6(std::move(uc2));
        CHECK_EQUAL(uc6.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc6.Value(), "Valid value");
        CHECK_EQUAL(uc6.Parsed().size(), 1u);
        CHECK_EQUAL(uc6.Parsed()[0], "Valid value");
        CHECK_EQUAL(uc6.First(), "Valid value");
        CHECK_EQUAL(uc6.At(0), "Valid value");
        CHECK_EQUAL(uc2.Validity(), ValidityType::Deinitialized);
        CHECK(uc2.Value().Empty());
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc2.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Construction_Valid) {
        UC uc_single("Valid value 1");
        CHECK_EQUAL(uc_single.Value(), "Valid value 1");
        CHECK_EQUAL(uc_single.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc_single.Parsed().size(), 1u);
        CHECK_EQUAL(uc_single.Parsed()[0], "Valid value 1");
        CHECK_EQUAL(uc_single.First(), "Valid value 1");

        UC uc_multiple("Value 1\\2nd Value");
        CHECK_EQUAL(uc_multiple.Value(), "Value 1\\2nd Value");
        CHECK_EQUAL(uc_multiple.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc_multiple.Parsed().size(), 2u);
        CHECK_EQUAL(uc_multiple.Parsed()[0], "Value 1");
        CHECK_EQUAL(uc_multiple.Parsed()[1], "2nd Value");
        CHECK_EQUAL(uc_multiple.First(), "Value 1");

        UC uc_empty1("    ");
        CHECK_EQUAL(uc_empty1.Value(), "    ");
        CHECK_EQUAL(uc_empty1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(uc_empty1.Parsed().size(), 1u);
        CHECK_EQUAL(uc_empty1.Parsed()[0], "");
        CHECK_EQUAL(uc_empty1.First(), "");

        UC uc_empty2("");
        CHECK_EQUAL(uc_empty2.Value(), "");
        CHECK_EQUAL(uc_empty2.Validity(), ValidityType::Valid);
        CHECK(uc_empty2.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(uc_empty2.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(uc_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Construction_InvalidCharacters) {
        UC uc_newline("\x0A");
        CHECK_EQUAL(uc_newline.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(uc_newline.Value(), encoded_string("\x0A"));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc_newline.Parsed()));

        UC uc_newpage("\x0C");
        CHECK_EQUAL(uc_newpage.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(uc_newpage.Value(), encoded_string("\x0C"));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc_newpage.Parsed()));

        UC uc_carriagereturn("\x0D");
        CHECK_EQUAL(uc_carriagereturn.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(uc_carriagereturn.Value(), encoded_string("\x0D"));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc_carriagereturn.Parsed()));

        UC uc_multiple("Valid\\\x0A");
        CHECK_EQUAL(uc_multiple.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(uc_multiple.Value(), encoded_string("Valid\\\x0A"));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(uc_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Equality_SingleValue) {
        UC uc1("Valid 1");
        UC uc2("Valid 2");

        CHECK(uc1 == &uc1);
        CHECK(uc1 != &uc2);
        CHECK(uc2 != &uc1);

        CHECK(uc1 <  &uc2);
        CHECK(uc1 <= &uc2);
        CHECK(uc2 >  &uc1);
        CHECK(uc2 >= &uc1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Equality_MultipleValue) {
        UC uc1("Identical\\Valid 1");
        UC uc2("Identical\\Valid 2");

        CHECK(uc1 == &uc1);
        CHECK(uc1 != &uc2);
        CHECK(uc2 != &uc1);

        CHECK(uc1 <  &uc2);
        CHECK(uc1 <= &uc2);
        CHECK(uc2 >  &uc1);
        CHECK(uc2 >= &uc1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Equality_DifferentMultiplicity) {
        UC uc1("Identical");
        UC uc2("Identical\\Valid");

        CHECK(uc1 == &uc1);
        CHECK(uc1 != &uc2);
        CHECK(uc2 != &uc1);

        CHECK(uc1 <  &uc2);
        CHECK(uc1 <= &uc2);
        CHECK(uc2 >  &uc1);
        CHECK(uc2 >= &uc1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Empty) {
        UC uc1;
        CHECK(uc1.Empty());

        UC uc2("Valid");
        CHECK(!uc2.Empty());

        UC uc3("");
        CHECK(uc3.Empty());

        UC uc4("   ");
        CHECK(!uc4.Empty());

        UC uc5("\\");
        CHECK(!uc5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UCTest, Copy) {
        UC uc_orig("Valid\\Values");
        std::unique_ptr<VR> vr_copy(uc_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto uc_copy = dynamic_cast<UC*>(vr_copy.get());
        CHECK(uc_copy != nullptr);

        CHECK(uc_orig.Value() == uc_copy->Value());
        CHECK(uc_orig == uc_copy);
    }
 
}