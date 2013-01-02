// Copyright Dean Michael Berris 2007.
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_MESSAGE_TRANSFORMERS_SELECTORS_HPP
#define NETWORK_MESSAGE_TRANSFORMERS_SELECTORS_HPP

namespace network {
namespace selectors {
struct source_selector;
struct destination_selector;
} // namespace selectors

selectors::source_selector source_(selectors::source_selector);
selectors::destination_selector destination_(selectors::destination_selector);

namespace selectors {

struct source_selector {
 private:
  source_selector() {};
  source_selector(source_selector const &) {};
  friend source_selector network::source_(source_selector);
};

struct destination_selector {
 private:
  destination_selector() {};
  destination_selector(destination_selector const &) {};
  friend destination_selector network::destination_(destination_selector);
};

} // namespace selectors

typedef selectors::source_selector (*source_selector_t)(selectors::source_selector);
typedef selectors::destination_selector (*destination_selector_t)(selectors::destination_selector);

inline selectors::source_selector source_(selectors::source_selector) {
    return selectors::source_selector();
}

inline selectors::destination_selector destination_(selectors::destination_selector) {
    return selectors::destination_selector();
}

} // namespace network

#endif // NETWORK_MESSAGE_TRANSFORMERS_SELECTORS_HPP
