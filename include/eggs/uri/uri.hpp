// Eggs.URI
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014-2015
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EGGS_URI_URI_HPP
#define EGGS_URI_URI_HPP

#include <eggs/uri/detail/grammar.hpp>
#include <eggs/uri/experimental/string_view.hpp>

#include <cassert>
#include <cstddef>
#include <string>
#include <utility>

#include <eggs/uri/detail/config/prefix.hpp>

namespace eggs { namespace uris
{
    namespace detail
    {
        ///////////////////////////////////////////////////////////////////////
        enum class uri_part
        {
            scheme = 1,
            authority = 2,
            path = 3,
            query = 4,
            fragment = 5
        };

        ///////////////////////////////////////////////////////////////////////
        EGGS_CXX14_CONSTEXPR inline bool valid(
            uri_part part, experimental::string_view source) EGGS_CXX11_NOEXCEPT
        {
            switch (part) {
            case uri_part::scheme:
                return valid_scheme(source.begin(), source.end());
            case uri_part::authority:
                return valid_authority(source.begin(), source.end());
            case uri_part::path:
                return valid_path(source.begin(), source.end());
            case uri_part::query:
                return valid_query(source.begin(), source.end());
            case uri_part::fragment:
                return valid_fragment(source.begin(), source.end());
            }
            return assert(false), false;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //! class uri;
    //!
    //! An Uniform Resource Identifier (URI) is a compact sequence of
    //! characters that identifies an abstract or physical resource.
    //!
    //! The generic URI syntax &mdash;as defined in IETF RFC 3986&mdash;
    //! consists of a hierarchical sequence of components referred to as the
    //! scheme, authority, path, query, and fragment:
    //!
    //!     scheme:[//authority]path[?query][#fragment]
    //!
    //! Each URI begins with a scheme name that refers to a specification for
    //! assigning identifiers within that scheme. As such, the URI syntax is
    //! a federated and extensible naming system wherein each scheme's
    //! specification may further restrict the syntax and semantics of
    //! identifiers using that scheme.
    //!
    //! Many URI schemes include a hierarchical element for a naming authority
    //! so that governance of the name space defined by the remainder of the
    //! URI is delegated to that authority. The generic syntax provides a
    //! common means for distinguishing an authority based on a registered
    //! name or server address, along with optional port and user information:
    //!
    //!     [userinfo@]host[":"port]
    //!
    //! The path component contains data, usually organized in hierarchical
    //! form, that, along with data in the non-hierarchical query component,
    //! serves to identify a resource within the scope of the URI's scheme and
    //! naming authority (if any).
    //!
    //! The query component contains non-hierarchical data that, along with
    //! data in the path component, serves to identify a resource within the
    //! scope of the URI's scheme and naming authority (if any).
    //!
    //! The fragment identifier component of a URI allows indirect
    //! identification of a secondary resource by reference to a primary
    //! resource and additional identifying information. The identified
    //! secondary resource may be some portion or subset of the primary
    //! resource, some view on representations of the primary resource, or
    //! some other resource defined or described by those representations.
    class uri
    {
    public:
        //! uri() noexcept
        //!
        //! \effects Constructs an object of type `uri`.
        //!
        //! \postconditions `empty()`.
        uri() EGGS_CXX11_NOEXCEPT
          : _value()
          , _scheme_end(0)
          , _authority_end(0)
          , _path_end(0)
          , _query_end(0)
        {}

        //! uri(uri const& other)
        //!
        //! \effects Constructs an object of type `uri` with the value of
        //!  `other`.
        uri(uri const&) = default;

        //! uri(uri&& other) noexcept
        //!
        //! \effects Constructs an object of type `uri` with the original
        //!  value of `other`, leaving it in a valid state with unspecified
        //!  value.
        uri(uri&& other) EGGS_CXX11_NOEXCEPT
          : _value(std::move(other._value))
          , _scheme_end(other._scheme_end)
          , _authority_end(other._authority_end)
          , _path_end(other._path_end)
          , _query_end(other._query_end)
        {
            other.clear();
        }

        //! uri(std::string source)
        //!
        //! \requires The source shall conform to the generic URI syntax.
        //!
        //! \effects Constructs an object of type `uri` from `source`.
        explicit uri(std::string source)
        {
            _build(std::move(source));
        }

        //! template <class InputIterator>
        //! uri(InputIterator first, InputIterator last)
        //!
        //! \requires The source shall conform to the generic URI syntax.
        //!
        //! \effects Constructs an object of type `uri` from the source range
        //!  [`first`, `last`).
        template <typename InputIterator>
        uri(InputIterator first, InputIterator last)
        {
            _build(std::string(first, last));
        }

        //! uri& operator=(uri const& other)
        //!
        //! \effects If `*this` and `other` are the same object, has no effect.
        //!  Otherwise, replaces the value of `*this` with that of `other`.
        //!
        //! \returns `*this`.
        uri& operator=(uri const&) = default;

        //! uri& operator=(uri&& other) noexcept
        //!
        //! \effects Replaces the value of `*this` with the original value of
        //! `other`, leaving it in a valid state with unspecified value.
        //!
        //! \returns `*this`.
        uri& operator=(uri&& other) EGGS_CXX11_NOEXCEPT
        {
            _value = std::move(other._value);
            _scheme_end = other._scheme_end;
            _authority_end = other._authority_end;
            _path_end = other._path_end;
            _query_end = other._query_end;
            other.clear();
            return *this;
        }

        //! uri(std::string source)
        //!
        //! \requires The source shall conform to the generic URI syntax.
        //!
        //! \effects Replaces the value of `*this` with `source`.
        //!
        //! \returns `*this`.
        uri& operator=(std::string source) EGGS_CXX11_NOEXCEPT
        {
            _build(std::move(source));
            return *this;
        }

        //! uri(std::string source)
        //!
        //! \requires The source shall conform to the generic URI syntax.
        //!
        //! \effects Replaces the value of `*this` with `source`.
        void assign(std::string source)
        {
            _build(std::move(source));
        }

        //! template <class InputIterator>
        //! uri(InputIterator first, InputIterator last)
        //!
        //! \requires The source shall conform to the generic URI syntax.
        //!
        //! \effects Replaces the value of `*this` with the source range
        //!  [`first`, `last`).
        template <typename InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            _build(std::string(first, last));
        }

        //! void clear() noexcept
        //!
        //! \postconditions `empty()`.
        void clear() EGGS_CXX11_NOEXCEPT
        {
            _value.clear();
            _scheme_end = _authority_end = _path_end = _query_end = 0;
        }

        //! bool has_scheme() const noexcept
        //!
        //! \returns `true` if and only if the uri has a scheme component.
        bool has_scheme() const EGGS_CXX11_NOEXCEPT
        {
            return _scheme_end != 0;
        }

        //! experimental::string_view scheme() const noexcept
        //!
        //! \returns The value of the scheme component if the uri has one;
        //!  otherwise, an empty `string_view`.
        experimental::string_view scheme() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(0, _scheme_end - has_scheme());
        }

