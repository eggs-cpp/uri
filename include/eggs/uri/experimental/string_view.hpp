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
#include <string>

namespace eggs { namespace uris { namespace experimental
{
    class string_view
    {
    public:
        // types
        typedef std::char_traits<char> traits_type;
        typedef char value_type;
        typedef char* pointer;
        typedef char const* const_pointer;
        typedef char& reference;
        typedef char const& const_reference;
        typedef char const* const_iterator;
        typedef const_iterator iterator;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        EGGS_CXX11_STATIC_CONSTEXPR size_type const npos = size_type(-1);

    public:
        EGGS_CXX11_CONSTEXPR string_view() EGGS_CXX11_NOEXCEPT
          : _data(nullptr), _size(0)
        {}

        EGGS_CXX11_CONSTEXPR string_view(
            char const* str, size_type size) EGGS_CXX11_NOEXCEPT
          : _data(str), _size(size)
        {}

        /*constexpr*/ string_view(
            char const* str) EGGS_CXX11_NOEXCEPT
          : _data(str), _size(traits_type::length(str))
        {}

        template <typename Allocator>
        string_view(
            std::basic_string<
                char, std::char_traits<char>, Allocator
            > const& str) EGGS_CXX11_NOEXCEPT
          : _data(str.data()), _size(str.size())
        {}

        EGGS_CXX11_CONSTEXPR string_view(
            string_view const&) EGGS_CXX11_NOEXCEPT = default;

        string_view& operator=(
            string_view const&) EGGS_CXX11_NOEXCEPT = default;

        // iterator support
        EGGS_CXX11_CONSTEXPR iterator begin() const EGGS_CXX11_NOEXCEPT
        {
            return _data + 0;
        }

        EGGS_CXX11_CONSTEXPR iterator end() const EGGS_CXX11_NOEXCEPT
        {
            return _data + _size;
        }

        EGGS_CXX11_CONSTEXPR const_iterator cbegin() const EGGS_CXX11_NOEXCEPT
        {
            return begin();
        }

        EGGS_CXX11_CONSTEXPR const_iterator cend() const EGGS_CXX11_NOEXCEPT
        {
            return end();
        }

        // capacity
        EGGS_CXX11_CONSTEXPR bool empty() const EGGS_CXX11_NOEXCEPT
        {
            return _size == 0;
        }

        EGGS_CXX11_CONSTEXPR size_type size() const EGGS_CXX11_NOEXCEPT
        {
            return _size;
        }

        // element access
        EGGS_CXX11_CONSTEXPR char const& operator[](
            size_type pos) const EGGS_CXX11_NOEXCEPT
        {
            return _data[pos];
        }

        EGGS_CXX11_CONSTEXPR char const* data() const EGGS_CXX11_NOEXCEPT
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

        EGGS_CXX11_CONSTEXPR string_view substr(
            size_type pos = 0, size_type n = npos) const EGGS_CXX11_NOEXCEPT
        {
            return string_view(_data + pos, n < _size - pos ? n : _size - pos);
        }

        EGGS_CXX14_CONSTEXPR size_type find_first_of(
            char c, size_type pos = 0) const EGGS_CXX11_NOEXCEPT
        {
            for (; pos < _size; ++pos) {
                if (_data[pos] == c) {
                    return pos;
                }
            }
            return npos;
        }

        EGGS_CXX14_CONSTEXPR size_type find_first_of(
            char const* s, size_type pos = 0) const EGGS_CXX11_NOEXCEPT
        {
            assert(s != nullptr);
            for (; pos < _size; ++pos) {
                for (char const* c = s; *c != '\0'; ++c) {
                    if (_data[pos] == *c) {
                        return pos;
                    }
                }
            }
            return npos;
        }

        EGGS_CXX14_CONSTEXPR size_type find_last_of(
            char c, size_type pos = npos) const EGGS_CXX11_NOEXCEPT
        {
            for (pos = pos < _size ? pos : _size; pos > 0; --pos) {
                if (_data[pos - 1] == c) {
                    return pos - 1;
                }
            }
            return npos;
        }

        EGGS_CXX14_CONSTEXPR size_type find_last_of(
            char const* s, size_type pos = npos) const EGGS_CXX11_NOEXCEPT
        {
            assert(s != nullptr);
            for (pos = pos < _size ? pos : _size; pos > 0; --pos) {
                for (char const* c = s; *c != '\0'; ++c) {
                    if (_data[pos - 1] == *c) {
                        return pos - 1;
                    }
                }
            }
            return npos;
        }

    private:
        char const* _data;
        std::size_t _size;
    };

    EGGS_CXX11_CONSTEXPR inline bool operator==(
        string_view const& lhs, string_view const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return lhs.size() == rhs.size()
         && std::char_traits<char>::compare(lhs.data(), rhs.data(), lhs.size()) == 0;
    }

    EGGS_CXX11_CONSTEXPR inline bool operator!=(
        string_view const& lhs, string_view const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return !(lhs == rhs);
    }

}}}

#endif

#include <eggs/uri/detail/config/suffix.hpp>

#endif /*EGGS_URISEXPERIMENTAL_STRING_VIEW_HPP*/
