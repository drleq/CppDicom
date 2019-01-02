#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/OL.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct OLTest {};
}

namespace dicom_test::data {

    TEST_CASE(OLTest, Construction) {
        // OL()
        OL ol0;
        CHECK(ol0.Value().Empty());
        CHECK(ol0.Length() == 0);
        CHECK(ol0.ByteLength() == 0);

        // OL(const buffer<int32_t>&)
        buffer<int32_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        OL ol1(binary_value);
        CHECK(ol1.Value() == binary_value);
        CHECK(ol1.Length() == 2);
        CHECK(ol1.ByteLength() == 2 * sizeof(int32_t));

        // OL(buffer<int32_t>&&)
        OL ol2(move(binary_value));
        CHECK(ol2.Value() == ol1.Value());
        CHECK(ol2.Length() == 2);
        CHECK(ol2.ByteLength() == 2 * sizeof(int32_t));
        CHECK(binary_value.Empty());
        
        // OL(const OL&)
        OL ol3(ol2);
        CHECK(ol3.Value() == ol3.Value());
        CHECK(ol3.Length() == 2);
        CHECK(ol3.ByteLength() == 2 * sizeof(int32_t));

        // OL(OL&&)
        OL ol4(move(ol3));
        CHECK(ol4.Value() == ol2.Value());
        CHECK(ol4.Length() == 2);
        CHECK(ol4.ByteLength() == 2 * sizeof(int32_t));
        CHECK(ol3.Value().Empty());
        CHECK(ol3.Length() == 0);
        CHECK(ol3.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OLTest, Equality_SingleValue) {
        OL ol1({ 1 });
        OL ol2({ 2 });

        CHECK(ol1 == &ol1);
        CHECK(ol1 != &ol2);
        CHECK(ol2 != &ol1);

        CHECK(ol1 <  &ol2);
        CHECK(ol1 <= &ol2);
        CHECK(ol2 >  &ol1);
        CHECK(ol2 >= &ol1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OLTest, Equality_MultipleValue) {
        OL ol1({ 1, 1 });
        OL ol2({ 1, 2 });

        CHECK(ol1 == &ol1);
        CHECK(ol1 != &ol2);
        CHECK(ol2 != &ol1);

        CHECK(ol1 <  &ol2);
        CHECK(ol1 <= &ol2);
        CHECK(ol2 >  &ol1);
        CHECK(ol2 >= &ol1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OLTest, Equality_DifferentMultiplicity) {
        OL ol1({ 1 });
        OL ol2({ 1, 1 });

        CHECK(ol1 == &ol1);
        CHECK(ol1 != &ol2);
        CHECK(ol2 != &ol1);

        CHECK(ol1 <  &ol2);
        CHECK(ol1 <= &ol2);
        CHECK(ol2 >  &ol1);
        CHECK(ol2 >= &ol1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OLTest, Empty) {
        OL ol1;
        CHECK(ol1.Empty());

        OL ol2(nullptr);
        CHECK(ol2.Empty());

        OL ol4(buffer<int32_t>(1));
        CHECK(!ol4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OLTest, Copy) {
        buffer<int32_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        OL ol_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ol_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto ol_copy = dynamic_cast<OL*>(vr_copy.get());
        CHECK(ol_copy != nullptr);

        CHECK(ol_orig.Value() == ol_copy->Value());
        CHECK(ol_orig == ol_copy);
    }

}