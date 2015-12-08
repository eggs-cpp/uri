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

TEST_CASE("uri::swap(uri&)", "[uri.swap]")
{
    eggs::uri u1;
    eggs::uri u2(source);
    REQUIRE(u1.empty() == true);
    REQUIRE(u2.empty() == false);

    u1.swap(u2);

    CHECK(u1.empty() == false);
    CHECK(u1.string() == source);
    CHECK(u2.empty() == true);
}

TEST_CASE("swap(uri&, uri&)", "[uri.swap]")
{
    eggs::uri u1;
    eggs::uri u2(source);
    REQUIRE(u1.empty() == true);
    REQUIRE(u2.empty() == false);

    eggs::uris::swap(u1, u2);

    CHECK(u1.empty() == false);
    CHECK(u1.string() == source);
    CHECK(u2.empty() == true);
}
