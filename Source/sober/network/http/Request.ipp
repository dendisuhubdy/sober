#ifndef SOBER_NETWORK_HTTP_REQUEST_IPP_
#define SOBER_NETWORK_HTTP_REQUEST_IPP_

// Copyright (c) 2014, Ruslan Baratov
// All rights reserved.

#include <sober/network/http/Request.hpp>

namespace sober {
namespace network {
namespace http {

template <class Handler>
void Request::async_write(Socket& socket, Handler&& handler) {
  fill_streambuf();
  assert(request_.size() != 0);
  boost::asio::async_write(socket, request_, handler);
}

} // namespace http
} // namespace network
} // namespace sober

#endif // SOBER_NETWORK_HTTP_REQUEST_IPP_
