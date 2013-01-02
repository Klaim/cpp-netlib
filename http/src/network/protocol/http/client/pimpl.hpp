// Copyright Dean Michael Berris 2010.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_CLIENT_PIMPL_HPP_20100623
#define NETWORK_PROTOCOL_HTTP_CLIENT_PIMPL_HPP_20100623

#include <boost/mpl/not.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/if.hpp>
#include <boost/static_assert.hpp>

#include <network/protocol/http/client/async_impl.hpp>
#include <network/protocol/http/client/sync_impl.hpp>

namespace network {
namespace http {

template <class Tag, unsigned version_major, unsigned version_minor>
struct basic_client_impl;

namespace impl {

    template <class Tag, unsigned version_major, unsigned version_minor>
    struct async_client;
    
    template <class Tag, unsigned version_major, unsigned version_minor>
    struct sync_client;
    
    
    template <class Tag, unsigned version_major, unsigned version_minor, class Enable = void>
    struct client_base {
        typedef unsupported_tag<Tag> type;
    };
    
    template <class Tag, unsigned version_major, unsigned version_minor>
    struct client_base<Tag, version_major, version_minor, typename enable_if<is_async<Tag> >::type> {
        typedef async_client<Tag,version_major,version_minor> type;
    };
    
    template <class Tag, unsigned version_major, unsigned version_minor>
    struct client_base<Tag, version_major, version_minor, typename enable_if<is_sync<Tag> >::type> {
        typedef sync_client<Tag,version_major,version_minor> type;
    };

} // namespace impl

template <class Tag, unsigned version_major, unsigned version_minor>
struct basic_client;

template <class Tag, unsigned version_major, unsigned version_minor>
struct basic_client_impl
    : impl::client_base<Tag,version_major,version_minor>::type
{
    STATIC_ASSERT((
        mpl::not_<
            mpl::and_<
                is_async<Tag>,
                is_sync<Tag>
            >
        >::value
        ));

    typedef typename impl::client_base<Tag,version_major,version_minor>::type base_type;
    typedef typename base_type::string_type string_type;

    basic_client_impl(bool cache_resolved, bool follow_redirect, optional<string_type> const & certificate_filename, optional<string_type> const & verify_path)
        : base_type(cache_resolved, follow_redirect, certificate_filename, verify_path)
    {}

    basic_client_impl(bool cache_resolved, bool follow_redirect, asio::io_service & service, optional<string_type> const & certificate_filename, optional<string_type> const & verify_path)
        : base_type(cache_resolved, follow_redirect, service, certificate_filename, verify_path)
    {}

    ~basic_client_impl()
    {}
};

} // namespace http

} // namespace network

#endif // NETWORK_PROTOCOL_HTTP_CLIENT_PIMPL_HPP_20100623
