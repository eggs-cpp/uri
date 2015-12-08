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

TEST_CASE("uri::replace_xxx()", "[uri.modifiers]")
{
    for (UriWithParts const& test : uri_tests)
    {
        eggs::uri uri(test.uri);

        SECTION("scheme")
        {
            uri.replace_scheme("replacement");

            CHECK(uri.has_scheme() == true);
        }

        SECTION("authority")
        {
            uri.replace_authority("replacement");

            CHECK(uri.has_authority() == true);
        }

        SECTION("path")
        {
            uri.replace_path("/replacement");
        }

        SECTION("query")
        {
            uri.replace_query("replacement");

            CHECK(uri.has_query() == true);
        }

        SECTION("fragment")
        {
            uri.replace_fragment("replacement");

            CHECK(uri.has_fragment() == true);
        }
    }
}
