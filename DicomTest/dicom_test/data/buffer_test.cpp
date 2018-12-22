#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/buffer.h"

using namespace dicom::data;

namespace {
    struct buffer_test {};
}

namespace dicom_test::data {

    TEST_CASE(buffer_test, Constructors) {
        // buffer()
        buffer<char> b0;
        CHECK(b0.Empty());
        CHECK_EQUAL(b0.Length(), 0u);
        CHECK_EQUAL(b0.ByteLength(), 0u);
        CHECK(b0.Get() == nullptr);
        CHECK(static_cast<char*>(b0) == nullptr);

        // buffer(size_t)
        buffer<char> b1(10);
        CHECK(!b1.Empty());
        CHECK_EQUAL(b1.Length(), 10u);
        CHECK_EQUAL(b1.ByteLength(), 10u);
        CHECK(b1.Get() != nullptr);
        CHECK(static_cast<char*>(b1) != nullptr);

        // buffer(T*, size_t)
        buffer<char> b2(b1.Get(), b1.Length());
        CHECK(!b2.Empty());
        CHECK_EQUAL(b2.Length(), 10u);
        CHECK_EQUAL(b2.ByteLength(), 10u);
        CHECK(b2.Get() != nullptr);
        CHECK(static_cast<char*>(b2) != nullptr);

        // buffer(std::initializer_list<>)
        buffer<char> b3({ 10, 20, 30 });
        CHECK(!b3.Empty());
        CHECK_EQUAL(b3.Length(), 3u);
        CHECK_EQUAL(b3.ByteLength(), 3u);
        CHECK(b3.Get() != nullptr);
        CHECK(static_cast<char*>(b3) != nullptr);
        CHECK(b3[0] == 10);
        CHECK(b3[1] == 20);
        CHECK(b3[2] == 30);

        // buffer(buffer&&)
        buffer<char> b4(std::move(b1));
        CHECK(!b4.Empty());
        CHECK_EQUAL(b4.Length(), 10u);
        CHECK_EQUAL(b4.ByteLength(), 10u);
        CHECK(b4.Get() != nullptr);
        CHECK(static_cast<char*>(b4) != nullptr);

        // buffer(buffer<U>&&)
        buffer<short> b5(std::move(b4));
        CHECK(!b5.Empty());
        CHECK_EQUAL(b5.Length(), 5u);
        CHECK_EQUAL(b5.ByteLength(), 10u);
        CHECK(b5.Get() != nullptr);
        CHECK(static_cast<short*>(b5) != nullptr);

        buffer<char> b6(std::move(b5));
        CHECK(!b6.Empty());
        CHECK_EQUAL(b6.Length(), 10u);
        CHECK_EQUAL(b6.ByteLength(), 10u);
        CHECK(b6.Get() != nullptr);
        CHECK(static_cast<char*>(b6) != nullptr);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(buffer_test, MoveAssignment) {
        buffer<char> b0(10);
        buffer<char> b1 = std::move(b0);

        CHECK(b0.Empty());
        CHECK_EQUAL(b0.Length(), 0u);
        CHECK_EQUAL(b0.ByteLength(), 0u);
        CHECK(b0.Get() == nullptr);
        CHECK(static_cast<char*>(b0) == nullptr);

        CHECK(!b1.Empty());
        CHECK_EQUAL(b1.Length(), 10u);
        CHECK_EQUAL(b1.ByteLength(), 10u);
        CHECK(b1.Get() != nullptr);
        CHECK(static_cast<char*>(b1) != nullptr);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(buffer_test, Compare_SameLength) {
        char a[2] = { 1, 2 };
        char b[2] = { 1, 2 };
        buffer<char> buf_a(a, 2);
        buffer<char> buf_b(b, 2);

        CHECK_EQUAL(buf_a.Compare(buf_b), 0);
        CHECK_EQUAL(buf_b.Compare(buf_a), 0);

        a[1] = 3;
        CHECK_EQUAL(buf_a.Compare(buf_b), 1);
        CHECK_EQUAL(buf_b.Compare(buf_a), -1);

        b[0] = 2;
        CHECK_EQUAL(buf_a.Compare(buf_b), -1);
        CHECK_EQUAL(buf_b.Compare(buf_a), 1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(buffer_test, Compare_DifferentLength) {
        char a[2] = { 1, 2 };
        char b[3] = { 1, 2, 3 };
        buffer<char> buf_a(a, 2);
        buffer<char> buf_b(b, 3);

        CHECK_EQUAL(buf_a.Compare(buf_b), -1);
        CHECK_EQUAL(buf_b.Compare(buf_a), 1);

        a[1] = 3;
        CHECK_EQUAL(buf_a.Compare(buf_b), 1);
        CHECK_EQUAL(buf_b.Compare(buf_a), -1);

        b[0] = 2;
        CHECK_EQUAL(buf_a.Compare(buf_b), -1);
        CHECK_EQUAL(buf_b.Compare(buf_a), 1);
    }

    //------------------------------------------------------------------------------------------------------------

    TEST_CASE(buffer_test, Copy) {
        char data[3] = { 1, 2, 3 };
        buffer<char> buf(data, 3);

        buffer<char> copy = buf.Copy();
        CHECK(copy == buf);
    }

}