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

TEST_CASE("operator<(uri const&, uri const&)", "[uri.rel]")
{
    eggs::uri const u1;
    eggs::uri const u2(source);
    REQUIRE(u1.empty() == true);
    REQUIRE(u2.empty() == false);

    CHECK(u1 < u2);
    CHECK(u2 >   u1);

    eggs::uri const u3(source);
    REQUIRE(u3.empty() == false);

    CHECK((u2 < u3) == false);
    CHECK((u2 > u3) == false);
    CHECK((u2 <= u3) == true);
    CHECK((u2 >= u3) == true);
}
