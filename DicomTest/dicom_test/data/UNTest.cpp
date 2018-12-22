#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UN.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct UNTest {};
}

namespace dicom_test::data {

    TEST_CASE(UNTest, Construction) {
        // UN()
        UN un0;
        REQUIRE(un0.Value().Empty());

        // UN(const buffer<int8_t>&)
        buffer<int8_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        UN un1(binary_value);
        REQUIRE(un1.Value() == binary_value);

        // UN(buffer<int8_t>&&)
        UN un2(move(binary_value));
        REQUIRE(un2.Value() == un1.Value());
        REQUIRE(binary_value.Empty());

        // UN(const UN&)
        UN un3(un2);
        REQUIRE(un3.Value() == un2.Value());

        // UN(UN&&)
        UN un4(move(un2));
        REQUIRE(un4.Value() == un3.Value());
        REQUIRE(un2.Value().Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UNTest, Equality_SingleValue) {
        UN un1({ 1 });
        UN un2({ 2 });

        REQUIRE(un1 == &un1);
        REQUIRE(un1 != &un2);
        REQUIRE(un2 != &un1);

        REQUIRE(un1 <  &un2);
        REQUIRE(un1 <= &un2);
        REQUIRE(un2 >  &un1);
        REQUIRE(un2 >= &un1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UNTest, Equality_MultipleValue) {
        UN un1({ 1, 1 });
        UN un2({ 1, 2 });

        REQUIRE(un1 == &un1);
        REQUIRE(un1 != &un2);
        REQUIRE(un2 != &un1);

        REQUIRE(un1 <  &un2);
        REQUIRE(un1 <= &un2);
        REQUIRE(un2 >  &un1);
        REQUIRE(un2 >= &un1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UNTest, Equality_DifferentMultiplicity) {
        UN un1({ 1 });
        UN un2({ 1, 1 });

        REQUIRE(un1 == &un1);
        REQUIRE(un1 != &un2);
        REQUIRE(un2 != &un1);

        REQUIRE(un1 <  &un2);
        REQUIRE(un1 <= &un2);
        REQUIRE(un2 >  &un1);
        REQUIRE(un2 >= &un1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UNTest, Empty) {
        UN un1;
        REQUIRE(un1.Empty());

        UN un2(nullptr);
        REQUIRE(un2.Empty());

        UN un3({ 1 });
        REQUIRE(!un3.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(UNTest, Copy) {
        buffer<int8_t> binary_value{ 1, 2 };

        UN un_orig(binary_value);
        std::unique_ptr<VR> vr_copy(un_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto un_copy = dynamic_cast<UN*>(vr_copy.get());
        REQUIRE(un_copy != nullptr);

        REQUIRE(un_orig.Value() == un_copy->Value());
        REQUIRE(un_orig == un_copy);
    }

}