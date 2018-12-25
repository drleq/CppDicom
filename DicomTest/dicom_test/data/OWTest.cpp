#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/OW.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct OWTest {};
}

namespace dicom_test::data {

    TEST_CASE(OWTest, Construction) {
        // OW()
        OW ow0;
        CHECK(ow0.Value().Empty());
        CHECK(ow0.Length() == 0);
        CHECK(ow0.ByteLength() == 0);

        // OW(const buffer<int16_t>&)
        buffer<int16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        OW ow1(binary_value);
        CHECK(ow1.Value() == binary_value);
        CHECK(ow1.Length() == 2);
        CHECK(ow1.ByteLength() == 2 * sizeof(int16_t));

        // OW(buffer<int16_t>&&)
        OW ow2(move(binary_value));
        CHECK(ow2.Value() == ow1.Value());
        CHECK(ow2.Length() == 2);
        CHECK(ow2.ByteLength() == 2 * sizeof(int16_t));
        CHECK(binary_value.Empty());
        
        // OW(const OW&)
        OW ow3(ow2);
        CHECK(ow3.Value() == ow3.Value());
        CHECK(ow3.Length() == 2);
        CHECK(ow3.ByteLength() == 2 * sizeof(int16_t));

        // OW(OW&&)
        OW ow4(move(ow3));
        CHECK(ow4.Value() == ow2.Value());
        CHECK(ow4.Length() == 2);
        CHECK(ow4.ByteLength() == 2 * sizeof(int16_t));
        CHECK(ow3.Value().Empty());
        CHECK(ow3.Length() == 0);
        CHECK(ow3.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OWTest, Equality_SingleValue) {
        OW ow1({ 1 });
        OW ow2({ 2 });

        CHECK(ow1 == &ow1);
        CHECK(ow1 != &ow2);
        CHECK(ow2 != &ow1);

        CHECK(ow1 <  &ow2);
        CHECK(ow1 <= &ow2);
        CHECK(ow2 >  &ow1);
        CHECK(ow2 >= &ow1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OWTest, Equality_MultipleValue) {
        OW ow1({ 1, 1 });
        OW ow2({ 1, 2 });

        CHECK(ow1 == &ow1);
        CHECK(ow1 != &ow2);
        CHECK(ow2 != &ow1);

        CHECK(ow1 <  &ow2);
        CHECK(ow1 <= &ow2);
        CHECK(ow2 >  &ow1);
        CHECK(ow2 >= &ow1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OWTest, Equality_DifferentMultiplicity) {
        OW ow1({ 1 });
        OW ow2({ 1, 1 });

        CHECK(ow1 == &ow1);
        CHECK(ow1 != &ow2);
        CHECK(ow2 != &ow1);

        CHECK(ow1 <  &ow2);
        CHECK(ow1 <= &ow2);
        CHECK(ow2 >  &ow1);
        CHECK(ow2 >= &ow1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OWTest, Empty) {
        OW ow1;
        CHECK(ow1.Empty());

        OW ow2(nullptr);
        CHECK(ow2.Empty());

        OW ow4(buffer<int16_t>(1));
        CHECK(!ow4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(OWTest, Copy) {
        buffer<int16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        OW ow_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ow_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto ow_copy = dynamic_cast<OW*>(vr_copy.get());
        CHECK(ow_copy != nullptr);

        CHECK(ow_orig.Value() == ow_copy->Value());
        CHECK(ow_orig == ow_copy);
    }

}