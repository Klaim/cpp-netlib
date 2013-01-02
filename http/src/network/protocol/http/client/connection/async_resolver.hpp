// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_ASYNC_RESOLVER_20111126
#define NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_ASYNC_RESOLVER_20111126

#include <memory>
#include <network/protocol/http/client/connection/resolver_delegate.hpp>

namespace network {
namespace http {

struct async_resolver_pimpl;

struct async_resolver : resolver_delegate {
  using resolver_delegate::resolve_completion_function;

  async_resolver(boost::asio::io_service & service, bool cache_resolved);
  virtual void resolve(std::string const & host,
                       uint16_t port,
                       resolve_completion_function once_resolved);  // override
  virtual void clear_resolved_cache();  // override
  virtual ~async_resolver();

 protected:
  // We need a shared_ptr because the pimpl may live on long after the resolver
  // delegate (instances of this type) is actually destroyed.
  std::shared_ptr<async_resolver_pimpl> pimpl;
};

} // namespace http

} // namespace network

#endif // NETWORK_PROTOCOL_HTTP_CLIENT_CONNECTION_ASYNC_RESOLVER_20111126
