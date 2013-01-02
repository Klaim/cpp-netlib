// Copyright 2011 Dean Michael Berris (dberris@google.com).
// Copyright 2011 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This is the conglomeration of all message-related implementation files. All
// we're doing is including all the .ipp files that are relevant.

#ifdef NETWORK_NO_LIB
#undef NETWORK_NO_LIB
#endif

#include <network/message/message.ipp>
#include <network/message/message_base.ipp>
