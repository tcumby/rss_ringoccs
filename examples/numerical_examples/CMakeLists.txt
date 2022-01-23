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

project(numerical_examples)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(five_point_derivative_example five_point_derivative_example.c)
target_link_libraries(five_point_derivative_example PRIVATE librssringoccs)

add_executable(newton_rapshon_bessel_function newton_rapshon_bessel_function.c)
target_link_libraries(newton_rapshon_bessel_function PRIVATE librssringoccs)