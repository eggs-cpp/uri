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

TEST_CASE("std::hash<uri>", "[uri.hash]")
{
    eggs::uri const u1;
    REQUIRE(u1.empty() == true);

    CHECK(std::hash<eggs::uri>()(u1) == std::hash<std::string>()(""));

    eggs::uri const u2(source);
    REQUIRE(u2.empty() == false);

    CHECK(std::hash<eggs::uri>()(u2) == std::hash<std::string>()(source));
}
