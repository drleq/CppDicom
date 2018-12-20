#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/CS.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct CSTest {};
}

namespace dicom_test::data {

    TEST_CASE(CSTest, Constructors) {
        // CS()
        CS cs0;
        REQUIRE(cs0.Validity() == ValidityType::Valid);
        REQUIRE(cs0.Value().empty());
        REQUIRE(cs0.ParsedCount() == 0);
        REQUIRE(cs0.Parsed().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs0.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs0.At(0)));

        // CS(const string_view&)
        CS cs1("VALID_VALUE");
        REQUIRE(cs1.Value() == "VALID_VALUE");
        REQUIRE(cs1.Validity() == ValidityType::Valid);
        REQUIRE(cs1.ParsedCount() == 1);
        REQUIRE(cs1.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs1.First() == "VALID_VALUE");
        REQUIRE(cs1.At(0) == "VALID_VALUE");
        
        // CS(string&&)
        std::string value("VALID_VALUE");
        CS cs2{ std::string(value) };
        REQUIRE(cs2.Value() == "VALID_VALUE");
        REQUIRE(cs2.Validity() == ValidityType::Valid);
        REQUIRE(cs2.ParsedCount() == 1);
        REQUIRE(cs2.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs2.First() == "VALID_VALUE");
        REQUIRE(cs2.At(0) == "VALID_VALUE");

        // CS(const vector<string_view>&)
        std::vector<std::string_view> values;
        values.push_back(value);
        values.push_back("ANOTHER");
        CS cs3(values);
        REQUIRE(cs3.Value() == "VALID_VALUE\\ANOTHER");
        REQUIRE(cs3.Validity() == ValidityType::Valid);
        REQUIRE(cs3.ParsedCount() == 2);
        REQUIRE(cs3.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs3.Parsed()[1] == "ANOTHER");
        REQUIRE(cs3.First() == "VALID_VALUE");
        REQUIRE(cs3.At(0) == "VALID_VALUE");
        REQUIRE(cs3.At(1) == "ANOTHER");

        // CS(initializer_list<string_view>)
        CS cs4({ value, "ANOTHER" });
        REQUIRE(cs4.Value() == "VALID_VALUE\\ANOTHER");
        REQUIRE(cs4.Validity() == ValidityType::Valid);
        REQUIRE(cs4.ParsedCount() == 2);
        REQUIRE(cs4.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs4.Parsed()[1] == "ANOTHER");
        REQUIRE(cs4.First() == "VALID_VALUE");
        REQUIRE(cs4.At(0) == "VALID_VALUE");
        REQUIRE(cs4.At(1) == "ANOTHER");

        // CS(const CS&)
        CS cs5(cs1);
        REQUIRE(cs5.Value() == "VALID_VALUE");
        REQUIRE(cs5.Validity() == ValidityType::Valid);
        REQUIRE(cs5.ParsedCount() == 1);
        REQUIRE(cs5.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs5.First() == "VALID_VALUE");
        REQUIRE(cs5.At(0) == "VALID_VALUE");
        REQUIRE(cs1.Value() == "VALID_VALUE");
        REQUIRE(cs1.Validity() == ValidityType::Valid);
        REQUIRE(cs1.ParsedCount() == 1);
        REQUIRE(cs1.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs1.First() == "VALID_VALUE");
        REQUIRE(cs1.At(0) == "VALID_VALUE");

