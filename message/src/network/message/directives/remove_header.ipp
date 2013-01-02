// Copyright 2011 Dean Michael Berris (dberris@google.com).
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_MESSAGE_DIRECTIVES_REMOVE_HEADER_IPP_20111021
#define NETWORK_MESSAGE_DIRECTIVES_REMOVE_HEADER_IPP_20111021

#include <network/message/directives/remove_header.hpp>

namespace network {
namespace impl {

remove_header_directive::remove_header_directive(std::string const & header_name):
  header_name_(header_name) {}

void remove_header_directive::operator() (message_base & msg) const {
  msg.remove_headers(header_name_);
}

}  // namespace impl
}  // namespace network

#endif /* NETWORK_MESSAGE_DIRECTIVES_REMOVE_HEADER_IPP_20111021 */
