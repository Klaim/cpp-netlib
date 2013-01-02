// Copyright 2010 Dean Michael Berris. 
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef NETWORK_PROTOCOL_HTTP_SERVER_REQUEST_PARSER_HPP_20101005
#define NETWORK_PROTOCOL_HTTP_SERVER_REQUEST_PARSER_HPP_20101005

#include <utility>
#include <boost/range/iterator_range.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace network { namespace http {

    struct request_parser {

        enum state_t {
            method_start
            , method_char
            , method_done
            , uri_char
            , uri_done
            , version_h
            , version_t1
            , version_t2
            , version_p
            , version_slash
            , version_d1
            , version_dot
            , version_d2
            , version_cr
            , version_done
            , header_name
            , header_colon
            , header_value
            , header_cr
            , header_line_done
            , headers_cr
            , headers_done
        };

        explicit request_parser(state_t start_state = method_start)
        : internal_state(start_state)
        {}

        void reset(state_t start_state = method_start) {
            internal_state = method_start;
        }

        state_t state() const { return internal_state; }

        template <class Range>
        boost::fusion::tuple<boost::logic::tribool, boost::iterator_range<typename Range::const_iterator> >
        parse_until(state_t stop_state, Range & range) {
            boost::logic::tribool parsed_ok = boost::logic::indeterminate;
            typedef typename boost::range_iterator<Range>::type iterator;
            iterator start = boost::begin(range)
                    , end  = boost::end(range)
                    , current_iterator = start;
            boost::iterator_range<iterator> local_range = 
                boost::make_iterator_range(start, end);
            while (
                !boost::empty(local_range)
                && stop_state != internal_state
                && indeterminate(parsed_ok)
            ) {
                current_iterator = boost::begin(local_range);
                switch(internal_state) {
                    case method_start:
                        if (boost::algorithm::is_upper()(*current_iterator)) internal_state = method_char;
                        else parsed_ok = false;
                        break;
                    case method_char:
                        if (boost::algorithm::is_upper()(*current_iterator)) break;
                        else if (boost::algorithm::is_space()(*current_iterator)) internal_state = method_done;
                        else parsed_ok = false;
                        break;
                    case method_done:
                        if (boost::algorithm::is_cntrl()(*current_iterator)) parsed_ok = false;
                        else if (boost::algorithm::is_space()(*current_iterator)) parsed_ok = false;
                        else internal_state = uri_char;
                        break;
                    case uri_char:
                        if (boost::algorithm::is_cntrl()(*current_iterator)) parsed_ok = false;
                        else if (boost::algorithm::is_space()(*current_iterator)) internal_state = uri_done;
                        break;
                    case uri_done:
                        if (*current_iterator == 'H') internal_state = version_h;
                        else parsed_ok = false;
                        break;
                    case version_h:
                        if (*current_iterator == 'T') internal_state = version_t1;
                        else parsed_ok = false;
                        break;
                    case version_t1:
                        if (*current_iterator == 'T') internal_state = version_t2;
                        else parsed_ok = false;
                        break;
                    case version_t2:
                        if (*current_iterator == 'P') internal_state = version_p;
                        else parsed_ok = false;
                        break;
                    case version_p:
                        if (*current_iterator == '/') internal_state = version_slash;
                        else parsed_ok = false;
                        break;
                    case version_slash:
                        if (boost::algorithm::is_digit()(*current_iterator)) internal_state = version_d1;
                        else parsed_ok = false;
                        break;
                    case version_d1:
                        if (*current_iterator == '.') internal_state = version_dot;
                        else parsed_ok = false;
                        break;
                    case version_dot:
                        if (boost::algorithm::is_digit()(*current_iterator)) internal_state = version_d2;
                        else parsed_ok = false;
                        break;
                    case version_d2:
                        if (*current_iterator == '\r') internal_state = version_cr;
                        else parsed_ok = false;
                        break;
                    case version_cr:
                        if (*current_iterator == '\n') internal_state = version_done;
                        else parsed_ok = false;
                        break;
                    case version_done:
                        if (boost::algorithm::is_alnum()(*current_iterator)) internal_state = header_name;
                        else if (*current_iterator == '\r') internal_state = headers_cr;
                        else parsed_ok = false;
                        break;
                    case header_name:
                        if (*current_iterator == ':') internal_state = header_colon;
                        else if (boost::algorithm::is_alnum()(*current_iterator) || boost::algorithm::is_punct()(*current_iterator)) break;
                        else parsed_ok = false;
                        break;
                    case header_colon:
                        if (*current_iterator == ' ') internal_state = header_value;
                        else parsed_ok = false;
                        break;
                    case header_value:
                        if (*current_iterator == '\r') internal_state = header_cr;
                        else if (boost::algorithm::is_cntrl()(*current_iterator)) parsed_ok = false;
                        break;
                    case header_cr:
                        if (*current_iterator == '\n') internal_state = header_line_done;
                        else parsed_ok = false;
                        break;
                    case header_line_done:
                        if (*current_iterator == '\r') internal_state = headers_cr;
                        else if (boost::algorithm::is_alnum()(*current_iterator)) internal_state = header_name;
                        else parsed_ok = false;
                        break;
                    case headers_cr:
                        if (*current_iterator == '\n') internal_state = headers_done;
                        else parsed_ok = false;
                        break;
                    case headers_done:
                        // anything that follows after headers_done is allowed.
                        break;
                    default:
                        parsed_ok = false;
                };
                if (internal_state == stop_state) parsed_ok = true;
                local_range = boost::make_iterator_range(
                    ++current_iterator, end);
            }
            return boost::fusion::make_tuple(
                parsed_ok, 
                boost::make_iterator_range(
                    start, current_iterator
                )
                );
        }

    private:
        state_t internal_state;

    };
    
}  // namespace http
}  // namespace network
    
#endif /* NETWORK_PROTOCOL_HTTP_SERVER_REQUEST_PARSER_HPP_20101005 */
