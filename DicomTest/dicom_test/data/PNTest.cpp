#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/PN.h"
#include "dicom_test/data/detail/constants.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct PNTest {};
}

namespace dicom_test::data {

    TEST_CASE(PNTest, Constructors) {
        // PN()
        PN pn0;
        CHECK_EQUAL(pn0.Validity(), ValidityType::Valid);
        CHECK(pn0.Value().Empty());
        CHECK(pn0.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(pn0.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(pn0.At(0)));

        // PN(encoded_string&&)
        PN pn1("Tables^Bobby");
        CHECK_EQUAL(pn1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn1.Value().Parsed(), "Tables^Bobby");
        CHECK_EQUAL(pn1.Parsed().size(), 1u);
        CHECK_EQUAL(pn1.Parsed()[0], encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn1.First(), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn1.At(0), encoded_string("Tables^Bobby"));
        
        // PN(const encoded_string&)
        encoded_string value("Tables^Bobby");
        PN pn2(value);
        CHECK_EQUAL(pn2.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn2.Value().Parsed(), "Tables^Bobby");
        CHECK_EQUAL(pn2.Parsed().size(), 1u);
        CHECK_EQUAL(pn2.Parsed()[0], encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn2.First(), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn2.At(0), encoded_string("Tables^Bobby"));

        // PN(const vector<PatientNameGroup>&)
        std::vector<PatientNameGroup> values;
        values.push_back(encoded_string("Tables^Bobby"));
        values.push_back(encoded_string("Tables^Jimmy"));
        PN pn3(values);
        CHECK_EQUAL(pn3.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn3.Value().Parsed(), "Tables^Bobby\\Tables^Jimmy");
        CHECK_EQUAL(pn3.Parsed().size(), 2u);
        CHECK_EQUAL(pn3.Parsed()[0], PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn3.Parsed()[1], PatientNameGroup("Tables^Jimmy"));
        CHECK_EQUAL(pn3.First(), PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn3.At(0), PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn3.At(1), PatientNameGroup("Tables^Jimmy"));

        // PN(initializer_list<PatientNameGroup>)
        PN pn4({ value, PatientNameGroup("Tables^Jimmy") });
        CHECK_EQUAL(pn4.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn4.Value().Parsed(), "Tables^Bobby\\Tables^Jimmy");
        CHECK_EQUAL(pn4.Parsed().size(), 2u);
        CHECK_EQUAL(pn4.Parsed()[0], PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn4.Parsed()[1], PatientNameGroup("Tables^Jimmy"));
        CHECK_EQUAL(pn4.First(), PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn4.At(0), PatientNameGroup("Tables^Bobby"));
        CHECK_EQUAL(pn4.At(1), PatientNameGroup("Tables^Jimmy"));

        // PN(const PN&)
        PN pn5(pn1);
        CHECK_EQUAL(pn5.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn5.Value().Parsed(), "Tables^Bobby");
        CHECK_EQUAL(pn5.Parsed().size(), 1u);
        CHECK_EQUAL(pn5.Parsed()[0], encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn5.First(), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn5.At(0), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn1.Value().Parsed(), "Tables^Bobby");
        CHECK_EQUAL(pn1.Parsed().size(), 1u);
        CHECK_EQUAL(pn1.Parsed()[0], encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn1.First(), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn1.At(0), encoded_string("Tables^Bobby"));

        // PN(PN&&)
        PN pn6(std::move(pn2));
        CHECK_EQUAL(pn6.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn6.Value().Parsed(), "Tables^Bobby");
        CHECK_EQUAL(pn6.Parsed().size(), 1u);
        CHECK_EQUAL(pn6.Parsed()[0], encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn6.First(), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn6.At(0), encoded_string("Tables^Bobby"));
        CHECK_EQUAL(pn2.Validity(), ValidityType::Deinitialized);
        CHECK(pn2.Value().Empty());
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(pn2.Parsed()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(pn2.First()));
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(pn2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Construction_Valid) {
        PN pn_single("Valid1");
        CHECK_EQUAL(pn_single.Value(), "Valid1");
        CHECK_EQUAL(pn_single.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn_single.Parsed().size(), 1u);
        CHECK_EQUAL(pn_single.Parsed()[0], PatientNameGroup("Valid1"));
        CHECK_EQUAL(pn_single.First(), PatientNameGroup("Valid1"));

        PN pn_multiple("Value1\\Value2");
        CHECK_EQUAL(pn_multiple.Value(), "Value1\\Value2");
        CHECK_EQUAL(pn_multiple.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn_multiple.Parsed().size(), 2u);
        CHECK_EQUAL(pn_multiple.Parsed()[0], PatientNameGroup("Value1"));
        CHECK_EQUAL(pn_multiple.Parsed()[1], PatientNameGroup("Value2"));
        CHECK_EQUAL(pn_multiple.First(), PatientNameGroup("Value1"));

        PN pn_empty1("    ");
        CHECK_EQUAL(pn_empty1.Value(), "    ");
        CHECK_EQUAL(pn_empty1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(pn_empty1.ParsedCount(), 1u);
        CHECK_EQUAL(pn_empty1.Parsed()[0], PatientNameGroup("    "));
        CHECK_EQUAL(pn_empty1.First(), PatientNameGroup("    "));

        PN sh_empty2("");
        CHECK_EQUAL(sh_empty2.Value(), "");
        CHECK_EQUAL(sh_empty2.Validity(), ValidityType::Valid);
        CHECK(sh_empty2.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(sh_empty2.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(sh_empty2.At(0)));
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Equality_SingleValue) {
        PN pn1("Valid 1");
        PN pn2("Valid 2");

        CHECK(pn1 == &pn1);
        CHECK(pn1 != &pn2);
        CHECK(pn2 != &pn1);

        CHECK(pn1 <  &pn2);
        CHECK(pn1 <= &pn2);
        CHECK(pn2 >  &pn1);
        CHECK(pn2 >= &pn1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Equality_MultipleValue) {
        PN pn1("Identical\\Valid 1");
        PN pn2("Identical\\Valid 2");

        CHECK(pn1 == &pn1);
        CHECK(pn1 != &pn2);
        CHECK(pn2 != &pn1);

        CHECK(pn1 <  &pn2);
        CHECK(pn1 <= &pn2);
        CHECK(pn2 >  &pn1);
        CHECK(pn2 >= &pn1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Equality_DifferentMultiplicity) {
        PN pn1("Identical");
        PN pn2("Identical\\Valid");

        CHECK(pn1 == &pn1);
        CHECK(pn1 != &pn2);
        CHECK(pn2 != &pn1);

        CHECK(pn1 <  &pn2);
        CHECK(pn1 <= &pn2);
        CHECK(pn2 >  &pn1);
        CHECK(pn2 >= &pn1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Empty) {
        PN pn1;
        CHECK(pn1.Empty());

        PN pn2("Valid");
        CHECK(!pn2.Empty());

        PN pn3("");
        CHECK(pn3.Empty());

//        PN pn4("   ");
//        CHECK(pn4.Empty());

        PN pn5("\\");
        CHECK(!pn5.Empty());
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PNTest, Copy) {
        PN pn_orig("Valid\\Values");
        std::unique_ptr<VR> vr_copy(pn_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto pn_copy = dynamic_cast<PN*>(vr_copy.get());
        CHECK(pn_copy != nullptr);

        CHECK(pn_orig.Value() == pn_copy->Value());
        CHECK(pn_orig == pn_copy);
    }
 
}