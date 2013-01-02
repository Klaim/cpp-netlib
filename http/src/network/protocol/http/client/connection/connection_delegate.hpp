// Copyright 2011 Dean Michael Berris (dberris@google.com).
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_CONNECTION_DELEGATE_HPP_
#define NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_CONNECTION_DELEGATE_HPP_

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include <functional>

namespace network {
namespace http {

struct connection_delegate {
  virtual void connect(boost::asio::ip::tcp::endpoint & endpoint,
                       std::string const & host,
                       std::function<void(boost::system::error_code const &)> handler) = 0;
  virtual void write(boost::asio::streambuf & command_streambuf,
                     std::function<void(boost::system::error_code const &, size_t)> handler) = 0;
  virtual void read_some(boost::asio::mutable_buffers_1 const & read_buffer,
                         std::function<void(boost::system::error_code const &, size_t)> handler) = 0;
  virtual ~connection_delegate() {}
};

}  // namespace http
}  // namespace network

#endif /* NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_CONNECTION_DELEGATE_HPP_ */