        //! void remove_scheme() noexcept
        //!
        //! \effects Removes the scheme component if the uri has one;
        //!  otherwise, has no effect.
        //!
        //! \postconditions `!has_scheme()`.
        void remove_scheme() EGGS_CXX11_NOEXCEPT
        {
            _resize(detail::uri_part::scheme, 0);
        }

        //! void replace_scheme(experimental::string_view scheme) noexcept
        //!
        //! \requires The given scheme shall be a valid scheme.
        //!
        //! \effects Replaces the scheme component with the given one.
        //!
        //! \postconditions `has_scheme()`.
        void replace_scheme(experimental::string_view scheme)
        {
            assert(detail::valid(detail::uri_part::scheme, scheme));
            _resize(detail::uri_part::scheme, scheme.size() + 1, ':');
            _value.replace(0, scheme.size(),
                scheme.data(), scheme.size());
        }

        //! experimental::string_view scheme_specific() const noexcept
        //!
        //! \returns The value of the scheme-specific part of the uri.
        //!
        //! \remarks The scheme-specific part of a uri consists of the
        //!  characters between the scheme and fragment components.
        experimental::string_view scheme_specific() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(_scheme_end, _query_end);
        }

        //! bool has_authority() const noexcept
        //!
        //! \returns `true` if and only if the uri has an authority component.
        bool has_authority() const EGGS_CXX11_NOEXCEPT
        {
            return _authority_end != _scheme_end;
        }

