// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EGGS_URISEXPERIMENTAL_STRING_VIEW_HPP
#define EGGS_URISEXPERIMENTAL_STRING_VIEW_HPP

#include <eggs/uri/detail/config/prefix.hpp>

#if EGGS_EXPERIMENTAL_STD_HAS_STRING_VIEW

#include <experimental/string_view>

namespace eggs { namespace uris { namespace experimental
{
    using string_view = std::experimental::string_view;
}}}

#else

#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

namespace eggs { namespace uris { namespace experimental
{
    class string_view
    {
    public:
        constexpr string_view() EGGS_CXX11_NOEXCEPT
          : _data(nullptr)
          , _size(0)
        {}

        /*constexpr*/ string_view(
            char const* str, std::size_t size) EGGS_CXX11_NOEXCEPT
          : _data(str)
          , _size(size)
        {
            assert(str != nullptr || size == 0);
        }

        string_view(
            char const* str) EGGS_CXX11_NOEXCEPT
          : string_view(str, str != nullptr ? std::strlen(str) : 0)
        {}

        string_view(
            std::string const& str) EGGS_CXX11_NOEXCEPT
          : string_view(str.data(), str.size())
        {}

        string_view(string_view const&) = default;
        string_view& operator=(string_view const&) = default;

        // capacity
        constexpr bool empty() const EGGS_CXX11_NOEXCEPT
        {
            return _size == 0;
        }

        constexpr std::size_t size() const EGGS_CXX11_NOEXCEPT
        {
            return _size;
        }

        // element access
        /*constexpr*/ char operator[](
            std::size_t pos) const EGGS_CXX11_NOEXCEPT
        {
            assert(pos < _size);
            return _data[pos];
        }

        constexpr char const* data() const EGGS_CXX11_NOEXCEPT
        {
            return _data;
        }

        // string operations
        std::string to_string() const
        {
            return std::string(_data, _size);
        }

        explicit operator std::string() const
        {
            return to_string();
        }

        /*constexpr*/ string_view substr(
            std::size_t pos = 0, std::size_t n = std::size_t(-1)) const EGGS_CXX11_NOEXCEPT
        {
            assert(pos <= _size);
            std::size_t const rlen = n < _size - pos ? n : _size - pos;
            return string_view(_data + pos, rlen);
        }

        /*constexpr*/ std::size_t find_first_of(
            char c, std::size_t pos = 0) const EGGS_CXX11_NOEXCEPT
        {
            for (; pos < _size; ++pos) {
                if (_data[pos] == c) {
                    return pos;
                }
            }
            return std::size_t(-1);
        }

        /*constexpr*/ std::size_t find_first_of(
            char const* s, std::size_t pos = 0) const EGGS_CXX11_NOEXCEPT
        {
            assert(s != nullptr);
            for (; pos < _size; ++pos) {
                for (char const* c = s; *c != '\0'; ++c) {
                    if (_data[pos] == *c) {
                        return pos;
                    }
                }
            }
            return std::size_t(-1);
        }

        /*constexpr*/ std::size_t find_last_of(
            char c, std::size_t pos = std::size_t(-1)) const EGGS_CXX11_NOEXCEPT
        {
            for (pos = pos < _size ? pos : _size; pos > 0; --pos) {
                if (_data[pos - 1] == c) {
                    return pos - 1;
                }
            }
            return std::size_t(-1);
        }

        /*constexpr*/ std::size_t find_last_of(
            char const* s, std::size_t pos = std::size_t(-1)) const EGGS_CXX11_NOEXCEPT
        {
            assert(s != nullptr);
            for (pos = pos < _size ? pos : _size; pos > 0; --pos) {
                for (char const* c = s; *c != '\0'; ++c) {
                    if (_data[pos - 1] == *c) {
                        return pos - 1;
                    }
                }
            }
            return std::size_t(-1);
        }

    private:
        char const* _data;
        std::size_t _size;
    };

    inline bool operator==(
        string_view const& lhs, string_view const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return lhs.size() == rhs.size()
         && std::memcmp(lhs.data(), rhs.data(), lhs.size()) == 0;
    }

    inline bool operator!=(
        string_view const& lhs, string_view const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return !(lhs == rhs);
    }

}}}

#endif

#include <eggs/uri/detail/config/suffix.hpp>

#endif /*EGGS_URISEXPERIMENTAL_STRING_VIEW_HPP*/
