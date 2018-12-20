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
        CHECK(u1.Validity() == ValidityType::Valid);
        CHECK(u1.Value() == TestUri);
        CHECK(*u1.Scheme() == "http");
        CHECK(*u1.Authentication() == "bobby:tables");
        CHECK(*u1.Host() == "example.com");
        CHECK(*u1.Port() == "1234");
        CHECK(*u1.Path() == "/my/path");
        CHECK(*u1.Query() == "id=1&seq=2");
        CHECK(*u1.Fragment() == "PageMarker");

        // uri(string&&, bool)
        uri u2{ std::string(TestUri) };
        CHECK(u2.Validity() == ValidityType::Valid);
        CHECK(u2.Value() == TestUri);
        CHECK(*u2.Scheme() == "http");
        CHECK(*u2.Authentication() == "bobby:tables");
        CHECK(*u2.Host() == "example.com");
        CHECK(*u2.Port() == "1234");
        CHECK(*u2.Path() == "/my/path");
        CHECK(*u2.Query() == "id=1&seq=2");
        CHECK(*u2.Fragment() == "PageMarker");

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
        CHECK(u3.Validity() == ValidityType::Valid);
        CHECK(u3.Value() == TestUri);
        CHECK(*u3.Scheme() == "http");
        CHECK(*u3.Authentication() == "bobby:tables");
        CHECK(*u3.Host() == "example.com");
        CHECK(*u3.Port() == "1234");
        CHECK(*u3.Path() == "/my/path");
        CHECK(*u3.Query() == "id=1&seq=2");
        CHECK(*u3.Fragment() == "PageMarker");
    }

}