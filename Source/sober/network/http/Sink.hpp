#ifndef SOBER_NETWORK_HTTP_SINK_HPP_
#define SOBER_NETWORK_HTTP_SINK_HPP_

// Copyright (c) 2014, Ruslan Baratov
// All rights reserved.

#include <sober/network/http/Sink.fpp>

#include <cstddef> // std::size_t

namespace sober {
namespace network {
namespace http {

class Sink {
 public:
  virtual void clear() =0;
  virtual void write(const char* buffer, std::size_t size, bool finish) =0;
};

} // namespace http
} // namespace network
} // namespace sober

#endif // SOBER_NETWORK_HTTP_SINK_HPP_
