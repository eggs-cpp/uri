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

TEST_CASE("uri::xxx()", "[uri.decompose]")
{
    for (UriWithParts const& test : uri_tests)
    {
        eggs::uri const uri(test.uri);

        SECTION("scheme")
        {
            if (test.parts.scheme != nullptr) {
                CHECK(uri.scheme() == test.parts.scheme);
            } else {
                CHECK(uri.scheme() == "");
            }
        }

        SECTION("scheme-specific")
        {
            std::string scheme_specific;
            if (test.parts.authority != nullptr) {
                scheme_specific.append("//");
                scheme_specific.append(test.parts.authority);
            }
            scheme_specific.append(test.parts.path);
            if (test.parts.query != nullptr) {
                scheme_specific.append("?");
                scheme_specific.append(test.parts.query);
            }

            CHECK(uri.scheme_specific() == scheme_specific);
        }

        SECTION("authority")
        {
            if (test.parts.authority != nullptr) {
                CHECK(uri.authority() == test.parts.authority);
            } else {
                CHECK(uri.authority() == "");
            }
        }

        SECTION("path")
        {
            REQUIRE(test.parts.path != nullptr);

            CHECK(uri.path() == test.parts.path);
        }

        SECTION("query")
        {
            if (test.parts.query != nullptr) {
                CHECK(uri.query() == test.parts.query);
            } else {
                CHECK(uri.query() == "");
            }
        }

        SECTION("fragment")
        {
            if (test.parts.fragment != nullptr) {
                CHECK(uri.fragment() == test.parts.fragment);
            } else {
                CHECK(uri.fragment() == "");
            }
        }
    }
}
