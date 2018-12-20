#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/AT.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct ATTest {};
}

namespace dicom_test::data {

    TEST_CASE(ATTest, Construction) {
        // AT()
        AT at0;
        REQUIRE(at0.Validity() == ValidityType::Valid);
        REQUIRE(at0.Value().empty());
        REQUIRE_THROW(value_empty_error, UNUSED_RETURN(at0.First()));

        // AT(int32_t)
        AT at1(0);
        REQUIRE(at1.Validity() == ValidityType::Valid);
        REQUIRE(at1.Value().size() == 1);
        REQUIRE(at1.First() == tag_number(0));

        // AT(int32_t)
        AT at2(tags::SOPInstanceUID);
        REQUIRE(at2.Validity() == ValidityType::Valid);
        REQUIRE(at2.Value().size() == 1);
        REQUIRE(at2.First() == tag_number(tags::SOPInstanceUID));

        // AT(int16_t, int16_t)
        AT at3(tags::SOPInstanceUID.Group(), tags::SOPInstanceUID.Element());
        REQUIRE(at3.Validity() == ValidityType::Valid);
        REQUIRE(at3.Value().size() == 1);
        REQUIRE(at3.First() == tag_number(tags::SOPInstanceUID));

        // AT(tag_number)
        tag_number value(tags::SOPInstanceUID);
        AT at4(value);
        REQUIRE(at4.Validity() == ValidityType::Valid);
        REQUIRE(at4.Value().size() == 1);
        REQUIRE(at4.First() == tag_number(tags::SOPInstanceUID));

        // AT(const container_type&)
        vector<tag_number> values;
        values.push_back(value);
        values.push_back(tag_number(tags::SeriesInstanceUID));
        AT at5(values);
        REQUIRE(at5.Validity() == ValidityType::Valid);
        REQUIRE(at5.Value().size() == 2);
        REQUIRE(at5.First() == tag_number(tags::SOPInstanceUID));
        REQUIRE(at5.Value()[1] == tag_number(tags::SeriesInstanceUID));

        // AT(container_type&&)
        AT at6(move(values));
        REQUIRE(at5.Validity() == ValidityType::Valid);
        REQUIRE(at5.Value().size() == 2);
        REQUIRE(at5.First() == tag_number(tags::SOPInstanceUID));
        REQUIRE(at5.Value()[1] == tag_number(tags::SeriesInstanceUID));

        // AT(const AT&)
        AT at7(at2);
        REQUIRE(at7.Validity() == ValidityType::Valid);
        REQUIRE(at7.Value().size() == 1);
        REQUIRE(at7.First() == tag_number(tags::SOPInstanceUID));
        REQUIRE(at2.Validity() == ValidityType::Valid);
        REQUIRE(at2.Value().size() == 1);
        REQUIRE(at2.First() == tag_number(tags::SOPInstanceUID));

        // AT(AT&&)
        AT at8(move(at2));
        REQUIRE(at8.Validity() == ValidityType::Valid);
        REQUIRE(at8.Value().size() == 1);
        REQUIRE(at8.First() == tag_number(tags::SOPInstanceUID));
        REQUIRE(at2.Validity() == ValidityType::Deinitialized);
        REQUIRE(at2.Value().empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ATTest, Empty) {
        AT at1;
        REQUIRE(at1.Empty());

        AT at2(0);
        REQUIRE(!at2.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ATTest, Equality) {
        AT at1(0x12345678);
        AT at2(0x5678, 0x1234);

        REQUIRE(at1 == &at1);
        REQUIRE(at1 != &at2);
        REQUIRE(at2 != &at1);

        REQUIRE(at1 <  &at2);
        REQUIRE(at1 <= &at2);
        REQUIRE(at2 >  &at1);
        REQUIRE(at2 >= &at1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ATTest, Copy) {
        AT at_orig(tags::SOPInstanceUID);
        std::unique_ptr<VR> vr_copy(at_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto at_copy = dynamic_cast<AT*>(vr_copy.get());
        REQUIRE(at_copy != nullptr);
        REQUIRE(at_orig == at_copy);
    }

}