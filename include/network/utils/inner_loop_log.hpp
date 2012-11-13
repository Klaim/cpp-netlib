// Copyright 2012 Rob J Meijer. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_UTILS_INNER_LOOP_LOG_HPP
#ifdef INNER_LOOP_DEBUG
#  ifndef INNER_LOOP_LOG
#    define INNER_LOOP_LOG(msg) this->log() <<  msg << std::endl;
#  endif
#else
#  ifndef INNER_LOOP_LOG
#    define INNER_LOOP_LOG(msg)
#  endif
#endif
#endif /* INNER_LOOP_LOG */
