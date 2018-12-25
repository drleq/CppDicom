#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/SS.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct SSTest {};
}

namespace dicom_test::data {

    TEST_CASE(SSTest, Construction) {
        // SS()
        SS ss0;
        CHECK(ss0.Value().Empty());
        CHECK(ss0.Length() == 0);
        CHECK(ss0.ByteLength() == 0);

        // SS(const buffer<int16_t>&)
        buffer<int16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        SS ss1(binary_value);
        CHECK(ss1.Value() == binary_value);
        CHECK(ss1.Length() == 2);
        CHECK(ss1.ByteLength() == 2 * sizeof(int16_t));

        // SS(buffer<int16_t>&&)
        SS ss2(move(binary_value));
        CHECK(ss2.Value() == ss1.Value());
        CHECK(ss2.Length() == 2);
        CHECK(ss2.ByteLength() == 2 * sizeof(int16_t));
        CHECK(binary_value.Empty());

        // SS(int16_t)
        SS ss3(5);
        CHECK(ss3.Value()[0] == 5);
        CHECK(ss3.Length() == 1);
        CHECK(ss3.ByteLength() == 1 * sizeof(int16_t));

        // SS(const std::vector<int16_t>&)
        vector<int16_t> values;
        values.push_back(1);
        values.push_back(2);
        SS ss4(values);
        CHECK(ss4.Value()[0] == 1);
        CHECK(ss4.Value()[1] == 2);
        CHECK(ss4.Length() == 2);
        CHECK(ss4.ByteLength() == 2 * sizeof(int16_t));
        
        // SS(const SS&)
        SS ss5(ss4);
        CHECK(ss5.Value() == ss4.Value());
        CHECK(ss5.Length() == 2);
        CHECK(ss5.ByteLength() == 2 * sizeof(int16_t));

        // SS(SS&&)
        SS ss6(move(ss4));
        CHECK(ss6.Value() == ss5.Value());
        CHECK(ss6.Length() == 2);
        CHECK(ss6.ByteLength() == 2 * sizeof(int16_t));
        CHECK(ss4.Value().Empty());
        CHECK(ss4.Length() == 0);
        CHECK(ss4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, First) {
        SS ss1(1);
        CHECK(ss1.First() == 1);

        buffer<int16_t> binary_value(1);
        binary_value[0] = 3;
        SS ss2(binary_value);
        CHECK_EQUAL(ss2.First(), 3);

        vector<int16_t> values;
        values.push_back(-2);
        SS ss3(values);
        CHECK_EQUAL(ss3.First(), -2);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, Equality_SingleValue) {
        SS ss1(1);
        SS ss2(2);

        CHECK(ss1 == &ss1);
        CHECK(ss1 != &ss2);
        CHECK(ss2 != &ss1);

        CHECK(ss1 <  &ss2);
        CHECK(ss1 <= &ss2);
        CHECK(ss2 >  &ss1);
        CHECK(ss2 >= &ss1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, Equality_MultipleValue) {
        SS ss1({ 1, 1 });
        SS ss2({ 1, 2 });

        CHECK(ss1 == &ss1);
        CHECK(ss1 != &ss2);
        CHECK(ss2 != &ss1);

        CHECK(ss1 <  &ss2);
        CHECK(ss1 <= &ss2);
        CHECK(ss2 >  &ss1);
        CHECK(ss2 >= &ss1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, Equality_DifferentMultiplicity) {
        SS ss1(1);
        SS ss2({ 1, 1 });

        CHECK(ss1 == &ss1);
        CHECK(ss1 != &ss2);
        CHECK(ss2 != &ss1);

        CHECK(ss1 <  &ss2);
        CHECK(ss1 <= &ss2);
        CHECK(ss2 >  &ss1);
        CHECK(ss2 >= &ss1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, Empty) {
        SS ss1;
        CHECK(ss1.Empty());

        SS ss2(nullptr);
        CHECK(ss2.Empty());

        SS ss3(1.0);
        CHECK(!ss3.Empty());

        SS ss4(buffer<int16_t>(1));
        CHECK(!ss4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(SSTest, Copy) {
        buffer<int16_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        SS ss_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ss_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto ss_copy = dynamic_cast<SS*>(vr_copy.get());
        CHECK(ss_copy != nullptr);

        CHECK(ss_orig.Value() == ss_copy->Value());
        CHECK(ss_orig == ss_copy);
    }

}