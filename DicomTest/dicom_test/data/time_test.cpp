#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/time.h"
#include "dicom/data/value_invalid.h"

using namespace dicom;
using namespace dicom::data;
using dicom_time = dicom::data::time;

namespace {
    struct time_test {};
}

namespace dicom_test::data {

    TEST_CASE(time_test, Construction_Empty) {
        dicom_time empty;
        CHECK_FALSE(empty.IsValid());
        CHECK_EQUAL(empty.Precision(), TimePrecision::Hours);
        CHECK_EQUAL(empty.Hour(), 0u);
        CHECK_EQUAL(empty.Minute(), 0u);
        CHECK_EQUAL(empty.Second(), 0u);
        CHECK_EQUAL(empty.Millisecond(), 0u);
    }

    TEST_CASE(time_test, Construction_Zero) {
        dicom_time zero_h{ TimePrecision::Hours, 0 };
        CHECK(zero_h.IsValid());
        CHECK_EQUAL(zero_h.Precision(), TimePrecision::Hours);
        CHECK_EQUAL(zero_h.Hour(), 0u);
        CHECK_EQUAL(zero_h.Minute(), 0u);
        CHECK_EQUAL(zero_h.Second(), 0u);
        CHECK_EQUAL(zero_h.Millisecond(), 0u);

        dicom_time zero_m{ TimePrecision::Minutes, 0, 0 };
        CHECK(zero_m.IsValid());
        CHECK_EQUAL(zero_m.Precision(), TimePrecision::Minutes);
        CHECK_EQUAL(zero_m.Hour(), 0u);
        CHECK_EQUAL(zero_m.Minute(), 0u);
        CHECK_EQUAL(zero_m.Second(), 0u);
        CHECK_EQUAL(zero_m.Millisecond(), 0u);

        dicom_time zero_s{ TimePrecision::Seconds, 0, 0, 0 };
        CHECK(zero_s.IsValid());
        CHECK_EQUAL(zero_s.Precision(), TimePrecision::Seconds);
        CHECK_EQUAL(zero_s.Hour(), 0u);
        CHECK_EQUAL(zero_s.Minute(), 0u);
        CHECK_EQUAL(zero_s.Second(), 0u);
        CHECK_EQUAL(zero_s.Millisecond(), 0u);

        dicom_time zero_ms{ TimePrecision::Milliseconds, 0, 0, 0, 0 };
        CHECK(zero_ms.IsValid());
        CHECK_EQUAL(zero_ms.Precision(), TimePrecision::Milliseconds);
        CHECK_EQUAL(zero_ms.Hour(), 0u);
        CHECK_EQUAL(zero_ms.Minute(), 0u);
        CHECK_EQUAL(zero_ms.Second(), 0u);
        CHECK_EQUAL(zero_ms.Millisecond(), 0u);
    }

    TEST_CASE(time_test, Construction_Precision) {
        dicom_time h{ TimePrecision::Hours, 1 };
        CHECK(h.IsValid());
        CHECK_EQUAL(h.Precision(), TimePrecision::Hours);
        CHECK_EQUAL(h.Hour(), 1u);
        CHECK_EQUAL(h.Minute(), 0u);
        CHECK_EQUAL(h.Second(), 0u);
        CHECK_EQUAL(h.Millisecond(), 0u);

        dicom_time m{ TimePrecision::Minutes, 1, 2 };
        CHECK(m.IsValid());
        CHECK_EQUAL(m.Precision(), TimePrecision::Minutes);
        CHECK_EQUAL(m.Hour(), 1u);
        CHECK_EQUAL(m.Minute(), 2u);
        CHECK_EQUAL(m.Second(), 0u);
        CHECK_EQUAL(m.Millisecond(), 0u);

        dicom_time s{ TimePrecision::Seconds, 1, 2, 3 };
        CHECK(s.IsValid());
        CHECK_EQUAL(s.Precision(), TimePrecision::Seconds);
        CHECK_EQUAL(s.Hour(), 1u);
        CHECK_EQUAL(s.Minute(), 2u);
        CHECK_EQUAL(s.Second(), 3u);
        CHECK_EQUAL(s.Millisecond(), 0u);

        dicom_time ms{ TimePrecision::Milliseconds, 1, 2, 3, 4 };
        CHECK(ms.IsValid());
        CHECK_EQUAL(ms.Precision(), TimePrecision::Milliseconds);
        CHECK_EQUAL(ms.Hour(), 1u);
        CHECK_EQUAL(ms.Minute(), 2u);
        CHECK_EQUAL(ms.Second(), 3u);
        CHECK_EQUAL(ms.Millisecond(), 4u);
    }

