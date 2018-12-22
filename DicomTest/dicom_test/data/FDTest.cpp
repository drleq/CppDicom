#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/FD.h"
#include "dicom/Tags.h"
#include "dicom_test/data/detail/constants.h"

using namespace std;
using namespace dicom;
using namespace dicom::data;

namespace {
    struct FDTest {};
}

namespace dicom_test::data {

    TEST_CASE(FDTest, Construction) {
        // FD()
        FD fd0;
        REQUIRE(fd0.Value().Empty());
        REQUIRE(fd0.Length() == 0);
        REQUIRE(fd0.ByteLength() == 0);

        // FD(const buffer<double>&)
        buffer<double> binary_value(2);
        binary_value[0] = 1.0;
        binary_value[1] = 2.0;
        FD fd1(binary_value);
        REQUIRE(fd1.Value() == binary_value);
        REQUIRE(fd1.Length() == 2);
        REQUIRE(fd1.ByteLength() == 2 * sizeof(double));

        // FD(buffer<double>&&)
        FD fd2(move(binary_value));
        REQUIRE(fd2.Value() == fd1.Value());
        REQUIRE(fd2.Length() == 2);
        REQUIRE(fd2.ByteLength() == 2 * sizeof(double));
        REQUIRE(binary_value.Empty());

        // FD(double)
        FD fd3(5.2);
        REQUIRE(fd3.Value()[0] == 5.2);
        REQUIRE(fd3.Length() == 1);
        REQUIRE(fd3.ByteLength() == 1 * sizeof(double));

        // FD(const std::vector<double>&)
        vector<double> values;
        values.push_back(1.0);
        values.push_back(2.0);
        FD fd4(values);
        REQUIRE(fd4.Value()[0] == 1.0);
        REQUIRE(fd4.Value()[1] == 2.0);
        REQUIRE(fd4.Length() == 2);
        REQUIRE(fd4.ByteLength() == 2 * sizeof(double));
        
        // FD(const FD&)
        FD fd5(fd4);
        REQUIRE(fd5.Value() == fd4.Value());
        REQUIRE(fd5.Length() == 2);
        REQUIRE(fd5.ByteLength() == 2 * sizeof(double));

        // FD(FD&&)
        FD fd6(move(fd4));
        REQUIRE(fd6.Value() == fd5.Value());
        REQUIRE(fd6.Length() == 2);
        REQUIRE(fd6.ByteLength() == 2 * sizeof(double));
        REQUIRE(fd4.Value().Empty());
        REQUIRE(fd4.Length() == 0);
        REQUIRE(fd4.ByteLength() == 0);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, First) {
        FD fd1(1.0);
        REQUIRE(fd1.First() == 1.0);

        buffer<double> binary_value(1);
        binary_value[0] = 3.0;
        FD fd2(binary_value);
        REQUIRE_EQUAL(fd2.First(), 3.0);

        vector<double> values;
        values.push_back(-2.5);
        FD fd3(values);
        REQUIRE_EQUAL(fd3.First(), -2.5);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, Equality_SingleValue) {
        FD fd1(1.0);
        FD fd2(1.1);

        REQUIRE(fd1 == &fd1);
        REQUIRE(fd1 != &fd2);
        REQUIRE(fd2 != &fd1);

        REQUIRE(fd1 <  &fd2);
        REQUIRE(fd1 <= &fd2);
        REQUIRE(fd2 >  &fd1);
        REQUIRE(fd2 >= &fd1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, Equality_MultipleValue) {
        vector<double> tmp(2);
        FD fd1(tmp);
        FD fd2(tmp);

        fd1.Value()[0] = fd2.Value()[0] = 1.0;
        fd1.Value()[1] = 1.0;
        fd2.Value()[1] = 1.1;

        REQUIRE(fd1 == &fd1);
        REQUIRE(fd1 != &fd2);
        REQUIRE(fd2 != &fd1);

        REQUIRE(fd1 <  &fd2);
        REQUIRE(fd1 <= &fd2);
        REQUIRE(fd2 >  &fd1);
        REQUIRE(fd2 >= &fd1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, Equality_DifferentMultiplicity) {
        vector<double> tmp(2);
        FD fd1(1.0);
        FD fd2(tmp);

        fd2.Value()[0] = fd1.First();
        fd2.Value()[1] = 1.1;

        REQUIRE(fd1 == &fd1);
        REQUIRE(fd1 != &fd2);
        REQUIRE(fd2 != &fd1);

        REQUIRE(fd1 <  &fd2);
        REQUIRE(fd1 <= &fd2);
        REQUIRE(fd2 >  &fd1);
        REQUIRE(fd2 >= &fd1);
    }
    
    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, Empty) {
        FD fd1;
        REQUIRE(fd1.Empty());

        FD fd2(nullptr);
        REQUIRE(fd2.Empty());

        FD fd3(1.0);
        REQUIRE(!fd3.Empty());

        FD fd4(buffer<double>(1));
        REQUIRE(!fd4.Empty());
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(FDTest, Copy) {
        buffer<double> binary_value(2);
        binary_value[0] = 1.0;
        binary_value[1] = -2.0;

        FD fd_orig(binary_value);
        std::unique_ptr<VR> vr_copy(fd_orig.Copy());
        REQUIRE(static_cast<bool>(vr_copy));

        auto fd_copy = dynamic_cast<FD*>(vr_copy.get());
        REQUIRE(fd_copy != nullptr);

        REQUIRE(fd_orig.Value() == fd_copy->Value());
        REQUIRE(fd_orig == fd_copy);
    }

}