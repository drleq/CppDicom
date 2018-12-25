#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/PatientNameGroup.h"
#include "dicom_test/data/detail/constants.h"
#include "dicom/data/value_invalid.h"

using namespace dicom::data;

namespace {
    struct PatientNameGroupTest {};
}

namespace dicom_test::data {

    TEST_CASE(PatientNameGroupTest, Construction) {
        // PatientNameGroup()
        PatientNameGroup png0;
        CHECK_EQUAL(png0.Validity(), ValidityType::Valid);
        CHECK(png0.Empty());
        CHECK_EQUAL(png0.ParsedCount(), 0u);
        CHECK_EQUAL(png0.Value(), encoded_string());
        CHECK_EQUAL(png0.Alphabetic(), ComponentGroup());
        CHECK_EQUAL(png0.Ideographic(), ComponentGroup());
        CHECK_EQUAL(png0.Phonetic(), ComponentGroup());

        // PatientNameGroup(const encoded_string&)
        encoded_string value("Tables^Bobby=Tables^Jimmy");
        PatientNameGroup png1(value);
        CHECK_EQUAL(png1.Validity(), ValidityType::Valid);
        CHECK_FALSE(png1.Empty());
        CHECK_EQUAL(png1.ParsedCount(), 2u);
        CHECK_EQUAL(png1.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png1.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png1.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png1.Phonetic(), ComponentGroup());

        // PatientNameGroup(encoded_string&&)
        PatientNameGroup png2{ encoded_string(value) };
        CHECK_EQUAL(png2.Validity(), ValidityType::Valid);
        CHECK_FALSE(png2.Empty());
        CHECK_EQUAL(png2.ParsedCount(), 2u);
        CHECK_EQUAL(png2.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png2.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png2.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png2.Phonetic(), ComponentGroup());

        // ComponentGroup(const std::array<ComponentGroup, 3>&)
        std::array<ComponentGroup, 3> values = {
            ComponentGroup("Tables^Bobby"), ComponentGroup("Tables^Jimmy")
        };
        PatientNameGroup png3(values);
        CHECK_EQUAL(png3.Validity(), ValidityType::Valid);
        CHECK_FALSE(png3.Empty());
        CHECK_EQUAL(png3.ParsedCount(), 2u);
        CHECK_EQUAL(png3.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png3.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png3.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png3.Phonetic(), ComponentGroup());

        // PatientNameGroup(std::initializer_list<ComponentGroup>)
        PatientNameGroup png4({
            ComponentGroup("Tables^Bobby"), ComponentGroup("Tables^Jimmy")
        });
        CHECK_EQUAL(png4.Validity(), ValidityType::Valid);
        CHECK_FALSE(png4.Empty());
        CHECK_EQUAL(png4.ParsedCount(), 2u);
        CHECK_EQUAL(png4.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png4.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png4.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png4.Phonetic(), ComponentGroup());

        // PatientNameGroup(const PatientNameGroup&)
        PatientNameGroup png5(png4);
        CHECK_EQUAL(png5.Validity(), ValidityType::Valid);
        CHECK_FALSE(png5.Empty());
        CHECK_EQUAL(png5.ParsedCount(), 2u);
        CHECK_EQUAL(png5.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png5.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png5.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png5.Phonetic(), ComponentGroup());

        // PatientNameGroup(PatientNameGroup&&)
        PatientNameGroup png6(std::move(png5));
        CHECK_EQUAL(png6.Validity(), ValidityType::Valid);
        CHECK_FALSE(png6.Empty());
        CHECK_EQUAL(png6.ParsedCount(), 2u);
        CHECK_EQUAL(png6.Value(), "Tables^Bobby=Tables^Jimmy");
        CHECK_EQUAL(png6.Alphabetic(), ComponentGroup("Tables^Bobby"));
        CHECK_EQUAL(png6.Ideographic(), ComponentGroup("Tables^Jimmy"));
        CHECK_EQUAL(png6.Phonetic(), ComponentGroup());
        CHECK_EQUAL(png5.Validity(), ValidityType::Deinitialized);
        CHECK(png5.Empty());
        CHECK_EQUAL(png5.ParsedCount(), 0u);
        CHECK_EQUAL(png5.Value().Validity(), ValidityType::Deinitialized);
        CHECK_EQUAL(png5.Alphabetic(), ComponentGroup());
        CHECK_EQUAL(png5.Ideographic(), ComponentGroup());
        CHECK_EQUAL(png5.Phonetic(), ComponentGroup());
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(PatientNameGroupTest, Construction_InvalidChars) {
        PatientNameGroup invalid("Tables\\Bobby");
        CHECK_EQUAL(invalid.Validity(), ValidityType::Invalid);
        CHECK_FALSE(invalid.Empty());
        CHECK_EQUAL(invalid.Value(), "Tables\\Bobby");
        CHECK_EQUAL(invalid.Alphabetic(), ComponentGroup());
        CHECK_EQUAL(invalid.Ideographic(), ComponentGroup());
        CHECK_EQUAL(invalid.Phonetic(), ComponentGroup());
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(PatientNameGroupTest, Empty) {
        PatientNameGroup empty0;
        CHECK(empty0.Empty());

        PatientNameGroup empty1("");
        CHECK(empty1.Empty());

        PatientNameGroup empty2({});
        CHECK(empty2.Empty());
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(PatientNameGroupTest, Equality_SingleValue) {
        PatientNameGroup png1("Valid1");
        PatientNameGroup png2("Valid2");

        CHECK(png1 == png1);
        CHECK(png1 != png2);
        CHECK(png2 != png1);

        CHECK(png1 <  png2);
        CHECK(png1 <= png2);
        CHECK(png2 >  png1);
        CHECK(png2 >= png1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PatientNameGroupTest, Equality_MultipleValue) {
        PatientNameGroup png1("Identical\\Valid1");
        PatientNameGroup png2("Identical\\Valid2");

        CHECK(png1 == png1);
        CHECK(png1 != png2);
        CHECK(png2 != png1);

        CHECK(png1 <  png2);
        CHECK(png1 <= png2);
        CHECK(png2 >  png1);
        CHECK(png2 >= png1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(PatientNameGroupTest, Equality_DifferentMultiplicity) {
        PatientNameGroup png1("Identical");
        PatientNameGroup png2("Identical\\Valid");

        CHECK(png1 == png1);
        CHECK(png1 != png2);
        CHECK(png2 != png1);

        CHECK(png1 <  png2);
        CHECK(png1 <= png2);
        CHECK(png2 >  png1);
        CHECK(png2 >= png1);
    }

}