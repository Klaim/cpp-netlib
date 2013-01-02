// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_SIMPLE_CONNECTION_FACTORY_20111112
#define NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_SIMPLE_CONNECTION_FACTORY_20111112

#include <memory>
#include <network/protocol/http/client/connection/connection_factory.hpp>
#include <network/protocol/http/client/connection/connection_delegate_factory.hpp>
#include <network/protocol/http/client/connection/resolver_delegate_factory.hpp>

namespace network {
namespace http {

struct simple_connection_factory_pimpl;

struct simple_connection_factory : connection_factory {
  simple_connection_factory();
  simple_connection_factory(std::shared_ptr<connection_delegate_factory> conn_delegate_factory,
                            std::shared_ptr<resolver_delegate_factory> res_delegate_factory);
  virtual std::shared_ptr<client_connection> create_connection(boost::asio::io_service & service,
                                                               request_base const & request,
                                                               client_options const & options) override;
  virtual ~simple_connection_factory();
 private:
  std::unique_ptr<simple_connection_factory_pimpl> pimpl;
  simple_connection_factory(simple_connection_factory const &);  // = delete
  simple_connection_factory& operator=(simple_connection_factory);  // = delete
};
  
}  // namespace http
}  // namespace network
  
#endif /* NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_SIMPLE_CONNECTION_FACTORY_20111112 */
