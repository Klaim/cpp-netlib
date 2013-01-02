// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PATH_IPP_20111204
#define NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PATH_IPP_20111204

#include <network/protocol/http/message/wrappers/path.hpp>
#include <network/uri.hpp>

namespace network { namespace http {

path_wrapper::path_wrapper(request_base const & request)
: request_(request) {}

path_wrapper::operator std::string () const {
  ::network::uri uri_;
  request_.get_uri(uri_);
  return path(uri_);
}

}  // namespace http
}  // namespace network

#endif  // NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_PATH_IPP_20111204
