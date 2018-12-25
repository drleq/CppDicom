#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/OF.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct OFTest {};
}

namespace dicom_test::data {

    TEST_CASE(OFTest, Construction) {
        // OF()
        OF of0;
        CHECK(of0.Value().Empty());
        CHECK(of0.Length() == 0);
        CHECK(of0.ByteLength() == 0);

        // OF(const buffer<float>&)
        buffer<float> binary_value(2);
        binary_value[0] = 1.0f;
        binary_value[1] = 2.0f;
        OF of1(binary_value);
        CHECK(of1.Value() == binary_value);
        CHECK(of1.Length() == 2);
        CHECK(of1.ByteLength() == 2 * sizeof(float));

        // OF(buffer<float>&&)
        OF of2(move(binary_value));
        CHECK(of2.Value() == of1.Value());
        CHECK(of2.Length() == 2);
        CHECK(of2.ByteLength() == 2 * sizeof(float));
        CHECK(binary_value.Empty());
        
        // OF(const OF&)
        OF of3(of2);
        CHECK(of3.Value() == of3.Value());
        CHECK(of3.Length() == 2);
        CHECK(of3.ByteLength() == 2 * sizeof(float));

        // OF(OF&&)
        OF of4(move(of3));
        CHECK(of4.Value() == of2.Value());
        CHECK(of4.Length() == 2);
        CHECK(of4.ByteLength() == 2 * sizeof(float));
        CHECK(of3.Value().Empty());
        CHECK(of3.Length() == 0);
        CHECK(of3.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OFTest, Equality_SingleValue) {
        OF of1({ 1.0f });
        OF of2({ 1.1f });

        CHECK(of1 == &of1);
        CHECK(of1 != &of2);
        CHECK(of2 != &of1);

        CHECK(of1 <  &of2);
        CHECK(of1 <= &of2);
        CHECK(of2 >  &of1);
        CHECK(of2 >= &of1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OFTest, Equality_MultipleValue) {
        OF of1({ 1.0f, 1.0f });
        OF of2({ 1.0f, 1.1f });

        CHECK(of1 == &of1);
        CHECK(of1 != &of2);
        CHECK(of2 != &of1);

        CHECK(of1 <  &of2);
        CHECK(of1 <= &of2);
        CHECK(of2 >  &of1);
        CHECK(of2 >= &of1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OFTest, Equality_DifferentMultiplicity) {
        OF of1({ 1.0f });
        OF of2({ 1.0f, 1.0f });

        CHECK(of1 == &of1);
        CHECK(of1 != &of2);
        CHECK(of2 != &of1);

        CHECK(of1 <  &of2);
        CHECK(of1 <= &of2);
        CHECK(of2 >  &of1);
        CHECK(of2 >= &of1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OFTest, Empty) {
        OF of1;
        CHECK(of1.Empty());

        OF of2(nullptr);
        CHECK(of2.Empty());

        OF of4(buffer<float>(1));
        CHECK(!of4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OFTest, Copy) {
        buffer<float> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        OF ow_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ow_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto ow_copy = dynamic_cast<OF*>(vr_copy.get());
        CHECK(ow_copy != nullptr);

        CHECK(ow_orig.Value() == ow_copy->Value());
        CHECK(ow_orig == ow_copy);
    }

}