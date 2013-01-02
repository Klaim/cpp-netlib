// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_RESPONSE_BASE_HPP_20110930
#define NETWORK_PROTOCOL_HTTP_RESPONSE_BASE_HPP_20110930

#include <network/message/message_base.hpp>
#include <cstdint>

namespace network { namespace http {

struct response_base : message_base {
  virtual void set_status(std::uint16_t new_status) = 0;
  virtual void set_status_message(std::string const & new_status_message) = 0;
  virtual void set_version(std::string const & new_version) = 0;
  virtual void get_status(std::uint16_t &status) const = 0;
  virtual void get_status_message(std::string &status_message) const = 0;
  virtual void get_version(std::string &version) const = 0;
  virtual ~response_base() = 0;
};

}  // namespace http
}  // namespace network

#endif /* NETWORK_PROTOCOL_HTTP_RESPONSE_BASE_HPP_20110930 */
