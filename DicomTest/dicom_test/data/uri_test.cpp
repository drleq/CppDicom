#include "dicomtest_pch.h"

#include "CppUnitTestFramework.hpp"
#include "dicom/data/uri.h"

using namespace dicom::data;

namespace {
    struct uri_test {};
}

namespace dicom_test::data {

    TEST_CASE(uri_test, Constructors) {
        // uri()
        uri u0;
        CHECK(u0.Validity() == ValidityType::Uninitialized);
        CHECK(u0.Value().empty());
        CHECK(!u0.Scheme());
        CHECK(!u0.Authentication());
        CHECK(!u0.Host());
        CHECK(!u0.Port());
        CHECK(!u0.Path());
        CHECK(!u0.Query());
        CHECK(!u0.Fragment());

        const char*const TestUri = "http://bobby:tables@example.com:1234/my/path?id=1&seq=2#PageMarker";

        // uri(const string_view&, bool)
        uri u1{ std::string_view(TestUri) };
        CHECK_EQUAL(u1.Validity(), ValidityType::Valid);
        CHECK_EQUAL(u1.Value(), TestUri);
        CHECK_EQUAL(*u1.Scheme(), "http");
        CHECK_EQUAL(*u1.Authentication(), "bobby:tables");
        CHECK_EQUAL(*u1.Host(), "example.com");
        CHECK_EQUAL(*u1.Port(), "1234");
        CHECK_EQUAL(*u1.Path(), "/my/path");
        CHECK_EQUAL(*u1.Query(), "id=1&seq=2");
        CHECK_EQUAL(*u1.Fragment(), "PageMarker");

        // uri(string&&, bool)
        uri u2{ std::string(TestUri) };
        CHECK_EQUAL(u2.Validity(), ValidityType::Valid);
        CHECK_EQUAL(u2.Value(), TestUri);
        CHECK_EQUAL(*u2.Scheme(), "http");
        CHECK_EQUAL(*u2.Authentication(), "bobby:tables");
        CHECK_EQUAL(*u2.Host(), "example.com");
        CHECK_EQUAL(*u2.Port(), "1234");
        CHECK_EQUAL(*u2.Path(), "/my/path");
        CHECK_EQUAL(*u2.Query(), "id=1&seq=2");
        CHECK_EQUAL(*u2.Fragment(), "PageMarker");

        //uri(
        //    const std::string_view& scheme,
        //    const std::string_view& path,
        //    const optional_section& host = optional_section(),
        //    const optional_section& port = optional_section(),
        //    const optional_section& authentication = optional_section(),
        //    const optional_section& query = optional_section(),
        //    const optional_section& fragment = optional_section()
        //)
        uri u3(
            "http",
            "/my/path",
            "example.com",
            "1234",
            "bobby:tables",
            "id=1&seq=2",
            "PageMarker"
        );
        CHECK_EQUAL(u3.Validity(), ValidityType::Valid);
        CHECK_EQUAL(u3.Value(), TestUri);
        CHECK_EQUAL(*u3.Scheme(), "http");
        CHECK_EQUAL(*u3.Authentication(), "bobby:tables");
        CHECK_EQUAL(*u3.Host(), "example.com");
        CHECK_EQUAL(*u3.Port(), "1234");
        CHECK_EQUAL(*u3.Path(), "/my/path");
        CHECK_EQUAL(*u3.Query(), "id=1&seq=2");
        CHECK_EQUAL(*u3.Fragment(), "PageMarker");

        // uri(const uri&)
        uri u4(u3);
        CHECK_EQUAL(u4.Validity(), u3.Validity());
        CHECK_EQUAL(u4.Value(), u3.Value());
        CHECK_EQUAL(*u4.Scheme(), *u3.Scheme());
        CHECK_EQUAL(*u4.Authentication(), *u3.Authentication());
        CHECK_EQUAL(*u4.Host(), *u3.Host());
        CHECK_EQUAL(*u4.Port(), *u3.Port());
        CHECK_EQUAL(*u4.Path(), *u3.Path());
        CHECK_EQUAL(*u4.Query(), *u3.Query());
        CHECK_EQUAL(*u4.Fragment(), *u3.Fragment());

        // uri(uri&&)
        uri u5(std::move(u4));
        CHECK_EQUAL(u5.Validity(), u3.Validity());
        CHECK_EQUAL(u5.Value(), u3.Value());
        CHECK_EQUAL(*u5.Scheme(), *u3.Scheme());
        CHECK_EQUAL(*u5.Authentication(), *u3.Authentication());
        CHECK_EQUAL(*u5.Host(), *u3.Host());
        CHECK_EQUAL(*u5.Port(), *u3.Port());
        CHECK_EQUAL(*u5.Path(), *u3.Path());
        CHECK_EQUAL(*u5.Query(), *u3.Query());
        CHECK_EQUAL(*u5.Fragment(), *u3.Fragment());
        CHECK_EQUAL(u4.Validity(), ValidityType::Deinitialized);
        CHECK(u4.Value().empty());
        CHECK(!u4.Scheme());
        CHECK(!u4.Authentication());
        CHECK(!u4.Host());
        CHECK(!u4.Port());
        CHECK(!u4.Path());
        CHECK(!u4.Query());
        CHECK(!u4.Fragment());
    }

}