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
        INFO("uri := " << test.uri.string());

        // scheme
        {
            eggs::uri uri = test.uri;

            uri.remove_scheme();

            CHECK(uri.has_scheme() == false);
            CHECK(uri.scheme() == "");
            if (test.parts.scheme == nullptr) {
                CHECK(uri == test.uri);
            }
        }

        // authority
        {
            eggs::uri uri = test.uri;

            uri.remove_authority();

            CHECK(uri.has_authority() == false);
            CHECK(uri.authority() == "");
            if (test.parts.authority == nullptr) {
                CHECK(uri == test.uri);
            }
        }

        // path
        {
            eggs::uri uri = test.uri;

            uri.remove_path();

            CHECK(uri.path() == "");
        }

        // query
        {
            eggs::uri uri = test.uri;

            uri.remove_query();

            CHECK(uri.has_query() == false);
            CHECK(uri.query() == "");
            if (test.parts.query == nullptr) {
                CHECK(uri == test.uri);
            }
        }

        // fragment
        {
            eggs::uri uri = test.uri;

            uri.remove_fragment();

            CHECK(uri.has_fragment() == false);
            CHECK(uri.fragment() == "");
            if (test.parts.fragment == nullptr) {
                CHECK(uri == test.uri);
            }
        }
    }
}
