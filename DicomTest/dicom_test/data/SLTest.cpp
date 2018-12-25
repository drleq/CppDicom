#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/SL.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct SLTest {};
}

namespace dicom_test::data {

    TEST_CASE(SLTest, Construction) {
        // SL()
        SL sl0;
        CHECK(sl0.Value().Empty());
        CHECK(sl0.Length() == 0);
        CHECK(sl0.ByteLength() == 0);

        // SL(const buffer<int32_t>&)
        buffer<int32_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        SL sl1(binary_value);
        CHECK(sl1.Value() == binary_value);
        CHECK(sl1.Length() == 2);
        CHECK(sl1.ByteLength() == 2 * sizeof(int32_t));

        // SL(buffer<int32_t>&&)
        SL sl2(move(binary_value));
        CHECK(sl2.Value() == sl1.Value());
        CHECK(sl2.Length() == 2);
        CHECK(sl2.ByteLength() == 2 * sizeof(int32_t));
        CHECK(binary_value.Empty());

        // SL(int32_t)
        SL sl3(5);
        CHECK(sl3.Value()[0] == 5);
        CHECK(sl3.Length() == 1);
        CHECK(sl3.ByteLength() == 1 * sizeof(int32_t));

        // SL(const std::vector<int32_t>&)
        vector<int32_t> values;
        values.push_back(1);
        values.push_back(2);
        SL sl4(values);
        CHECK(sl4.Value()[0] == 1);
        CHECK(sl4.Value()[1] == 2);
        CHECK(sl4.Length() == 2);
        CHECK(sl4.ByteLength() == 2 * sizeof(int32_t));
        
        // SL(const SL&)
        SL sl5(sl4);
        CHECK(sl5.Value() == sl4.Value());
        CHECK(sl5.Length() == 2);
        CHECK(sl5.ByteLength() == 2 * sizeof(int32_t));

        // SL(SL&&)
        SL sl6(move(sl4));
        CHECK(sl6.Value() == sl5.Value());
        CHECK(sl6.Length() == 2);
        CHECK(sl6.ByteLength() == 2 * sizeof(int32_t));
        CHECK(sl4.Value().Empty());
        CHECK(sl4.Length() == 0);
        CHECK(sl4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, First) {
        SL sl1(1);
        CHECK(sl1.First() == 1);

        buffer<int32_t> binary_value(1);
        binary_value[0] = 3;
        SL sl2(binary_value);
        CHECK_EQUAL(sl2.First(), 3);

        vector<int32_t> values;
        values.push_back(-2);
        SL sl3(values);
        CHECK_EQUAL(sl3.First(), -2);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, Equality_SingleValue) {
        SL sl1(1);
        SL sl2(2);

        CHECK(sl1 == &sl1);
        CHECK(sl1 != &sl2);
        CHECK(sl2 != &sl1);

        CHECK(sl1 <  &sl2);
        CHECK(sl1 <= &sl2);
        CHECK(sl2 >  &sl1);
        CHECK(sl2 >= &sl1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, Equality_MultipleValue) {
        SL sl1({ 1, 1 });
        SL sl2({ 1, 2 });

        CHECK(sl1 == &sl1);
        CHECK(sl1 != &sl2);
        CHECK(sl2 != &sl1);

        CHECK(sl1 <  &sl2);
        CHECK(sl1 <= &sl2);
        CHECK(sl2 >  &sl1);
        CHECK(sl2 >= &sl1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, Equality_DifferentMultiplicity) {
        SL sl1(1);
        SL sl2({ 1, 1 });

        CHECK(sl1 == &sl1);
        CHECK(sl1 != &sl2);
        CHECK(sl2 != &sl1);

        CHECK(sl1 <  &sl2);
        CHECK(sl1 <= &sl2);
        CHECK(sl2 >  &sl1);
        CHECK(sl2 >= &sl1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, Empty) {
        SL sl1;
        CHECK(sl1.Empty());

        SL sl2(nullptr);
        CHECK(sl2.Empty());

        SL sl3(1);
        CHECK(!sl3.Empty());

        SL sl4(buffer<int32_t>(1));
        CHECK(!sl4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SLTest, Copy) {
        buffer<int32_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        SL sl_orig(binary_value);
        std::unique_ptr<VR> vr_copy(sl_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto sl_copy = dynamic_cast<SL*>(vr_copy.get());
        CHECK(sl_copy != nullptr);

        CHECK(sl_orig.Value() == sl_copy->Value());
        CHECK(sl_orig == sl_copy);
    }

}