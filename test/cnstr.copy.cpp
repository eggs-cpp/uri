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

TEST_CASE("uri::uri(uri const&)", "[uri.cnstr]")
{
    eggs::uri const u1(source);

    REQUIRE(u1.empty() == false);
    REQUIRE(u1.string() == source);

    eggs::uri u2(u1);

    CHECK(u2.empty() == false);
    CHECK(u2.string() == source);
    CHECK(u2 == u1);
}
