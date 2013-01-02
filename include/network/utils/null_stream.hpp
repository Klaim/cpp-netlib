// Copyright 2012 Rob J Meijer. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_UTILS_NULL_STREAM_HPP
#define NETWORK_UTILS_NULL_STREAM_HPP
#include <streambuf>

namespace network { namespace utils {

template <typename CharType,typename traits=std::char_traits<CharType> >
class nullstreambuf : public std::basic_streambuf<CharType,traits > {
  public:
   typename traits::int_type overflow(typename traits::int_type c) { return c; }
};

}  // namespace utils
}  // namespace network

#endif /* NETWORK_UTILS_NULL_STREAM_HPP */
