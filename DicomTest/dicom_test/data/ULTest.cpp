#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UL.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct ULTest {};
}

namespace dicom_test::data {

    TEST_CASE(ULTest, Construction) {
        // UL()
        UL ul0;
        REQUIRE(ul0.Value().Empty());
        REQUIRE(ul0.Length() == 0);
        REQUIRE(ul0.ByteLength() == 0);

        // UL(const buffer<uint32_t>&)
        buffer<uint32_t> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = 2;
        UL ul1(binary_value);
        REQUIRE(ul1.Value() == binary_value);
        REQUIRE(ul1.Length() == 2);
        REQUIRE(ul1.ByteLength() == 2 * sizeof(uint32_t));

        // UL(buffer<uint32_t>&&)
        UL ul2(move(binary_value));
        REQUIRE(ul2.Value() == ul1.Value());
        REQUIRE(ul2.Length() == 2);
        REQUIRE(ul2.ByteLength() == 2 * sizeof(uint32_t));
        REQUIRE(binary_value.Empty());

        // UL(uint32_t)
        UL ul3(5);
        REQUIRE(ul3.Value()[0] == 5);
        REQUIRE(ul3.Length() == 1);
        REQUIRE(ul3.ByteLength() == 1 * sizeof(uint32_t));

        // UL(const std::vector<uint32_t>&)
        vector<uint32_t> values;
        values.push_back(1);
        values.push_back(2);
        UL ul4(values);
        REQUIRE(ul4.Value()[0] == 1);
        REQUIRE(ul4.Value()[1] == 2);
        REQUIRE(ul4.Length() == 2);
        REQUIRE(ul4.ByteLength() == 2 * sizeof(uint32_t));
        
        // UL(const UL&)
        UL ul5(ul4);
        REQUIRE(ul5.Value() == ul4.Value());
        REQUIRE(ul5.Length() == 2);
        REQUIRE(ul5.ByteLength() == 2 * sizeof(uint32_t));

        // UL(UL&&)
        UL ul6(move(ul4));
        REQUIRE(ul6.Value() == ul5.Value());
        REQUIRE(ul6.Length() == 2);
        REQUIRE(ul6.ByteLength() == 2 * sizeof(uint32_t));
        REQUIRE(ul4.Value().Empty());
        REQUIRE(ul4.Length() == 0);
        REQUIRE(ul4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, First) {
        UL ul1(1);
        REQUIRE(ul1.First() == 1);

        buffer<uint32_t> binary_value({ 3 });
        UL ul2(binary_value);
        REQUIRE_EQUAL(ul2.First(), 3u);

        vector<uint32_t> values = { 2 };
        UL ul3(values);
        REQUIRE_EQUAL(ul3.First(), 2u);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, Equality_SingleValue) {
        UL ul1(1);
        UL ul2(2);

        REQUIRE(ul1 == &ul1);
        REQUIRE(ul1 != &ul2);
        REQUIRE(ul2 != &ul1);

        REQUIRE(ul1 <  &ul2);
        REQUIRE(ul1 <= &ul2);
        REQUIRE(ul2 >  &ul1);
        REQUIRE(ul2 >= &ul1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, Equality_MultipleValue) {
        UL ul1({ 1, 1 });
        UL ul2({ 1, 2 });

        REQUIRE(ul1 == &ul1);
        REQUIRE(ul1 != &ul2);
        REQUIRE(ul2 != &ul1);

        REQUIRE(ul1 <  &ul2);
        REQUIRE(ul1 <= &ul2);
        REQUIRE(ul2 >  &ul1);
        REQUIRE(ul2 >= &ul1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, Equality_DifferentMultiplicity) {
        UL ul1({ 1 });
        UL ul2({ 1, 2 });

        REQUIRE(ul1 == &ul1);
        REQUIRE(ul1 != &ul2);
        REQUIRE(ul2 != &ul1);

        REQUIRE(ul1 <  &ul2);
        REQUIRE(ul1 <= &ul2);
        REQUIRE(ul2 >  &ul1);
        REQUIRE(ul2 >= &ul1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, Empty) {
        UL ul1;
        REQUIRE(ul1.Empty());

        UL ul2(nullptr);
        REQUIRE(ul2.Empty());

        UL ul3(1);
        REQUIRE(!ul3.Empty());

        UL ul4(buffer<uint32_t>({ 1 }));
        REQUIRE(!ul4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ULTest, Copy) {
        buffer<uint32_t> binary_value({ 1, 2 });

        UL ul_orig(binary_value);
        std::unique_ptr<VR> vr_copy(ul_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto un_copy = dynamic_cast<UL*>(vr_copy.get());
        REQUIRE(un_copy != nullptr);

        REQUIRE(ul_orig.Value() == un_copy->Value());
        REQUIRE(ul_orig == un_copy);
    }

}