    TEST_CASE(time_test, Compare_Empty) {
        dicom_time empty1;
        dicom_time empty2;

        CHECK(empty1 == empty2);
        CHECK(empty1 <= empty2);
        CHECK(empty1 >= empty2);
        CHECK_FALSE(empty1 != empty2);
        CHECK_FALSE(empty1 < empty2);
        CHECK_FALSE(empty1 > empty2);
    }

    TEST_CASE(time_test, Compare_Zero) {
        dicom_time empty;
        dicom_time zero1{ TimePrecision::Hours, 0 };
        dicom_time zero2{ TimePrecision::Hours, 0 };

        CHECK(empty != zero1);
        CHECK(empty < zero1);
        CHECK(empty <= zero1);
        CHECK_FALSE(empty == zero1);
        CHECK_FALSE(empty > zero1);
        CHECK_FALSE(empty >= zero1);

        CHECK(zero1 == zero2);
        CHECK(zero1 <= zero2);
        CHECK(zero1 >= zero2);
        CHECK_FALSE(zero1 != zero2);
        CHECK_FALSE(zero1 < zero2);
        CHECK_FALSE(zero1 > zero2);
    }

    TEST_CASE(time_test, Compare_NonZero) {
        dicom_time h{ TimePrecision::Hours, 1 };
        dicom_time m{ TimePrecision::Minutes, 1, 2 };
        dicom_time s{ TimePrecision::Seconds, 1, 2, 3 };
        dicom_time ms{ TimePrecision::Milliseconds, 1, 2, 3, 4 };

        CHECK(h != m);
        CHECK(h != s);
        CHECK(h != ms);
        CHECK(h < m);
        CHECK(h < s);
        CHECK(h < ms);
        CHECK(h <= m);
        CHECK(h <= s);
        CHECK(h <= ms);
        CHECK_FALSE(h == m);
        CHECK_FALSE(h == s);
        CHECK_FALSE(h == ms);
        CHECK_FALSE(h > m);
        CHECK_FALSE(h > s);
        CHECK_FALSE(h > ms);
        CHECK_FALSE(h >= m);
        CHECK_FALSE(h >= s);
        CHECK_FALSE(h >= ms);

        CHECK(m != s);
        CHECK(m != ms);
        CHECK(m < s);
        CHECK(m < ms);
        CHECK(m <= s);
        CHECK(m <= ms);
        CHECK_FALSE(m == s);
        CHECK_FALSE(m == ms);
        CHECK_FALSE(m > s);
        CHECK_FALSE(m > ms);
        CHECK_FALSE(m >= s);
        CHECK_FALSE(m >= ms);

        CHECK(s != ms);
        CHECK(s < ms);
        CHECK(s <= ms);
        CHECK_FALSE(s == ms);
        CHECK_FALSE(s > ms);
        CHECK_FALSE(s >= ms);
    }

    TEST_CASE(time_test, AsString) {
        dicom_time tm0;
        CHECK_THROW(value_invalid_error, UNUSED_RETURN(tm0.AsString()));

        dicom_time tm1(TimePrecision::Hours, 10);
        CHECK_EQUAL(tm1.AsString(), "10");

        dicom_time tm2(TimePrecision::Minutes, 10, 15);
        CHECK_EQUAL(tm2.AsString(), "1015");

        dicom_time tm3(TimePrecision::Seconds, 10, 15, 20);
        CHECK_EQUAL(tm3.AsString(), "101520");

        dicom_time tm4(TimePrecision::Milliseconds, 10, 15, 20, 123456);
        CHECK_EQUAL(tm4.AsString(), "101520.123456");
    }

}