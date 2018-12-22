#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UI.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct UITest {};
}

namespace dicom_test::data {

    TEST_CASE(UITest, Constructors) {
        // UI()
        UI ui0;
        CHECK_EQUAL(ui0.Validity(), ValidityType::Invalid);
        CHECK(ui0.Value().empty());
        CHECK_EQUAL(ui0.ParsedCount(), 0u);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui0.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui0.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui0.At(0)));

        // UI(const string_view&)
        UI ui1("1.2.3.4.5");
        CHECK_EQUAL(ui1.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui1.ParsedCount(), 1u);
        CHECK_EQUAL(ui1.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui1.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui1.At(0), "1.2.3.4.5");
        
        // UI(string&&)
        std::string value("1.2.3.4.5");
        UI ui2{ std::string(value) };
        CHECK_EQUAL(ui2.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui2.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui2.ParsedCount(), 1u);
        CHECK_EQUAL(ui2.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui2.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui2.At(0), "1.2.3.4.5");

        // UI(const vector<string_view>&)
        std::vector<std::string_view> values;
        values.push_back("1.2.3.4.5");
        values.push_back("6.7.8.9.10");
        UI ui3(values);
        CHECK_EQUAL(ui3.Value(), "1.2.3.4.5\\6.7.8.9.10");
        CHECK_EQUAL(ui3.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui3.ParsedCount(), 2u);
        CHECK_EQUAL(ui3.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui3.Parsed()[1], "6.7.8.9.10");
        CHECK_EQUAL(ui3.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui3.At(0), "1.2.3.4.5");
        CHECK_EQUAL(ui3.At(1), "6.7.8.9.10");

        // UI(initializer_list<string_view>)
        UI ui4({ "1.2.3.4.5", "6.7.8.9.10" });
        CHECK_EQUAL(ui4.Value(), "1.2.3.4.5\\6.7.8.9.10");
        CHECK_EQUAL(ui4.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui4.ParsedCount(), 2u);
        CHECK_EQUAL(ui4.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui4.Parsed()[1], "6.7.8.9.10");
        CHECK_EQUAL(ui4.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui4.At(0), "1.2.3.4.5");
        CHECK_EQUAL(ui4.At(1), "6.7.8.9.10");

        // UI(const UI&)
        UI ui5(ui1);
        CHECK_EQUAL(ui5.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui5.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui5.ParsedCount(), 1u);
        CHECK_EQUAL(ui5.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui5.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui5.At(0), "1.2.3.4.5");
        CHECK_EQUAL(ui1.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui1.ParsedCount(), 1u);
        CHECK_EQUAL(ui1.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui1.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui1.At(0), "1.2.3.4.5");

        // UI(UI&&)
        UI ui6(std::move(ui2));
        CHECK_EQUAL(ui6.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui6.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui6.ParsedCount(), 1u);
        CHECK_EQUAL(ui6.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui6.First(), "1.2.3.4.5");
        CHECK_EQUAL(ui6.At(0), "1.2.3.4.5");
        CHECK(ui2.Value().empty());
        CHECK_EQUAL(ui2.Validity(), ValidityType::Deinitialized);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui2.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Construction_Valid) {
        UI ui_single("1.2.3.4.5");
        CHECK_EQUAL(ui_single.Value(), "1.2.3.4.5");
        CHECK_EQUAL(ui_single.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui_single.ParsedCount(), 1u);
        CHECK_EQUAL(ui_single.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui_single.First(), "1.2.3.4.5");

        UI ui_multiple("1.2.3.4.5\\6.7.8.9.10");
        CHECK_EQUAL(ui_multiple.Value(), "1.2.3.4.5\\6.7.8.9.10");
        CHECK_EQUAL(ui_multiple.Validity(), ValidityType::Valid);
        CHECK_EQUAL(ui_multiple.ParsedCount(), 2u);
        CHECK_EQUAL(ui_multiple.Parsed()[0], "1.2.3.4.5");
        CHECK_EQUAL(ui_multiple.Parsed()[1], "6.7.8.9.10");
        CHECK_EQUAL(ui_multiple.First(), "1.2.3.4.5");

        UI ui_empty1("    ");
        CHECK_EQUAL(ui_empty1.Value(), "    ");
        CHECK_EQUAL(ui_empty1.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(ui_empty1.ParsedCount(), 0u);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui_empty1.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui_empty1.At(0)));

        UI ui_empty2("");
        CHECK_EQUAL(ui_empty2.Value(), "");
        CHECK_EQUAL(ui_empty2.Validity(), ValidityType::Invalid);
        CHECK_EQUAL(ui_empty2.ParsedCount(), 0u);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui_empty2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(ui_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Construction_Overlong) {
        auto value = "1.2.3.4.5." + std::string(64, '6');
        UI ui(value);
        CHECK_EQUAL(ui.Value(), value);
        CHECK_EQUAL(ui.Validity(), ValidityType::Acceptable);
        CHECK_EQUAL(ui.ParsedCount(), 1u);
        CHECK_EQUAL(ui.Parsed()[0], value);
        CHECK_EQUAL(ui.First(), value);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Construction_InvalidCharacters) {
        UI cs_single("invalid");
        CHECK_EQUAL(cs_single.Value(), "invalid");
        CHECK_EQUAL(cs_single.Validity(), ValidityType::Invalid);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(cs_single.Parsed()));

        UI cs_multiple("1.2.3.4.5\\invalid");
        CHECK_EQUAL(cs_multiple.Value(), "1.2.3.4.5\\invalid");
        CHECK_EQUAL(cs_multiple.Validity(), ValidityType::Invalid);
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(cs_multiple.Parsed()));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Equality_SingleValue) {
        UI ui1("1.2.3.4.5");
        UI ui2("1.2.3.4.6");

        CHECK(ui1 == &ui1);
        CHECK(ui1 != &ui2);
        CHECK(ui2 != &ui1);

        CHECK(ui1 <  &ui2);
        CHECK(ui1 <= &ui2);
        CHECK(ui2 >  &ui1);
        CHECK(ui2 >= &ui1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Equality_MultipleValue) {
        UI ui1("1.2.3.4.5\\6.7.8");
        UI ui2("1.2.3.4.5\\6.7.9");

        CHECK(ui1 == &ui1);
        CHECK(ui1 != &ui2);
        CHECK(ui2 != &ui1);

        CHECK(ui1 <  &ui2);
        CHECK(ui1 <= &ui2);
        CHECK(ui2 >  &ui1);
        CHECK(ui2 >= &ui1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Equality_DifferentMultiplicity) {
        UI ui1("1.2.3.4.5");
        UI ui2("1.2.3.4.5\\6.7.8.9");

        CHECK(ui1 == &ui1);
        CHECK(ui1 != &ui2);
        CHECK(ui2 != &ui1);

        CHECK(ui1 <  &ui2);
        CHECK(ui1 <= &ui2);
        CHECK(ui2 >  &ui1);
        CHECK(ui2 >= &ui1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Empty) {
        UI ui1;
        CHECK(ui1.Empty());

        UI ui2("1.2.3.4.5");
        CHECK(!ui2.Empty());

        UI ui3("");
        CHECK(ui3.Empty());

        UI ui4("   ");
        CHECK(!ui4.Empty());

        UI ui5("\\");
        CHECK(!ui5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UITest, Copy) {
        UI ui_orig("1.2.3.4.5\\6.7.8.9.10");
        std::unique_ptr<VR> vr_copy(ui_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto ui_copy = dynamic_cast<UI*>(vr_copy.get());
        REQUIRE(ui_copy != nullptr);

        CHECK_EQUAL(ui_orig.Value(), ui_copy->Value());
        CHECK(ui_orig == ui_copy);
    }
 
}