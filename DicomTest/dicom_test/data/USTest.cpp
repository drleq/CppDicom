#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/US.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct USTest {};
}

namespace dicom_test::data {

    TEST_CASE(USTest, Construction) {
        // US()
        US us0;
        REQUIRE(us0.Value().Empty());
        REQUIRE(us0.Length() == 0);
        REQUIRE(us0.ByteLength() == 0);

        // US(const buffer<uint16_t>&)
        buffer<uint16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        US us1(binary_value);
        REQUIRE(us1.Value() == binary_value);
        REQUIRE(us1.Length() == 2);
        REQUIRE(us1.ByteLength() == 2 * sizeof(uint16_t));

        // US(buffer<uint16_t>&&)
        US us2(move(binary_value));
        REQUIRE(us2.Value() == us1.Value());
        REQUIRE(us2.Length() == 2);
        REQUIRE(us2.ByteLength() == 2 * sizeof(uint16_t));
        REQUIRE(binary_value.Empty());

        // US(uint16_t)
        US us3(5);
        REQUIRE(us3.Value()[0] == 5);
        REQUIRE(us3.Length() == 1);
        REQUIRE(us3.ByteLength() == 1 * sizeof(uint16_t));

        // US(const std::vector<uint16_t>&)
        vector<uint16_t> values;
        values.push_back(1);
        values.push_back(2);
        US us4(values);
        REQUIRE(us4.Value()[0] == 1);
        REQUIRE(us4.Value()[1] == 2);
        REQUIRE(us4.Length() == 2);
        REQUIRE(us4.ByteLength() == 2 * sizeof(uint16_t));
        
        // US(const US&)
        US us5(us4);
        REQUIRE(us5.Value() == us4.Value());
        REQUIRE(us5.Length() == 2);
        REQUIRE(us5.ByteLength() == 2 * sizeof(uint16_t));

        // US(US&&)
        US us6(move(us4));
        REQUIRE(us6.Value() == us5.Value());
        REQUIRE(us6.Length() == 2);
        REQUIRE(us6.ByteLength() == 2 * sizeof(uint16_t));
        REQUIRE(us4.Value().Empty());
        REQUIRE(us4.Length() == 0);
        REQUIRE(us4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, First) {
        US us1(1);
        REQUIRE(us1.First() == 1);

        buffer<uint16_t> binary_value(1);
        binary_value[0] = 3;
        US us2(binary_value);
        REQUIRE_EQUAL(us2.First(), 3);

        vector<uint16_t> values;
        values.push_back(2);
        US us3(values);
        REQUIRE_EQUAL(us3.First(), 2);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, Equality_SingleValue) {
        US us1(1);
        US us2(2);

        REQUIRE(us1 == &us1);
        REQUIRE(us1 != &us2);
        REQUIRE(us2 != &us1);

        REQUIRE(us1 <  &us2);
        REQUIRE(us1 <= &us2);
        REQUIRE(us2 >  &us1);
        REQUIRE(us2 >= &us1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, Equality_MultipleValue) {
        vector<uint16_t> tmp(2);
        US us1(tmp);
        US us2(tmp);

        us1.Value()[0] = us2.Value()[0] = 1;
        us1.Value()[1] = 1;
        us2.Value()[1] = 2;

        REQUIRE(us1 == &us1);
        REQUIRE(us1 != &us2);
        REQUIRE(us2 != &us1);

        REQUIRE(us1 <  &us2);
        REQUIRE(us1 <= &us2);
        REQUIRE(us2 >  &us1);
        REQUIRE(us2 >= &us1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, Equality_DifferentMultiplicity) {
        vector<uint16_t> tmp(2);
        US us1(1);
        US us2(tmp);

        us2.Value()[0] = us1.First();
        us2.Value()[1] = 1;

        REQUIRE(us1 == &us1);
        REQUIRE(us1 != &us2);
        REQUIRE(us2 != &us1);

        REQUIRE(us1 <  &us2);
        REQUIRE(us1 <= &us2);
        REQUIRE(us2 >  &us1);
        REQUIRE(us2 >= &us1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, Empty) {
        US us1;
        REQUIRE(us1.Empty());

        US us2(nullptr);
        REQUIRE(us2.Empty());

        US us3(1);
        REQUIRE(!us3.Empty());

        US us4(buffer<uint16_t>(1));
        REQUIRE(!us4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(USTest, Copy) {
        buffer<uint16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;

        US us_orig(binary_value);
        std::unique_ptr<VR> vr_copy(us_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto us_copy = dynamic_cast<US*>(vr_copy.get());
        REQUIRE(us_copy != nullptr);

        REQUIRE(us_orig.Value() == us_copy->Value());
        REQUIRE(us_orig == us_copy);
    }

}