        // CS(CS&&)
        CS cs6(std::move(cs2));
        REQUIRE(cs6.Value() == "VALID_VALUE");
        REQUIRE(cs6.Validity() == ValidityType::Valid);
        REQUIRE(cs6.ParsedCount() == 1);
        REQUIRE(cs6.Parsed()[0] == "VALID_VALUE");
        REQUIRE(cs6.First() == "VALID_VALUE");
        REQUIRE(cs6.At(0) == "VALID_VALUE");
        REQUIRE(cs2.Value().empty());
        REQUIRE(cs2.Validity() == ValidityType::Deinitialized);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs2.Parsed()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs2.First()));
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Construction_Valid) {
        CS cs_single("VALID_VALUE 1");
        REQUIRE(cs_single.Value() == "VALID_VALUE 1");
        REQUIRE(cs_single.Validity() == ValidityType::Valid);
        REQUIRE(cs_single.ParsedCount() == 1);
        REQUIRE(cs_single.Parsed()[0] == "VALID_VALUE 1");
        REQUIRE(cs_single.First() == "VALID_VALUE 1");

        CS cs_multiple("VALUE_1\\2ND VALUE");
        REQUIRE(cs_multiple.Value() == "VALUE_1\\2ND VALUE");
        REQUIRE(cs_multiple.Validity() == ValidityType::Valid);
        REQUIRE(cs_multiple.ParsedCount() == 2);
        REQUIRE(cs_multiple.Parsed()[0] == "VALUE_1");
        REQUIRE(cs_multiple.Parsed()[1] == "2ND VALUE");
        REQUIRE(cs_multiple.First() == "VALUE_1");

        CS cs_empty1("    ");
        REQUIRE(cs_empty1.Value() == "");
        REQUIRE(cs_empty1.Validity() == ValidityType::Valid);
        REQUIRE(cs_empty1.ParsedCount() == 0);
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs_empty1.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs_empty1.At(0)));

        CS cs_empty2("");
        REQUIRE(cs_empty2.Value() == "");
        REQUIRE(cs_empty2.Validity() == ValidityType::Valid);
        REQUIRE(cs_empty2.ParsedCount() == 0);
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs_empty2.First()));
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(cs_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Construction_Overlong) {
        CS cs("THIS VALUE IS LONGER THAN 16 CHARACTERS");
        REQUIRE(cs.Value() == "THIS VALUE IS LONGER THAN 16 CHARACTERS");
        REQUIRE(cs.Validity() == ValidityType::Acceptable);
        REQUIRE(cs.ParsedCount() == 1);
        REQUIRE(cs.Parsed()[0] == "THIS VALUE IS LONGER THAN 16 CHARACTERS");
        REQUIRE(cs.First() == "THIS VALUE IS LONGER THAN 16 CHARACTERS");
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Construction_BadCase) {
        CS cs_single("invalid");
        REQUIRE(cs_single.Value() == "invalid");
        REQUIRE(cs_single.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs_single.Parsed()));

        CS cs_multiple("VALID\\invalid");
        REQUIRE(cs_multiple.Value() == "VALID\\invalid");
        REQUIRE(cs_multiple.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Construction_InvalidCharacters) {
        CS cs_single("INVALID-TEXT");
        REQUIRE(cs_single.Value() == "INVALID-TEXT");
        REQUIRE(cs_single.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs_single.Parsed()));

        CS cs_multiple("VALID_TEXT\\INVALID-TEXT");
        REQUIRE(cs_multiple.Value() == "VALID_TEXT\\INVALID-TEXT");
        REQUIRE(cs_multiple.Validity() == ValidityType::Invalid);
        REQUIRE_THROW(value_invalid_error, UNUSED_RETURN(cs_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Equality_SingleValue) {
        CS cs1("VALID 1");
        CS cs2("VALID 2");

        REQUIRE(cs1 == &cs1);
        REQUIRE(cs1 != &cs2);
        REQUIRE(cs2 != &cs1);

        REQUIRE(cs1 <  &cs2);
        REQUIRE(cs1 <= &cs2);
        REQUIRE(cs2 >  &cs1);
        REQUIRE(cs2 >= &cs1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Equality_MultipleValue) {
        CS cs1("IDENTICAL\\VALID 1");
        CS cs2("IDENTICAL\\VALID 2");

        REQUIRE(cs1 == &cs1);
        REQUIRE(cs1 != &cs2);
        REQUIRE(cs2 != &cs1);

        REQUIRE(cs1 <  &cs2);
        REQUIRE(cs1 <= &cs2);
        REQUIRE(cs2 >  &cs1);
        REQUIRE(cs2 >= &cs1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Equality_DifferentMultiplicity) {
        CS cs1("IDENTICAL");
        CS cs2("IDENTICAL\\VALID");

        REQUIRE(cs1 == &cs1);
        REQUIRE(cs1 != &cs2);
        REQUIRE(cs2 != &cs1);

        REQUIRE(cs1 <  &cs2);
        REQUIRE(cs1 <= &cs2);
        REQUIRE(cs2 >  &cs1);
        REQUIRE(cs2 >= &cs1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Empty) {
        CS cs1;
        REQUIRE(cs1.Empty());

        CS cs2("VALID");
        REQUIRE(!cs2.Empty());

        CS cs3("");
        REQUIRE(cs3.Empty());

        CS cs4("   ");
        REQUIRE(cs4.Empty());

        CS cs5("\\");
        REQUIRE(!cs5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(CSTest, Copy) {
        CS cs_orig("VALID\\VALUES");
        std::unique_ptr<VR> vr_copy(cs_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto cs_copy = dynamic_cast<CS*>(vr_copy.get());
        REQUIRE(cs_copy != nullptr);

        REQUIRE(cs_orig.Value() == cs_copy->Value());
        REQUIRE(cs_orig == cs_copy);
    }
 
}