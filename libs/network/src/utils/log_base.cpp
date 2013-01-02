// Copyright 2012 Rob J Meijer. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <network/utils/log_base.hpp>

namespace network { namespace utils {

template <>
std::basic_ostream<char> *basic_log_base<char>::sLogStream=0;

}}
