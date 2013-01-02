// Copyright 2011 Dean Michael Berris (dberris@google.com).
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_MESSAGE_WRAPPERS_SOURCE_IPP_20111021
#define NETWORK_MESSAGE_WRAPPERS_SOURCE_IPP_20111021

#include <network/message/wrappers/source.hpp>

namespace network {

source_wrapper::source_wrapper(message_base const & message):
  message_(message) {}

source_wrapper::operator std::string () const {
  if (cache_) {
    return *cache_;
  }
  std::string tmp;
  message_.get_source(tmp);
  cache_ = tmp;
  return *cache_;
}

} /* network */

#endif /* NETWORK_MESSAGE_WRAPPERS_SOURCE_IPP_20111021 */
