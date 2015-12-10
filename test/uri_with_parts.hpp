// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EGGS_URIS_TEST_URI_WITH_PARTS_HPP
#define EGGS_URIS_TEST_URI_WITH_PARTS_HPP

#include <eggs/uri.hpp>

struct UriWithParts {
    eggs::uri uri;
    struct Parts {
        char const* scheme;
        char const* authority;
        char const* path;
        char const* query;
        char const* fragment;
    } parts;
};

UriWithParts const uri_tests[] = {
    { eggs::uri(""),
        { nullptr, nullptr, "", nullptr, nullptr }
    },
    { eggs::uri("#"),
        { nullptr, nullptr, "", nullptr, "" }
    },
    { eggs::uri("#fragment"),
        { nullptr, nullptr, "", nullptr, "fragment" }
    },
    { eggs::uri("?"),
        { nullptr, nullptr, "", "", nullptr }
    },
    { eggs::uri("?#"),
        { nullptr, nullptr, "", "", "" }
    },
    { eggs::uri("?#fragment"),
        { nullptr, nullptr, "", "", "fragment" }
    },
    { eggs::uri("?query"),
        { nullptr, nullptr, "", "query", nullptr }
    },
    { eggs::uri("?query#"),
        { nullptr, nullptr, "", "query", "" }
    },
    { eggs::uri("?query#fragment"),
        { nullptr, nullptr, "", "query", "fragment" }
    },
    { eggs::uri("path"),
        { nullptr, nullptr, "path", nullptr, nullptr }
    },
    { eggs::uri("path#"),
        { nullptr, nullptr, "path", nullptr, "" }
    },
    { eggs::uri("path#fragment"),
        { nullptr, nullptr, "path", nullptr, "fragment" }
    },
    { eggs::uri("path?"),
        { nullptr, nullptr, "path", "", nullptr }
    },
    { eggs::uri("path?#"),
        { nullptr, nullptr, "path", "", "" }
    },
    { eggs::uri("path?#fragment"),
        { nullptr, nullptr, "path", "", "fragment" }
    },
    { eggs::uri("path?query"),
        { nullptr, nullptr, "path", "query", nullptr }
    },
    { eggs::uri("path?query#"),
        { nullptr, nullptr, "path", "query", "" }
    },
    { eggs::uri("path?query#fragment"),
        { nullptr, nullptr, "path", "query", "fragment" }
    },
    { eggs::uri("//"),
        { nullptr, "", "", nullptr, nullptr }
    },
    { eggs::uri("//#"),
        { nullptr, "", "", nullptr, "" }
    },
    { eggs::uri("//#fragment"),
        { nullptr, "", "", nullptr, "fragment" }
    },
    { eggs::uri("//?"),
        { nullptr, "", "", "", nullptr }
    },
    { eggs::uri("//?#"),
        { nullptr, "", "", "", "" }
    },
    { eggs::uri("//?#fragment"),
        { nullptr, "", "", "", "fragment" }
    },
    { eggs::uri("//?query"),
        { nullptr, "", "", "query", nullptr }
    },
    { eggs::uri("//?query#"),
        { nullptr, "", "", "query", "" }
    },
    { eggs::uri("//?query#fragment"),
        { nullptr, "", "", "query", "fragment" }
    },
    { eggs::uri("///path"),
        { nullptr, "", "/path", nullptr, nullptr }
    },
    { eggs::uri("///path#"),
        { nullptr, "", "/path", nullptr, "" }
    },
    { eggs::uri("///path#fragment"),
        { nullptr, "", "/path", nullptr, "fragment" }
    },
    { eggs::uri("///path?"),
        { nullptr, "", "/path", "", nullptr }
    },
    { eggs::uri("///path?#"),
        { nullptr, "", "/path", "", "" }
    },
    { eggs::uri("///path?#fragment"),
        { nullptr, "", "/path", "", "fragment" }
    },
    { eggs::uri("///path?query"),
        { nullptr, "", "/path", "query", nullptr }
    },
    { eggs::uri("///path?query#"),
        { nullptr, "", "/path", "query", "" }
    },
    { eggs::uri("///path?query#fragment"),
        { nullptr, "", "/path", "query", "fragment" }
    },
    { eggs::uri("//authority"),
        { nullptr, "authority", "", nullptr, nullptr }
    },
    { eggs::uri("//authority#"),
        { nullptr, "authority", "", nullptr, "" }
    },
    { eggs::uri("//authority#fragment"),
        { nullptr, "authority", "", nullptr, "fragment" }
    },
    { eggs::uri("//authority?"),
        { nullptr, "authority", "", "", nullptr }
    },
    { eggs::uri("//authority?#"),
        { nullptr, "authority", "", "", "" }
    },
    { eggs::uri("//authority?#fragment"),
        { nullptr, "authority", "", "", "fragment" }
    },
    { eggs::uri("//authority?query"),
        { nullptr, "authority", "", "query", nullptr }
    },
    { eggs::uri("//authority?query#"),
        { nullptr, "authority", "", "query", "" }
    },
    { eggs::uri("//authority?query#fragment"),
        { nullptr, "authority", "", "query", "fragment" }
    },
    { eggs::uri("//authority/path"),
        { nullptr, "authority", "/path", nullptr, nullptr }
    },
    { eggs::uri("//authority/path#"),
        { nullptr, "authority", "/path", nullptr, "" }
    },
    { eggs::uri("//authority/path#fragment"),
        { nullptr, "authority", "/path", nullptr, "fragment" }
    },
    { eggs::uri("//authority/path?"),
        { nullptr, "authority", "/path", "", nullptr }
    },
    { eggs::uri("//authority/path?#"),
        { nullptr, "authority", "/path", "", "" }
    },
    { eggs::uri("//authority/path?#fragment"),
        { nullptr, "authority", "/path", "", "fragment" }
    },
    { eggs::uri("//authority/path?query"),
        { nullptr, "authority", "/path", "query", nullptr }
    },
    { eggs::uri("//authority/path?query#"),
        { nullptr, "authority", "/path", "query", "" }
    },
    { eggs::uri("//authority/path?query#fragment"),
        { nullptr, "authority", "/path", "query", "fragment" }
    },
    { eggs::uri("scheme:"),
        { "scheme", nullptr, "", nullptr, nullptr }
    },
    { eggs::uri("scheme:#"),
        { "scheme", nullptr, "", nullptr, "" }
    },
    { eggs::uri("scheme:#fragment"),
        { "scheme", nullptr, "", nullptr, "fragment" }
    },
    { eggs::uri("scheme:?"),
        { "scheme", nullptr, "", "", nullptr }
    },
    { eggs::uri("scheme:?#"),
        { "scheme", nullptr, "", "", "" }
    },
    { eggs::uri("scheme:?#fragment"),
        { "scheme", nullptr, "", "", "fragment" }
    },
    { eggs::uri("scheme:?query"),
        { "scheme", nullptr, "", "query", nullptr }
    },
    { eggs::uri("scheme:?query#"),
        { "scheme", nullptr, "", "query", "" }
    },
    { eggs::uri("scheme:?query#fragment"),
        { "scheme", nullptr, "", "query", "fragment" }
    },
    { eggs::uri("scheme:path"),
        { "scheme", nullptr, "path", nullptr, nullptr }
    },
    { eggs::uri("scheme:path#"),
        { "scheme", nullptr, "path", nullptr, "" }
    },
    { eggs::uri("scheme:path#fragment"),
        { "scheme", nullptr, "path", nullptr, "fragment" }
    },
    { eggs::uri("scheme:path?"),
        { "scheme", nullptr, "path", "", nullptr }
    },
    { eggs::uri("scheme:path?#"),
        { "scheme", nullptr, "path", "", "" }
    },
    { eggs::uri("scheme:path?#fragment"),
        { "scheme", nullptr, "path", "", "fragment" }
    },
    { eggs::uri("scheme:path?query"),
        { "scheme", nullptr, "path", "query", nullptr }
    },
    { eggs::uri("scheme:path?query#"),
        { "scheme", nullptr, "path", "query", "" }
    },
    { eggs::uri("scheme:path?query#fragment"),
        { "scheme", nullptr, "path", "query", "fragment" }
    },
    { eggs::uri("scheme://"),
        { "scheme", "", "", nullptr, nullptr }
    },
    { eggs::uri("scheme://#"),
        { "scheme", "", "", nullptr, "" }
    },
    { eggs::uri("scheme://#fragment"),
        { "scheme", "", "", nullptr, "fragment" }
    },
    { eggs::uri("scheme://?"),
        { "scheme", "", "", "", nullptr }
    },
    { eggs::uri("scheme://?#"),
        { "scheme", "", "", "", "" }
    },
    { eggs::uri("scheme://?#fragment"),
        { "scheme", "", "", "", "fragment" }
    },
    { eggs::uri("scheme://?query"),
        { "scheme", "", "", "query", nullptr }
    },
    { eggs::uri("scheme://?query#"),
        { "scheme", "", "", "query", "" }
    },
    { eggs::uri("scheme://?query#fragment"),
        { "scheme", "", "", "query", "fragment" }
    },
    { eggs::uri("scheme:///path"),
        { "scheme", "", "/path", nullptr, nullptr }
    },
    { eggs::uri("scheme:///path#"),
        { "scheme", "", "/path", nullptr, "" }
    },
    { eggs::uri("scheme:///path#fragment"),
        { "scheme", "", "/path", nullptr, "fragment" }
    },
    { eggs::uri("scheme:///path?"),
        { "scheme", "", "/path", "", nullptr }
    },
    { eggs::uri("scheme:///path?#"),
        { "scheme", "", "/path", "", "" }
    },
    { eggs::uri("scheme:///path?#fragment"),
        { "scheme", "", "/path", "", "fragment" }
    },
    { eggs::uri("scheme:///path?query"),
        { "scheme", "", "/path", "query", nullptr }
    },
    { eggs::uri("scheme:///path?query#"),
        { "scheme", "", "/path", "query", "" }
    },
    { eggs::uri("scheme:///path?query#fragment"),
        { "scheme", "", "/path", "query", "fragment" }
    },
    { eggs::uri("scheme://authority"),
        { "scheme", "authority", "", nullptr, nullptr }
    },
    { eggs::uri("scheme://authority#"),
        { "scheme", "authority", "", nullptr, "" }
    },
    { eggs::uri("scheme://authority#fragment"),
        { "scheme", "authority", "", nullptr, "fragment" }
    },
    { eggs::uri("scheme://authority?"),
        { "scheme", "authority", "", "", nullptr }
    },
    { eggs::uri("scheme://authority?#"),
        { "scheme", "authority", "", "", "" }
    },
    { eggs::uri("scheme://authority?#fragment"),
        { "scheme", "authority", "", "", "fragment" }
    },
    { eggs::uri("scheme://authority?query"),
        { "scheme", "authority", "", "query", nullptr }
    },
    { eggs::uri("scheme://authority?query#"),
        { "scheme", "authority", "", "query", "" }
    },
    { eggs::uri("scheme://authority?query#fragment"),
        { "scheme", "authority", "", "query", "fragment" }
    },
    { eggs::uri("scheme://authority/path"),
        { "scheme", "authority", "/path", nullptr, nullptr }
    },
    { eggs::uri("scheme://authority/path#"),
        { "scheme", "authority", "/path", nullptr, "" }
    },
    { eggs::uri("scheme://authority/path#fragment"),
        { "scheme", "authority", "/path", nullptr, "fragment" }
    },
    { eggs::uri("scheme://authority/path?"),
        { "scheme", "authority", "/path", "", nullptr }
    },
    { eggs::uri("scheme://authority/path?#"),
        { "scheme", "authority", "/path", "", "" }
    },
    { eggs::uri("scheme://authority/path?#fragment"),
        { "scheme", "authority", "/path", "", "fragment" }
    },
    { eggs::uri("scheme://authority/path?query"),
        { "scheme", "authority", "/path", "query", nullptr }
    },
    { eggs::uri("scheme://authority/path?query#"),
        { "scheme", "authority", "/path", "query", "" }
    },
    { eggs::uri("scheme://authority/path?query#fragment"),
        { "scheme", "authority", "/path", "query", "fragment" }
    },
};

#endif /*EGGS_URIS_TEST_URI_WITH_PARTS_HPP*/
