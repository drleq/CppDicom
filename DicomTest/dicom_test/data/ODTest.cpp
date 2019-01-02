#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/OD.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct ODTest {};
}

namespace dicom_test::data {

    TEST_CASE(ODTest, Construction) {
        // OD()
        OD od0;
        CHECK(od0.Value().Empty());
        CHECK(od0.Length() == 0);
        CHECK(od0.ByteLength() == 0);

        // OD(const buffer<double>&)
        buffer<double> binary_value(2);
        binary_value[0] = 1.0;
        binary_value[1] = 2.0;
        OD od1(binary_value);
        CHECK(od1.Value() == binary_value);
        CHECK(od1.Length() == 2);
        CHECK(od1.ByteLength() == 2 * sizeof(double));

        // OD(buffer<double>&&)
        OD od2(move(binary_value));
        CHECK(od2.Value() == od1.Value());
        CHECK(od2.Length() == 2);
        CHECK(od2.ByteLength() == 2 * sizeof(double));
        CHECK(binary_value.Empty());
        
        // OD(const OD&)
        OD od3(od2);
        CHECK(od3.Value() == od3.Value());
        CHECK(od3.Length() == 2);
        CHECK(od3.ByteLength() == 2 * sizeof(double));

        // OD(OD&&)
        OD od4(move(od3));
        CHECK(od4.Value() == od2.Value());
        CHECK(od4.Length() == 2);
        CHECK(od4.ByteLength() == 2 * sizeof(double));
        CHECK(od3.Value().Empty());
        CHECK(od3.Length() == 0);
        CHECK(od3.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ODTest, Equality_SingleValue) {
        OD od1({ 1.0 });
        OD od2({ 1.1 });

        CHECK(od1 == &od1);
        CHECK(od1 != &od2);
        CHECK(od2 != &od1);

        CHECK(od1 <  &od2);
        CHECK(od1 <= &od2);
        CHECK(od2 >  &od1);
        CHECK(od2 >= &od1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ODTest, Equality_MultipleValue) {
        OD od1({ 1.0, 1.0 });
        OD od2({ 1.0, 1.1 });

        CHECK(od1 == &od1);
        CHECK(od1 != &od2);
        CHECK(od2 != &od1);

        CHECK(od1 <  &od2);
        CHECK(od1 <= &od2);
        CHECK(od2 >  &od1);
        CHECK(od2 >= &od1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ODTest, Equality_DifferentMultiplicity) {
        OD od1({ 1.0 });
        OD od2({ 1.0, 1.0 });

        CHECK(od1 == &od1);
        CHECK(od1 != &od2);
        CHECK(od2 != &od1);

        CHECK(od1 <  &od2);
        CHECK(od1 <= &od2);
        CHECK(od2 >  &od1);
        CHECK(od2 >= &od1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ODTest, Empty) {
        OD od1;
        CHECK(od1.Empty());

        OD od2(nullptr);
        CHECK(od2.Empty());

        OD od4(buffer<double>(1));
        CHECK(!od4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(ODTest, Copy) {
        buffer<double> binary_value(2);
        binary_value[0] = 1;
        binary_value[1] = -2;

        OD od_orig(binary_value);
        std::unique_ptr<VR> vr_copy(od_orig.Copy());
        CHECK(static_cast<bool>(vr_copy));

        auto od_copy = dynamic_cast<OD*>(vr_copy.get());
        CHECK(od_copy != nullptr);

        CHECK(od_orig.Value() == od_copy->Value());
        CHECK(od_orig == od_copy);
    }

}