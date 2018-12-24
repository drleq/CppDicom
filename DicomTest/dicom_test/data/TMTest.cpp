#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/TM.h"

using namespace dicom::data;

namespace {
    struct TMTest {};
}

namespace dicom_test::data {

    TEST_CASE(TMTest, Construction_Default) {
        TM tm0;
        CHECK_EQUAL(tm0.Validity(), ValidityType::Valid);
        CHECK_EQUAL(tm0.ParsedCount(), 0u);
        CHECK_EQUAL(tm0.Value(), "");
        CHECK(tm0.Parsed().empty());
        CHECK_THROW(value_empty_error, UNUSED_RETURN(tm0.First()));
        CHECK_THROW(value_empty_error, UNUSED_RETURN(tm0.At(0)));
    }

}