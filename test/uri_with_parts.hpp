// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

struct UriWithParts {
    char const* uri;
    struct Parts {
        char const* scheme;
        char const* authority;
        char const* path;
        char const* query;
        char const* fragment;
    } parts;
};

UriWithParts const uri_tests[] = {
    { "",
        { nullptr, nullptr, "", nullptr, nullptr }
    },
    { "#",
        { nullptr, nullptr, "", nullptr, "" }
    },
    { "#fragment",
        { nullptr, nullptr, "", nullptr, "fragment" }
    },
    { "?",
        { nullptr, nullptr, "", "", nullptr }
    },
    { "?#",
        { nullptr, nullptr, "", "", "" }
    },
    { "?#fragment",
        { nullptr, nullptr, "", "", "fragment" }
    },
    { "?query",
        { nullptr, nullptr, "", "query", nullptr }
    },
    { "?query#",
        { nullptr, nullptr, "", "query", "" }
    },
    { "?query#fragment",
        { nullptr, nullptr, "", "query", "fragment" }
    },
    { "path",
        { nullptr, nullptr, "path", nullptr, nullptr }
    },
    { "path#",
        { nullptr, nullptr, "path", nullptr, "" }
    },
    { "path#fragment",
        { nullptr, nullptr, "path", nullptr, "fragment" }
    },
    { "path?",
        { nullptr, nullptr, "path", "", nullptr }
    },
    { "path?#",
        { nullptr, nullptr, "path", "", "" }
    },
    { "path?#fragment",
        { nullptr, nullptr, "path", "", "fragment" }
    },
    { "path?query",
        { nullptr, nullptr, "path", "query", nullptr }
    },
    { "path?query#",
        { nullptr, nullptr, "path", "query", "" }
    },
    { "path?query#fragment",
        { nullptr, nullptr, "path", "query", "fragment" }
    },
    { "//",
        { nullptr, "", "", nullptr, nullptr }
    },
    { "//#",
        { nullptr, "", "", nullptr, "" }
    },
    { "//#fragment",
        { nullptr, "", "", nullptr, "fragment" }
    },
    { "//?",
        { nullptr, "", "", "", nullptr }
    },
    { "//?#",
        { nullptr, "", "", "", "" }
    },
    { "//?#fragment",
        { nullptr, "", "", "", "fragment" }
    },
    { "//?query",
        { nullptr, "", "", "query", nullptr }
    },
    { "//?query#",
        { nullptr, "", "", "query", "" }
    },
    { "//?query#fragment",
        { nullptr, "", "", "query", "fragment" }
    },
    { "///path",
        { nullptr, "", "/path", nullptr, nullptr }
    },
    { "///path#",
        { nullptr, "", "/path", nullptr, "" }
    },
    { "///path#fragment",
        { nullptr, "", "/path", nullptr, "fragment" }
    },
    { "///path?",
        { nullptr, "", "/path", "", nullptr }
    },
    { "///path?#",
        { nullptr, "", "/path", "", "" }
    },
    { "///path?#fragment",
        { nullptr, "", "/path", "", "fragment" }
    },
    { "///path?query",
        { nullptr, "", "/path", "query", nullptr }
    },
    { "///path?query#",
        { nullptr, "", "/path", "query", "" }
    },
    { "///path?query#fragment",
        { nullptr, "", "/path", "query", "fragment" }
    },
    { "//authority",
        { nullptr, "authority", "", nullptr, nullptr }
    },
    { "//authority#",
        { nullptr, "authority", "", nullptr, "" }
    },
    { "//authority#fragment",
        { nullptr, "authority", "", nullptr, "fragment" }
    },
    { "//authority?",
        { nullptr, "authority", "", "", nullptr }
    },
    { "//authority?#",
        { nullptr, "authority", "", "", "" }
    },
    { "//authority?#fragment",
        { nullptr, "authority", "", "", "fragment" }
    },
    { "//authority?query",
        { nullptr, "authority", "", "query", nullptr }
    },
    { "//authority?query#",
        { nullptr, "authority", "", "query", "" }
    },
    { "//authority?query#fragment",
        { nullptr, "authority", "", "query", "fragment" }
    },
    { "//authority/path",
        { nullptr, "authority", "/path", nullptr, nullptr }
    },
    { "//authority/path#",
        { nullptr, "authority", "/path", nullptr, "" }
    },
    { "//authority/path#fragment",
        { nullptr, "authority", "/path", nullptr, "fragment" }
    },
    { "//authority/path?",
        { nullptr, "authority", "/path", "", nullptr }
    },
    { "//authority/path?#",
        { nullptr, "authority", "/path", "", "" }
    },
    { "//authority/path?#fragment",
        { nullptr, "authority", "/path", "", "fragment" }
    },
    { "//authority/path?query",
        { nullptr, "authority", "/path", "query", nullptr }
    },
    { "//authority/path?query#",
        { nullptr, "authority", "/path", "query", "" }
    },
    { "//authority/path?query#fragment",
        { nullptr, "authority", "/path", "query", "fragment" }
    },
    { "scheme:",
        { "scheme", nullptr, "", nullptr, nullptr }
    },
    { "scheme:#",
        { "scheme", nullptr, "", nullptr, "" }
    },
    { "scheme:#fragment",
        { "scheme", nullptr, "", nullptr, "fragment" }
    },
    { "scheme:?",
        { "scheme", nullptr, "", "", nullptr }
    },
    { "scheme:?#",
        { "scheme", nullptr, "", "", "" }
    },
    { "scheme:?#fragment",
        { "scheme", nullptr, "", "", "fragment" }
    },
    { "scheme:?query",
        { "scheme", nullptr, "", "query", nullptr }
    },
    { "scheme:?query#",
        { "scheme", nullptr, "", "query", "" }
    },
    { "scheme:?query#fragment",
        { "scheme", nullptr, "", "query", "fragment" }
    },
    { "scheme:path",
        { "scheme", nullptr, "path", nullptr, nullptr }
    },
    { "scheme:path#",
        { "scheme", nullptr, "path", nullptr, "" }
    },
    { "scheme:path#fragment",
        { "scheme", nullptr, "path", nullptr, "fragment" }
    },
    { "scheme:path?",
        { "scheme", nullptr, "path", "", nullptr }
    },
    { "scheme:path?#",
        { "scheme", nullptr, "path", "", "" }
    },
    { "scheme:path?#fragment",
        { "scheme", nullptr, "path", "", "fragment" }
    },
    { "scheme:path?query",
        { "scheme", nullptr, "path", "query", nullptr }
    },
    { "scheme:path?query#",
        { "scheme", nullptr, "path", "query", "" }
    },
    { "scheme:path?query#fragment",
        { "scheme", nullptr, "path", "query", "fragment" }
    },
    { "scheme://",
        { "scheme", "", "", nullptr, nullptr }
    },
    { "scheme://#",
        { "scheme", "", "", nullptr, "" }
    },
    { "scheme://#fragment",
        { "scheme", "", "", nullptr, "fragment" }
    },
    { "scheme://?",
        { "scheme", "", "", "", nullptr }
    },
    { "scheme://?#",
        { "scheme", "", "", "", "" }
    },
    { "scheme://?#fragment",
        { "scheme", "", "", "", "fragment" }
    },
    { "scheme://?query",
        { "scheme", "", "", "query", nullptr }
    },
    { "scheme://?query#",
        { "scheme", "", "", "query", "" }
    },
    { "scheme://?query#fragment",
        { "scheme", "", "", "query", "fragment" }
    },
    { "scheme:///path",
        { "scheme", "", "/path", nullptr, nullptr }
    },
    { "scheme:///path#",
        { "scheme", "", "/path", nullptr, "" }
    },
    { "scheme:///path#fragment",
        { "scheme", "", "/path", nullptr, "fragment" }
    },
    { "scheme:///path?",
        { "scheme", "", "/path", "", nullptr }
    },
    { "scheme:///path?#",
        { "scheme", "", "/path", "", "" }
    },
    { "scheme:///path?#fragment",
        { "scheme", "", "/path", "", "fragment" }
    },
    { "scheme:///path?query",
        { "scheme", "", "/path", "query", nullptr }
    },
    { "scheme:///path?query#",
        { "scheme", "", "/path", "query", "" }
    },
    { "scheme:///path?query#fragment",
        { "scheme", "", "/path", "query", "fragment" }
    },
    { "scheme://authority",
        { "scheme", "authority", "", nullptr, nullptr }
    },
    { "scheme://authority#",
        { "scheme", "authority", "", nullptr, "" }
    },
    { "scheme://authority#fragment",
        { "scheme", "authority", "", nullptr, "fragment" }
    },
    { "scheme://authority?",
        { "scheme", "authority", "", "", nullptr }
    },
    { "scheme://authority?#",
        { "scheme", "authority", "", "", "" }
    },
    { "scheme://authority?#fragment",
        { "scheme", "authority", "", "", "fragment" }
    },
    { "scheme://authority?query",
        { "scheme", "authority", "", "query", nullptr }
    },
    { "scheme://authority?query#",
        { "scheme", "authority", "", "query", "" }
    },
    { "scheme://authority?query#fragment",
        { "scheme", "authority", "", "query", "fragment" }
    },
    { "scheme://authority/path",
        { "scheme", "authority", "/path", nullptr, nullptr }
    },
    { "scheme://authority/path#",
        { "scheme", "authority", "/path", nullptr, "" }
    },
    { "scheme://authority/path#fragment",
        { "scheme", "authority", "/path", nullptr, "fragment" }
    },
    { "scheme://authority/path?",
        { "scheme", "authority", "/path", "", nullptr }
    },
    { "scheme://authority/path?#",
        { "scheme", "authority", "/path", "", "" }
    },
    { "scheme://authority/path?#fragment",
        { "scheme", "authority", "/path", "", "fragment" }
    },
    { "scheme://authority/path?query",
        { "scheme", "authority", "/path", "query", nullptr }
    },
    { "scheme://authority/path?query#",
        { "scheme", "authority", "/path", "query", "" }
    },
    { "scheme://authority/path?query#fragment",
        { "scheme", "authority", "/path", "query", "fragment" }
    },
};
