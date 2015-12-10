// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EGGS_URI_DETAIL_GRAMMAR_HPP
#define EGGS_URI_DETAIL_GRAMMAR_HPP

#include <eggs/uri/experimental/string_view.hpp>

#include <eggs/uri/detail/config/prefix.hpp>

namespace eggs { namespace uris { namespace detail
{
    ///////////////////////////////////////////////////////////////////////
    struct _grammar
    {
        static EGGS_CXX14_CONSTEXPR bool any_of(
            char needle, char const* hay) EGGS_CXX11_NOEXCEPT
        {
            for (char const* iter = hay; *iter != '\0'; ++iter) {
                if (*iter == needle) {
                    return true;
                }
            }
            return false;
        }

        static EGGS_CXX14_CONSTEXPR bool alpha(char c) EGGS_CXX11_NOEXCEPT
        {
            return any_of(c,
                "abcdefghijklmnopqrstuvwxyz"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        }

        static EGGS_CXX14_CONSTEXPR bool digit(char c) EGGS_CXX11_NOEXCEPT
        {
            return any_of(c, "0123456789");
        }

        static EGGS_CXX14_CONSTEXPR bool hexdigit(char c) EGGS_CXX11_NOEXCEPT
        {
            return any_of(c, "0123456789" "ABCDEF" "abcdef");
        }

        static EGGS_CXX14_CONSTEXPR bool gen_delims(char c) EGGS_CXX11_NOEXCEPT
        {
            return any_of(c, ":" "/" "?" "#" "[" "]" "@");
        }

        static EGGS_CXX14_CONSTEXPR bool sub_delims(char c) EGGS_CXX11_NOEXCEPT
        {
            return any_of(c, "!" "$" "&" "'" "(" ")" "*" "+" "," ";" "=");
        }

        static EGGS_CXX14_CONSTEXPR bool reserved(char c) EGGS_CXX11_NOEXCEPT
        {
            return gen_delims(c) || sub_delims(c);
        }

        static EGGS_CXX14_CONSTEXPR bool unreserved(char c) EGGS_CXX11_NOEXCEPT
        {
            return alpha(c) || digit(c) || any_of(c, "-" "." "_" "~");
        }

        static EGGS_CXX14_CONSTEXPR bool pchar(char c) EGGS_CXX11_NOEXCEPT
        {
            return unreserved(c) || sub_delims(c) || any_of(c, ":" "@");
        }

        template <typename InputIterator>
        static EGGS_CXX14_CONSTEXPR bool pct_encoded(char c,
            InputIterator& first, InputIterator const& last) EGGS_CXX11_NOEXCEPT
        {
            if (c != '%') {
                return false;
            }
            if (++first == last || !_grammar::hexdigit(*first)) {
                return false;
            }
            if (++first == last || !_grammar::hexdigit(*first)) {
                return false;
            }
            return true;
        }
    };

    ///////////////////////////////////////////////////////////////////////
    template <typename InputIterator>
    EGGS_CXX14_CONSTEXPR bool valid_scheme(
        InputIterator first, InputIterator last) EGGS_CXX11_NOEXCEPT
    {
        if (first == last || !_grammar::alpha(*first++)) {
            return false;
        }
        for (; first != last; ++first) {
            char const c = *first;
            if (!_grammar::alpha(c) && !_grammar::digit(c)
             && !_grammar::any_of(c, "+" "-" ".")) {
                return false;
            }
        }
        return true;
    }

    template <typename InputIterator>
    EGGS_CXX14_CONSTEXPR bool valid_authority(
        InputIterator first, InputIterator last) EGGS_CXX11_NOEXCEPT
    {
        for (; first != last; ++first) {
            char const c = *first;
            if (!_grammar::unreserved(c) && !_grammar::sub_delims(c)
             && !_grammar::any_of(c, ":" "[" "]" "@")) {
                if (!_grammar::pct_encoded(c, first, last)) {
                    return false;
                }
            }
        }
        return true;
    }

    template <typename InputIterator>
    EGGS_CXX14_CONSTEXPR bool valid_path(
        InputIterator first, InputIterator last) EGGS_CXX11_NOEXCEPT
    {
        for (; first != last; ++first) {
            char const c = *first;
            if (!_grammar::pchar(c) && !_grammar::any_of(c, "/")) {
                if (!_grammar::pct_encoded(c, first, last)) {
                    return false;
                }
            }
        }
        return true;
    }

    template <typename InputIterator>
    EGGS_CXX14_CONSTEXPR bool valid_query(
        InputIterator first, InputIterator last) EGGS_CXX11_NOEXCEPT
    {
        for (; first != last; ++first) {
            char const c = *first;
            if (!_grammar::pchar(c) && !_grammar::any_of(c, "/" "?")) {
                if (!_grammar::pct_encoded(c, first, last)) {
                    return false;
                }
            }
        }
        return true;
    }

    template <typename InputIterator>
    EGGS_CXX14_CONSTEXPR bool valid_fragment(
        InputIterator first, InputIterator last) EGGS_CXX11_NOEXCEPT
    {
        return valid_query(first, last);
    }
}}}

#include <eggs/uri/detail/config/suffix.hpp>

#endif /*EGGS_URI_DETAIL_GRAMMAR_HPP*/
