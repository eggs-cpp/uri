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

TEST_CASE("uri::operator=(std::string)", "[uri.assign]")
{
    eggs::uri u;

    REQUIRE(u.empty() == true);

    u = source;

    CHECK(u.empty() == false);
    CHECK(u.string() == source);
    CHECK(u.scheme() == "scheme");
    CHECK(u.authority() == "authority");
    CHECK(u.path() == "/path");
    CHECK(u.query() == "query");
    CHECK(u.fragment() == "fragment");
}

TEST_CASE("uri::assign(std::string)", "[uri.assign]")
{
    eggs::uri u;

    REQUIRE(u.empty() == true);

    u.assign(source);

    CHECK(u.empty() == false);
    CHECK(u.string() == source);
    CHECK(u.scheme() == "scheme");
    CHECK(u.authority() == "authority");
    CHECK(u.path() == "/path");
    CHECK(u.query() == "query");
    CHECK(u.fragment() == "fragment");
}

TEST_CASE("uri::assign(InputIterator, InputIterator)", "[uri.assign]")
{
    eggs::uri u;

    REQUIRE(u.empty() == true);

    u.assign(source.begin(), source.end());

    CHECK(u.empty() == false);
    CHECK(u.string() == source);
    CHECK(u.scheme() == "scheme");
    CHECK(u.authority() == "authority");
    CHECK(u.path() == "/path");
    CHECK(u.query() == "query");
    CHECK(u.fragment() == "fragment");
}
