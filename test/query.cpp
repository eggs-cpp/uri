// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <eggs/uri.hpp>

#include <eggs/uri/detail/config/prefix.hpp>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "uri_with_parts.hpp"

TEST_CASE("uri::has_xxx()", "[uri.query]")
{
    for (UriWithParts const& test : uri_tests)
    {
        INFO("uri := " << test.uri.string());

        eggs::uri const& uri = test.uri;

        // scheme
        {
            if (test.parts.scheme != nullptr) {
                CHECK(uri.has_scheme() == true);
            } else {
                CHECK(uri.has_scheme() == false);
            }
        }

        // authority
        {
            if (test.parts.authority != nullptr) {
                CHECK(uri.has_authority() == true);
            } else {
                CHECK(uri.has_authority() == false);
            }
        }

        // query
        {
            if (test.parts.query != nullptr) {
                CHECK(uri.has_query() == true);
            } else {
                CHECK(uri.has_query() == false);
            }
        }

        // fragment
        {
            if (test.parts.fragment != nullptr) {
                CHECK(uri.has_fragment() == true);
            } else {
                CHECK(uri.has_fragment() == false);
            }
        }
    }
}

TEST_CASE("is_absolute/is_relative()", "[uri.query]")
{
    eggs::uri const u1("http://isocpp.org/about");

    CHECK(eggs::uris::is_absolute(u1) == true);
    CHECK(eggs::uris::is_relative(u1) == false);

    eggs::uri const u2("about");

    CHECK(eggs::uris::is_absolute(u2) == false);
    CHECK(eggs::uris::is_relative(u2) == true);

    eggs::uri const u3("mailto:herb@isocpp.org");

    CHECK(eggs::uris::is_absolute(u3) == true);
    CHECK(eggs::uris::is_relative(u3) == false);
}

TEST_CASE("is_hierarchical/is_opaque()", "[uri.query]")
{
    eggs::uri const u1("http://isocpp.org/about");

    CHECK(eggs::uris::is_hierarchical(u1) == true);
    CHECK(eggs::uris::is_opaque(u1) == false);

    eggs::uri const u2("about");

    CHECK(eggs::uris::is_hierarchical(u2) == true);
    CHECK(eggs::uris::is_opaque(u2) == false);

    eggs::uri const u3("mailto:herb@isocpp.org");

    CHECK(eggs::uris::is_hierarchical(u3) == false);
    CHECK(eggs::uris::is_opaque(u3) == true);

    eggs::uri const u4("urn:isbn:0201539926");

    CHECK(eggs::uris::is_hierarchical(u4) == false);
    CHECK(eggs::uris::is_opaque(u4) == true);
}
