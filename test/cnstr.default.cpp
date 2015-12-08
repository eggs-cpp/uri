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

TEST_CASE("uri::uri()", "[uri.cnstr]")
{
    eggs::uri u;

    CHECK(u.empty() == true);
    CHECK(u.has_scheme() == false);
    CHECK(u.has_authority() == false);
    CHECK(u.has_query() == false);
    CHECK(u.has_fragment() == false);
    CHECK(u.string() == "");
}
