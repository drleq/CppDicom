#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/time_offset.h"

using namespace dicom;
using namespace dicom::data;

namespace {
    struct time_offset_test {};
}

namespace dicom_test::data {

    TEST_CASE(time_offset_test, Construction) {
        time_offset empty;
        CHECK_FALSE(empty.IsValid());
        CHECK_FALSE(empty.IsNegative());
        CHECK_EQUAL(empty.Hour(), 0u);
        CHECK_EQUAL(empty.Minute(), 0u);

        time_offset zero{ 0, 0 };
        CHECK(zero.IsValid());
        CHECK_FALSE(zero.IsNegative());
        CHECK_EQUAL(zero.Hour(), 0u);
        CHECK_EQUAL(zero.Minute(), 0u);

        time_offset zero_neg{ 0, 0, true };
        CHECK(zero_neg.IsValid());
        CHECK(zero_neg.IsNegative());
        CHECK_EQUAL(zero_neg.Hour(), 0u);
        CHECK_EQUAL(zero_neg.Minute(), 0u);

        time_offset positive{ 2, 30 };
        CHECK(positive.IsValid());
        CHECK_FALSE(positive.IsNegative());
        CHECK_EQUAL(positive.Hour(), 2u);
        CHECK_EQUAL(positive.Minute(), 30u);

        time_offset negative{ 2, 30, true };
        CHECK(negative.IsValid());
        CHECK(negative.IsNegative());
        CHECK_EQUAL(negative.Hour(), 2u);
        CHECK_EQUAL(negative.Minute(), 30u);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(time_offset_test, Construction_Invalid) {
        time_offset valid_hour{ 23, 0 };
        time_offset invalid_hour{ 24, 0 };
        CHECK(valid_hour.IsValid());
        CHECK_FALSE(invalid_hour.IsValid());

        time_offset valid_minute{ 0, 59 };
        time_offset invalid_minute{ 0, 60 };
        CHECK(valid_minute.IsValid());
        CHECK_FALSE(invalid_minute.IsValid());
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(time_offset_test, Compare_Empty) {
        time_offset empty1;
        time_offset empty2;

        CHECK_EQUAL(empty1.Compare(empty2), 0);
        CHECK(empty1 == empty2);
        CHECK(empty1 <= empty2);
        CHECK(empty1 >= empty2);
        CHECK_FALSE(empty1 != empty2);
        CHECK_FALSE(empty1 < empty2);
        CHECK_FALSE(empty1 > empty2);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(time_offset_test, Compare_BothPositive) {
        time_offset pos1{ 0, 0 };
        time_offset pos2{ 2, 30 };

        CHECK(pos1.Compare(pos2) < 0);
        CHECK(pos1 != pos2);
        CHECK(pos1 < pos2);
        CHECK(pos1 <= pos2);
        CHECK_FALSE(pos1 == pos2);
        CHECK_FALSE(pos1 > pos2);
        CHECK_FALSE(pos1 >= pos2);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(time_offset_test, Compare_BothNegative) {
        time_offset neg1{ 0, 0, true };
        time_offset neg2{ 2, 30, true };

        CHECK(neg1.Compare(neg2) > 0);
        CHECK(neg1 != neg2);
        CHECK(neg1 > neg2);
        CHECK(neg1 >= neg2);
        CHECK_FALSE(neg1 == neg2);
        CHECK_FALSE(neg1 < neg2);
        CHECK_FALSE(neg1 <= neg2);
    }

    //--------------------------------------------------------------------------------------------------------

    TEST_CASE(time_offset_test, Compare_Mixed) {
        time_offset pos{ 2, 30, false };
        time_offset neg{ 2, 30, true };

        CHECK(pos.Compare(neg) > 0);
        CHECK(pos != neg);
        CHECK(pos > neg);
        CHECK(pos >= neg);
        CHECK_FALSE(pos == neg);
        CHECK_FALSE(pos < neg);
        CHECK_FALSE(pos <= neg);
    }

}