#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/FL.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct FLTest {};
}

namespace dicom_test::data {

    TEST_CASE(FLTest, Construction) {
        // FL()
        FL fl0;
        REQUIRE(fl0.Value().Empty());
        REQUIRE(fl0.Length() == 0);
        REQUIRE(fl0.ByteLength() == 0);

        // FL(const buffer<float>&)
        buffer<float> binary_value(2);
        binary_value[0] = 1.0f;
        binary_value[1] = 2.0f;
        FL fl1(binary_value);
        REQUIRE(fl1.Value() == binary_value);
        REQUIRE(fl1.Length() == 2);
        REQUIRE(fl1.ByteLength() == 2 * sizeof(float));

        // FL(buffer<float>&&)
        FL fl2(move(binary_value));
        REQUIRE(fl2.Value() == fl1.Value());
        REQUIRE(fl2.Length() == 2);
        REQUIRE(fl2.ByteLength() == 2 * sizeof(float));
        REQUIRE(binary_value.Empty());

        // FL(float)
        FL fl3(5.2f);
        REQUIRE(fl3.Value()[0] == 5.2f);
        REQUIRE(fl3.Length() == 1);
        REQUIRE(fl3.ByteLength() == 1 * sizeof(float));

        // FL(const std::vector<float>&)
        vector<float> values;
        values.push_back(1.0f);
        values.push_back(2.0f);
        FL fl4(values);
        REQUIRE(fl4.Value()[0] == 1.0f);
        REQUIRE(fl4.Value()[1] == 2.0f);
        REQUIRE(fl4.Length() == 2);
        REQUIRE(fl4.ByteLength() == 2 * sizeof(float));
        
        // FL(const FL&)
        FL fl5(fl4);
        REQUIRE(fl5.Value() == fl4.Value());
        REQUIRE(fl5.Length() == 2);
        REQUIRE(fl5.ByteLength() == 2 * sizeof(float));

        // FL(FL&&)
        FL fl6(move(fl4));
        REQUIRE(fl6.Value() == fl5.Value());
        REQUIRE(fl6.Length() == 2);
        REQUIRE(fl6.ByteLength() == 2 * sizeof(float));
        REQUIRE(fl4.Value().Empty());
        REQUIRE(fl4.Length() == 0);
        REQUIRE(fl4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, First) {
        FL fl1(1.0f);
        REQUIRE(fl1.First() == 1.0f);

        buffer<float> binary_value(1);
        binary_value[0] = 3.0f;
        FL fl2(binary_value);
        REQUIRE_EQUAL(fl2.First(), 3.0f);

        vector<float> values;
        values.push_back(-2.5f);
        FL fl3(values);
        REQUIRE_EQUAL(fl3.First(), -2.5f);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, Equality_SingleValue) {
        FL fl1(1.0f);
        FL fl2(1.1f);

        REQUIRE(fl1 == &fl1);
        REQUIRE(fl1 != &fl2);
        REQUIRE(fl2 != &fl1);

        REQUIRE(fl1 <  &fl2);
        REQUIRE(fl1 <= &fl2);
        REQUIRE(fl2 >  &fl1);
        REQUIRE(fl2 >= &fl1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, Equality_MultipleValue) {
        vector<float> tmp(2);
        FL fl1(tmp);
        FL fl2(tmp);

        fl1.Value()[0] = fl2.Value()[0] = 1.0f;
        fl1.Value()[1] = 1.0f;
        fl2.Value()[1] = 1.1f;

        REQUIRE(fl1 == &fl1);
        REQUIRE(fl1 != &fl2);
        REQUIRE(fl2 != &fl1);

        REQUIRE(fl1 <  &fl2);
        REQUIRE(fl1 <= &fl2);
        REQUIRE(fl2 >  &fl1);
        REQUIRE(fl2 >= &fl1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, Equality_DifferentMultiplicity) {
        vector<float> tmp(2);
        FL fl1(1.0f);
        FL fl2(tmp);

        fl2.Value()[0] = fl1.First();
        fl2.Value()[1] = 1.1f;

        REQUIRE(fl1 == &fl1);
        REQUIRE(fl1 != &fl2);
        REQUIRE(fl2 != &fl1);

        REQUIRE(fl1 <  &fl2);
        REQUIRE(fl1 <= &fl2);
        REQUIRE(fl2 >  &fl1);
        REQUIRE(fl2 >= &fl1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, Empty) {
        FL fl1;
        REQUIRE(fl1.Empty());

        FL fl2(nullptr);
        REQUIRE(fl2.Empty());

        FL fl3(1.0);
        REQUIRE(!fl3.Empty());

        FL fl4(buffer<float>(1));
        REQUIRE(!fl4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FLTest, Copy) {
        buffer<float> binary_value(2);
        binary_value[0] = 1.0f;
        binary_value[1] = -2.0f;

        FL fl_orig(binary_value);
        std::unique_ptr<VR> vr_copy(fl_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto fl_copy = dynamic_cast<FL*>(vr_copy.get());
        REQUIRE(fl_copy != nullptr);

        REQUIRE(fl_orig.Value() == fl_copy->Value());
        REQUIRE(fl_orig == fl_copy);
    }

}