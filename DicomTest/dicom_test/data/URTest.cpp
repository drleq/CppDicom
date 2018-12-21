#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/UR.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct URTest {};
}

namespace dicom_test::data {

    TEST_CASE(URTest, Construction) {
        // UR()
        UR ur0;
        REQUIRE(ur0.Empty());

        // UR(const uri&)
        uri value("http://localhost:1234/ping");
        UR ur1(value);
        REQUIRE(!ur1.Empty());
        REQUIRE_EQUAL(ur1.Value(), value);

        // UR(uri&&)
        UR ur2(move(value));
        REQUIRE(!ur2.Empty());
        REQUIRE_EQUAL(ur2.Value(), ur1.Value());
        REQUIRE(value.Value().empty());

        // UR(const UR&)
        UR ur3(ur2);
        REQUIRE(!ur3.Empty());
        REQUIRE_EQUAL(ur3.Value(), ur2.Value());

        // UR(UR&&)
        UR ur4(move(ur2));
        REQUIRE(!ur4.Empty());
        REQUIRE_EQUAL(ur4.Value(), ur3.Value());
        REQUIRE(ur2.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(URTest, Equality_SingleValue) {
        UR ur1("http://localhost:1234/ping1");
        UR ur2("http://localhost:1234/ping2");

        REQUIRE(ur1 == &ur1);
        REQUIRE(ur1 != &ur2);
        REQUIRE(ur2 != &ur1);

        REQUIRE(ur1 <  &ur2);
        REQUIRE(ur1 <= &ur2);
        REQUIRE(ur2 >  &ur1);
        REQUIRE(ur2 >= &ur1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(URTest, Empty) {
        UR ur1;
        REQUIRE(ur1.Empty());

        UR ur2{uri{}};
        REQUIRE(ur2.Empty());

        UR ur3("http://localhost:1234/ping");
        REQUIRE(!ur3.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(URTest, Copy) {
        uri value("http://localhost:1234/ping");

        UR us_orig(value);
        std::unique_ptr<VR> vr_copy(us_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto us_copy = dynamic_cast<UR*>(vr_copy.get());
        REQUIRE(us_copy != nullptr);

        REQUIRE(us_orig.Value() == us_copy->Value());
        REQUIRE(us_orig == us_copy);
    }

}