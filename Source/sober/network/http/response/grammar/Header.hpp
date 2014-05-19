#ifndef SOBER_NETWORK_HTTP_RESPONSE_GRAMMAR_HEADER_HPP_
#define SOBER_NETWORK_HTTP_RESPONSE_GRAMMAR_HEADER_HPP_

// Copyright (c) 2014, Ruslan Baratov
// All rights reserved.

#include <boost/spirit/home/qi.hpp>
#include <boost/phoenix.hpp>

#include <boost/spirit/home/qi/nonterminal/grammar.hpp>
#include <boost/spirit/home/support/common_terminals.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>

#include <sober/network/http/response/attribute/Header.hpp>
#include <sober/network/http/response/grammar/CR.hpp>
#include <sober/network/http/response/grammar/CRLF.hpp>
#include <sober/network/http/response/grammar/ContentLength.hpp>
#include <sober/network/http/response/grammar/StatusLine.hpp>
#include <sober/network/http/response/grammar/TransferEncoding.hpp>

namespace sober {
namespace network {
namespace http {
namespace response {
namespace grammar {

// 6 Response
// Header = Response without message-body
template <class Iterator>
struct Header: qi::grammar<Iterator, attribute::Header()> {
  using Base = qi::grammar<Iterator, attribute::Header()>;

  Header(): Base(header) {
    namespace ph = boost::phoenix;
    using qi::_val;
    using qi::_1;
    using ph::at_c;

    // Header:
    // at_c<0> StatusLine status_line;
    // at_c<1> ContentLength content_length;
    // at_c<2> TransferEncoding transfer_encoding;

    any_header = +(qi::char_ - cr);

    header = qi::eps[at_c<1>(_val) = 0] >>
        qi::eps[at_c<2>(_val) = attribute::TransferEncoding::OTHER] >>
        status_line[at_c<0>(_val) = _1] >>
        // 7.1 Entity Header Fields (simplified version) --
        +(
            (
                content_length[at_c<1>(_val) = _1] |
                transfer_encoding[at_c<2>(_val) = _1] |
                any_header
            ) >> crlf
        ) >>
        // --
        crlf;
    ;
  }

  StatusLine<Iterator> status_line;
  ContentLength<Iterator> content_length;
  TransferEncoding<Iterator> transfer_encoding;
  CR<Iterator> cr;
  CRLF<Iterator> crlf;

  qi::rule<Iterator, void()> any_header;

  qi::rule<Iterator, attribute::Header()> header;
};

} // namespace grammar
} // namespace response
} // namespace http
} // namespace network
} // namespace sober

#endif // SOBER_NETWORK_HTTP_RESPONSE_GRAMMAR_HEADER_HPP_