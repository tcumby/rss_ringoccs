cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CompilerOptions)

# We use vcpkg to retrieve a build of GSL
include(FetchVcpkg)
set(CMAKE_TOOLCHAIN_FILE ${vcpkg_toolchain_file}
    CACHE STRING "Vcpkg toolchain file"
)
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

if(SKBUILD)
    message(STATUS "The project is built using scikit-build")
endif()

if(DEFINED ENV{GITHUB_ENV})
    message(STATUS "The project is being built via Github CI")

    # Stop Python lookup as soon as a version satisfying version constraints is founded
    set(Python_FIND_STRATEGY "LOCATION")

    # Windows only: Perform lookup via environment variables before inspecting the registry
    set(Python_FIND_REGISTRY "LAST")

    # macOS only: look for a matching Python version in the form of a framework
    set(Python_FIND_FRAMEWORK "LAST")
endif()

option(BUILD_EXAMPLES "Build all examples" TRUE)
option(BUILD_TESTS "Build all tests" TRUE)

set(RSS_RINGOCCS_PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "" FORCE)
set(RSS_RINGOCCS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "" FORCE)

project(rss_ringoccs)

if(MSVC)
    enable_language(CXX)
else()
    enable_language(C)
endif()

cmake_policy(SET CMP0069 NEW)
include(CheckIPOSupported)
# Optional IPO. Do not use IPO if it's not supported by compiler.
check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT IPO_CHECK_OUTPUT)
if(IPO_SUPPORTED)
    message(
        STATUS
        "Interprocedural Optimization/Link-Time Optimization is supported."
    )
else()
    message(
        WARNING
        "Interprocedural Optimization/Link-Time Optimization is not supported: ${IPO_CHECK_OUTPUT}"
    )
endif()

add_subdirectory("librssringoccs")
add_subdirectory("rss_ringoccs")

if(BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()

if(BUILD_TESTS)
    add_subdirectory("tests")
endif()
