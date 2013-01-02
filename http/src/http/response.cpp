// Copyright 2011 Dean Michael Berris <dberris@google.com>.
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifdef NETWORK_NO_LIB
#undef NETWORK_NO_LIB
#endif

#include <network/protocol/http/response/response_base.ipp>
#include <network/protocol/http/response/response.ipp>

#include <network/protocol/http/message/wrappers/status.ipp>
#include <network/protocol/http/message/wrappers/status_message.ipp>
#include <network/protocol/http/message/wrappers/version.ipp>