        //! experimental::string_view authority() const noexcept
        //!
        //! \returns The value of the authority component if the uri has one;
        //!  otherwise, an empty `string_view`.
        experimental::string_view authority() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(_scheme_end + 2, _authority_end);
        }

        //! void remove_authority() noexcept
        //!
        //! \effects Removes the authority component if the uri has one;
        //!  otherwise, has no effect.
        //!
        //! \postconditions `!has_authority()`.
        void remove_authority() EGGS_CXX11_NOEXCEPT
        {
            _resize(detail::uri_part::authority, 0);
        }

        //! void replace_authority(experimental::string_view authority) noexcept
        //!
        //! \requires The given authority shall be a valid authority.
        //!
        //! \effects Replaces the authority component with the given one.
        //!
        //! \postconditions `has_authority()`.
        void replace_authority(experimental::string_view authority)
        {
            assert(detail::valid(detail::uri_part::authority, authority));
            _resize(detail::uri_part::authority, 2 + authority.size(), '/');
            _value.replace(_scheme_end + 2, authority.size(),
                authority.data(), authority.size());
        }

        //! experimental::string_view path() const noexcept
        //!
        //! \returns The value of the path component of the uri.
        //!
        //! \remark The path component is always present in an uri.
        experimental::string_view path() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(_authority_end, _path_end);
        }

        //! void remove_path() noexcept
        //!
        //! \effects Replaces the path component with an empty one.
        void remove_path() EGGS_CXX11_NOEXCEPT
        {
            _resize(detail::uri_part::path, 0);
        }

        //! void replace_path(experimental::string_view path) noexcept
        //!
        //! \requires The given path shall be a valid path.
        //!
        //! \effects Replaces the path component with the given one.
        void replace_path(experimental::string_view path)
        {
            assert(detail::valid(detail::uri_part::path, path));
            _resize(detail::uri_part::path, path.size());
            _value.replace(_authority_end, path.size(),
                path.data(), path.size());
        }

        //! bool has_query() const noexcept
        //!
        //! \returns `true` if and only if the uri has a query component.
        bool has_query() const EGGS_CXX11_NOEXCEPT
        {
            return _query_end != _path_end;
        }

        //! experimental::string_view query() const noexcept
        //!
        //! \returns The value of the query component if the uri has one;
        //!  otherwise, an empty `string_view`.
        experimental::string_view query() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(_path_end + 1, _query_end);
        }

        //! void remove_query() noexcept
        //!
        //! \effects Removes the query component if the uri has one;
        //!  otherwise, has no effect.
        //!
        //! \postconditions `!has_query()`.
        void remove_query() EGGS_CXX11_NOEXCEPT
        {
            _resize(detail::uri_part::query, 0);
        }

        //! void replace_query(experimental::string_view query) noexcept
        //!
        //! \requires The given query shall be a valid query.
        //!
        //! \effects Replaces the query component with the given one.
        //!
        //! \postconditions `has_query()`.
        void replace_query(experimental::string_view query)
        {
            assert(detail::valid(detail::uri_part::query, query));
            _resize(detail::uri_part::query, 1 + query.size(), '?');
            _value.replace(_path_end + 1, query.size(),
                query.data(), query.size());
        }

        //! bool has_fragment() const noexcept
        //!
        //! \returns `true` if and only if the uri has a fragment component.
        bool has_fragment() const EGGS_CXX11_NOEXCEPT
        {
            return _query_end != _value.size();
        }

        //! experimental::string_view fragment() const noexcept
        //!
        //! \returns The value of the fragment component if the uri has one;
        //!  otherwise, an empty `string_view`.
        experimental::string_view fragment() const EGGS_CXX11_NOEXCEPT
        {
            return _substr(_query_end + 1, _value.size());
        }

        //! void remove_fragment() noexcept
        //!
        //! \effects Removes the fragment component if the uri has one;
        //!  otherwise, has no effect.
        //!
        //! \postconditions `!has_fragment()`.
        void remove_fragment() EGGS_CXX11_NOEXCEPT
        {
            _resize(detail::uri_part::fragment, 0);
        }

        //! void replace_fragment(experimental::string_view fragment) noexcept
        //!
        //! \requires The given fragment shall be a valid fragment.
        //!
        //! \effects Replaces the fragment component with the given one.
        //!
        //! \postconditions `has_fragment()`.
        void replace_fragment(experimental::string_view fragment)
        {
            assert(detail::valid(detail::uri_part::fragment, fragment));
            _resize(detail::uri_part::fragment, 1 + fragment.size(), '#');
            _value.replace(_query_end + 1, fragment.size(),
                fragment.data(), fragment.size());
        }

        //! void swap(uri& other) noexcept
        //!
        //! \postconditions `*this` contains the value that was in `other`,
        //!  `other` contains the value that was in `*this`.
        void swap(uri& other) EGGS_CXX11_NOEXCEPT
        {
            std::swap(_value, other._value);
            std::swap(_scheme_end, other._scheme_end);
            std::swap(_authority_end, other._authority_end);
            std::swap(_path_end, other._path_end);
            std::swap(_query_end, other._query_end);
        }

        //! bool empty() const noexcept
        //!
        //! \returns `true` if and only if the uri is empty.
        bool empty() const EGGS_CXX11_NOEXCEPT
        {
            return _value.empty();
        }

        //! std::string const& string() const noexcept
        //!
        //! \returns The underlying string representation for this uri.
        std::string const& string() const EGGS_CXX11_NOEXCEPT
        {
            return _value;
        }

    private:
        void _build(std::string&& source, bool checked = true) noexcept
        {
            _value = std::move(source);
            if (!_value.empty()) {
                _scheme_end = _value.find_first_of(':');
                if (_scheme_end == std::string::npos) {
                    _scheme_end = 0;
                } else {
                    ++_scheme_end;
                    assert(!checked
                     || detail::valid(detail::uri_part::scheme, scheme()));
                }

                if (_scheme_end + 2 <= _value.size()
                 && _value[_scheme_end + 0] == '/'
                 && _value[_scheme_end + 1] == '/') {
                    _authority_end = _value.find_first_of("/?#", _scheme_end + 2);
                    if (_authority_end == std::string::npos) {
                        _authority_end = _value.size();
                    }
                    assert(!checked
                     || detail::valid(detail::uri_part::authority, authority()));
                } else {
                    _authority_end = _scheme_end;
                }

                _path_end = _value.find_first_of("?#", _authority_end);
                if (_path_end == std::string::npos) {
                    _path_end = _value.size();
                }
                assert(!checked
                 || detail::valid(detail::uri_part::path, path()));

                _query_end = _value.find_first_of('#', _path_end);
                if (_query_end == std::string::npos) {
                    _query_end = _value.size();
                }
                assert(!checked
                 || detail::valid(detail::uri_part::query, query()));

                assert(!checked
                 || detail::valid(detail::uri_part::fragment, fragment()));
            } else {
                _scheme_end = _authority_end = _path_end = _query_end = 0;
            }

            (void)checked;
        }

        experimental::string_view _substr(
            std::size_t begin, std::size_t end) const EGGS_CXX11_NOEXCEPT
        {
            return begin <= end
              ? experimental::string_view(_value.data() + begin, end - begin)
              : experimental::string_view(_value.data() + end, 0);
        }

        void _resize(
            detail::uri_part part, std::size_t count, char value = '\0')
        {
            std::size_t start = 0;
            std::size_t fragment_end = _value.size();
            std::size_t* const parts[] = {
                &start, &_scheme_end,
                &_authority_end, &_path_end,
                &_query_end, &fragment_end
            };
            std::size_t const parts_count = sizeof(parts) / sizeof(parts[0]);

            std::size_t const index = static_cast<std::size_t>(part);
            std::size_t begin = *parts[index - 1];
            std::size_t end = *parts[index];
            _value.replace(begin, end - begin, count, value);

            std::ptrdiff_t const diff = count - (end - begin);
            for (std::size_t i = index; i < parts_count - 1; ++i) {
                *parts[i] += diff;
            }
        }

    private:
        std::string _value;
        std::size_t _scheme_end;
        std::size_t _authority_end;
        std::size_t _path_end;
        std::size_t _query_end;
    };

    ///////////////////////////////////////////////////////////////////////////
    //! bool operator==(uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `lhs.string() == rhs.string()`.
    inline bool operator==(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return lhs.string() == rhs.string();
    }

    //! bool operator!=(uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `!(lhs == rhs)`.
    inline bool operator!=(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return !(lhs == rhs);
    }

    //! bool operator<uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `lhs.string() < rhs.string()`.
    inline bool operator<(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return lhs.string() < rhs.string();
    }

    //! bool operator>uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `rhs < lhs`.
    inline bool operator>(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return rhs < lhs;
    }

    //! bool operator<=(uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `!(lhs > rhs)`.
    inline bool operator<=(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return !(lhs > rhs);
    }

    //! bool operator>=(uri const& lhs, uri const& rhs) noexcept
    //!
    //! \returns `!(lhs < rhs)`.
    inline bool operator>=(uri const& lhs, uri const& rhs) EGGS_CXX11_NOEXCEPT
    {
        return !(lhs < rhs);
    }

    ///////////////////////////////////////////////////////////////////////////
    //! void swap(uri& lhs, uri& rhs) noexcept
    //!
    //! \effects Equivalent to `lhs.swap(rhs)`.
    inline void swap(uri& lhs, uri& rhs) EGGS_CXX11_NOEXCEPT
    {
        lhs.swap(rhs);
    }

    ///////////////////////////////////////////////////////////////////////////
    //! bool is_absolute(uri const& u) noexcept
    //!
    //! \returns `true` if and only if `u` is an absolute uri; that is, it
    //!  specifies a scheme.
    inline bool is_absolute(uri const& u) EGGS_CXX11_NOEXCEPT
    {
        return u.has_scheme();
    }

    //! bool is_relative(uri const& u) noexcept
    //!
    //! \returns `!is_absolute(u)`.
    inline bool is_relative(uri const& u) EGGS_CXX11_NOEXCEPT
    {
        return !is_absolute(u);
    }

    ///////////////////////////////////////////////////////////////////////////
    //! bool is_hierarchical(uri const& u) noexcept
    //!
    //! \returns `true` if and only if `u` is an hierarchical uri; that is, it
    //!  is either an absolute uri whose scheme-specific part begins with a
    //!  slash character, or it is a relative uri.
    inline bool is_hierarchical(uri const& u) EGGS_CXX11_NOEXCEPT
    {
        return is_relative(u)
         || (!u.scheme_specific().empty() && u.scheme_specific()[0] == '/');
    }

    //! bool is_opaque(uri const& u) noexcept
    //!
    //! \returns `!is_hierarchical(u)`.
    inline bool is_opaque(uri const& u) EGGS_CXX11_NOEXCEPT
    {
        return !is_hierarchical(u);
    }
}}

namespace std
{
    //! template <>
    //! struct hash<::eggs::uris::uri>;
    //!
    //! \requires The template specialization `std::hash<uri>` shall meet the
    //!  requirements of class template `std::hash`. For an object `u` of
    //!  type `uri`, `std::hash<uri>()(u)` shall evaluate to the same value as
    //!  `std::hash<std::string>()(u.string())`.
    template <>
    struct hash<::eggs::uris::uri>
    {
        using argument_type = ::eggs::uris::uri;
        using result_type = std::size_t;

        std::size_t operator()(::eggs::uris::uri const& u) const
        {
            hash<std::string> h;
            return h(u.string());
        }
    };
}

#include <eggs/uri/detail/config/suffix.hpp>

#endif /*EGGS_URI_URI_HPP*/
