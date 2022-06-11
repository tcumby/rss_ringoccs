cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# We use vcpkg to retrieve a build of GSL
include(FetchVcpkg)
set(CMAKE_TOOLCHAIN_FILE ${vcpkg_toolchain_file}
    CACHE STRING "Vcpkg toolchain file"
)
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

if(SKBUILD)
    message(STATUS "The project is built using scikit-build")
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    elseif(UNIX)
        include(gcc)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    elseif(WIN32)
        if(MSVC)
            # Compile as C++ for Microsoft Visual Studio to avoid the non-standard complex number implementation in the
            # C compiler
            list(APPEND CMAKE_CXX_SOURCE_FILE_EXTENSIONS c)
            enable_language(CXX)
            set(CMAKE_CXX_STANDARD 11)
            set(CMAKE_GENERATOR_PLATFORM x64 CACHE INTERNAL "")
            target_compile_options(<target> PRIVATE "/MP")
        endif()
    endif()
endif()

option(BUILD_EXAMPLES "Build all examples" TRUE)
option(BUILD_TESTS "Build all tests" TRUE)

set(RSS_RINGOCCS_PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "" FORCE)
set(RSS_RINGOCCS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "" FORCE)

project(rss_ringoccs)

add_subdirectory("librssringoccs")
add_subdirectory("rss_ringoccs")

if(BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()

if(BUILD_TESTS)
    add_subdirectory("tests")
endif()
