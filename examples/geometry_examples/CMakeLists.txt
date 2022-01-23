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

project(geometry_examples)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(euclidean_norm_3d_example euclidean_norm_3d_example.c)
target_link_libraries(euclidean_norm_3d_example PRIVATE librssringoccs)