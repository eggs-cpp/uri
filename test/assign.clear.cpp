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

std::string const source = "scheme://authority/path?query#fragment";

TEST_CASE("uri::clear()", "[uri.assign]")
{
    eggs::uri u(source);

    REQUIRE(u.empty() == false);
    REQUIRE(u.has_scheme() == true);
    REQUIRE(u.has_authority() == true);
    REQUIRE(u.has_query() == true);
    REQUIRE(u.has_fragment() == true);
    REQUIRE(u.string() == source);

    u.clear();

    CHECK(u.empty() == true);
    CHECK(u.has_scheme() == false);
    CHECK(u.has_authority() == false);
    CHECK(u.has_query() == false);
    CHECK(u.has_fragment() == false);
    CHECK(u.string() == "");
}
