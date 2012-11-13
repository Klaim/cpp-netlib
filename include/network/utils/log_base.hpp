// Copyright 2012 Rob J Meijer. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_UTILS_LOG_BASE_HPP
#define NETWORK_UTILS_LOG_BASE_HPP
#include <iostream>
#include <network/utils/null_stream.hpp>

namespace network { namespace utils {

template <typename CharType>
struct basic_log_base {
  static std::basic_ostream<CharType> *sLogStream;
  nullstreambuf<CharType> mNullStreamBuff;
  std::basic_ostream<CharType> mNullStream;
  std::basic_ostream<CharType> *mLogStream;
 protected:
  basic_log_base():mNullStreamBuff(),mNullStream(&mNullStreamBuff),mLogStream(sLogStream ? sLogStream : &mNullStream){}
  basic_log_base(std::basic_ostream<CharType> &logstream):mNullStreamBuff(),mNullStream(&mNullStreamBuff),mLogStream(&logstream){}
  std::basic_ostream<CharType> &log() { return *mLogStream;}
 public:
  static void initializeDefaultLogStream(std::basic_ostream<CharType> &logstream){
     sLogStream = &logstream;
  }
};

typedef basic_log_base<char> log_base;
//typedef basic_log_base<wchar_t> wlog_base;
//typedef basic_log_base<char16_t> log16_base;
//typedef basic_log_base<char32_t> log32_base;

}  // namespace utils
}  // namespace network

#endif /* NETWORK_UTILS_LOG_BASE_HPP */
