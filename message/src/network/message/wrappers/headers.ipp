// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_MESSAGE_WRAPPERS_HEADERS_IPP_20110911
#define NETWORK_MESSAGE_WRAPPERS_HEADERS_IPP_20110911

#include <network/message/wrappers/headers.hpp>
#include <network/message/message_base.hpp>
#include <functional>

namespace network {

headers_wrapper::headers_wrapper(message_base const & message)
: message_(message)
{}

template <class Map>
struct kv_inserter {
  kv_inserter(Map & m)
      : m_(m) {}
  void operator() (std::string const & k, std::string const & v) const {
    m_.insert(std::make_pair(k, v));
  }
 private:
  Map & m_;
};

headers_wrapper::operator headers_wrapper::container_type () const {
  container_type tmp;
  kv_inserter<container_type> inserter(tmp);
  message_.get_headers(inserter);
  return tmp;
}

} /* network */

#endif /* NETWORK_MESSAGE_WRAPPERS_HEADERS_IPP_20110911 */
