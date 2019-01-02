#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/OB.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct OBTest {};
}

namespace dicom_test::data {

    TEST_CASE(OBTest, Construction) {
        // OB()
        OB ob0;
        CHECK(ob0.Value().Empty());
        CHECK(ob0.Length() == 0);
        CHECK(ob0.ByteLength() == 0);

        // OB(const buffer<int8_t>&)
        buffer<int8_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        OB ob1(binary_value);
        CHECK(ob1.Value() == binary_value);
        CHECK(ob1.Length() == 2);
        CHECK(ob1.ByteLength() == 2 * sizeof(int8_t));

        // OB(buffer<int8_t>&&)
        OB ob2(move(binary_value));
        CHECK(ob2.Value() == ob1.Value());
        CHECK(ob2.Length() == 2);
        CHECK(ob2.ByteLength() == 2 * sizeof(int8_t));
        CHECK(binary_value.Empty());
        
        // OB(const OB&)
        OB ob3(ob2);
        CHECK(ob3.Value() == ob3.Value());
        CHECK(ob3.Length() == 2);
        CHECK(ob3.ByteLength() == 2 * sizeof(int8_t));

        // OB(OB&&)
        OB ob4(move(ob3));
        CHECK(ob4.Value() == ob2.Value());
        CHECK(ob4.Length() == 2);
        CHECK(ob4.ByteLength() == 2 * sizeof(int8_t));
        CHECK(ob3.Value().Empty());
        CHECK(ob3.Length() == 0);
        CHECK(ob3.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OBTest, Equality_SingleValue) {
        OB ob1({ 1 });
        OB ob2({ 2 });

        CHECK(ob1 == &ob1);
        CHECK(ob1 != &ob2);
        CHECK(ob2 != &ob1);

        CHECK(ob1 <  &ob2);
        CHECK(ob1 <= &ob2);
        CHECK(ob2 >  &ob1);
        CHECK(ob2 >= &ob1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OBTest, Equality_MultipleValue) {
        OB ob1({ 1, 1 });
        OB ob2({ 1, 2 });

        CHECK(ob1 == &ob1);
        CHECK(ob1 != &ob2);
        CHECK(ob2 != &ob1);

        CHECK(ob1 <  &ob2);
        CHECK(ob1 <= &ob2);
        CHECK(ob2 >  &ob1);
        CHECK(ob2 >= &ob1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OBTest, Equality_DifferentMultiplicity) {
        OB ob1({ 1 });
        OB ob2({ 1, 1 });

        CHECK(ob1 == &ob1);
        CHECK(ob1 != &ob2);
        CHECK(ob2 != &ob1);

        CHECK(ob1 <  &ob2);
        CHECK(ob1 <= &ob2);
        CHECK(ob2 >  &ob1);
        CHECK(ob2 >= &ob1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OBTest, Empty) {
        OB ob1;
        CHECK(ob1.Empty());

        OB ob2(nullptr);
        CHECK(ob2.Empty());

        OB ob4(buffer<int8_t>(1));
        CHECK(!ob4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OBTest, Copy) {
        buffer<int8_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        OB ow_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ow_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto ow_copy = dynamic_cast<OB*>(vr_copy.get());
        CHECK(ow_copy != nullptr);

        CHECK(ow_orig.Value() == ow_copy->Value());
        CHECK(ow_orig == ow_copy);
    }

}