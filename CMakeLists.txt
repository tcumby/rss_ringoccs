cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

option(BUILD_EXAMPLES "Build all examples" FALSE)
option(BUILD_TESTS "Build all tests" TRUE)

project(rss_ringoccs)

add_subdirectory("librssringoccs")

if (BUILD_EXAMPLES)
add_subdirectory("examples")
endif()

if (BUILD_TESTS)
add_subdirectory("tests")
endif()