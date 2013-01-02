// Copyright 2010 (c) Dean Michael Berris.
// Copyright 2010 (c) Sinefunc, Inc.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_URI_HPP_20100620
#define NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_URI_HPP_20100620

#include <network/uri/uri.hpp>
#include <network/protocol/http/request/request_base.hpp>

namespace network {
namespace http {

struct uri_wrapper {
  explicit uri_wrapper(request_base const & request_);
  operator std::string() const;
  operator ::network::uri() const;
 private:
  request_base const & request_;
};

inline
uri_wrapper const
uri(request_base const & request) {
    return uri_wrapper(request);
}

} // namespace http
} // namespace network

#endif // NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_URI_HPP_20100620
