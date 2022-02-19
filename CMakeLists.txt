cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (WIN32)
    # We use vcpkg to retrieve a build of GSL for Windows
    include(FetchVcpkg)
    set(CMAKE_TOOLCHAIN_FILE ${vcpkg_toolchain_file} CACHE STRING "Vcpkg toolchain file")
endif()
endif()

option(BUILD_EXAMPLES "Build all examples" TRUE)
option(BUILD_TESTS "Build all tests" TRUE)

project(rss_ringoccs)

add_subdirectory("librssringoccs")

if (BUILD_EXAMPLES)
add_subdirectory("examples")
endif()

if (BUILD_TESTS)
add_subdirectory("tests")
endif()