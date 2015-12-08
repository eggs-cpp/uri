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

TEST_CASE("uri::remove_xxx()", "[uri.modifiers]")
{
    for (UriWithParts const& test : uri_tests)
    {
        eggs::uri uri(test.uri);

        SECTION("scheme")
        {
            uri.remove_scheme();

            CHECK(uri.has_scheme() == false);
            if (test.parts.scheme == nullptr) {
                CHECK(uri.string() == test.uri);
            }
        }

        SECTION("authority")
        {
            uri.remove_authority();

            CHECK(uri.has_authority() == false);
            if (test.parts.authority == nullptr) {
                CHECK(uri.string() == test.uri);
            }
        }

        SECTION("path")
        {
            uri.remove_path();
        }

        SECTION("query")
        {
            uri.remove_query();

            CHECK(uri.has_query() == false);
            if (test.parts.query == nullptr) {
                CHECK(uri.string() == test.uri);
            }
        }

        SECTION("fragment")
        {
            uri.remove_fragment();

            CHECK(uri.has_fragment() == false);
            if (test.parts.fragment == nullptr) {
                CHECK(uri.string() == test.uri);
            }
        }
    }
}
