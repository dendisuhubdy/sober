# Copyright (c) 2014, Ruslan Baratov
# All rights reserved.

if(DEFINED SOBER_NETWORK_HTTP_RESPONSE_ATTRIBUTE_SUGAR_CMAKE_)
  return()
else()
  set(SOBER_NETWORK_HTTP_RESPONSE_ATTRIBUTE_SUGAR_CMAKE_ 1)
endif()

include(sugar_files)

sugar_files(
    SOBER_SOURCES
    ChunkSize.hpp
    ContentLength.hpp
    ReasonPhrase.hpp
    Response.hpp
    StatusCode.hpp
    StatusLine.hpp
    TEXT.hpp
    TransferEncoding.hpp
)
