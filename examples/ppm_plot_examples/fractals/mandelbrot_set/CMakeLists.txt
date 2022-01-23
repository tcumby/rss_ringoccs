cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(mandlebrot_set)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

add_executable(mandelbrot_general mandelbrot_general.c)
target_link_libraries(mandelbrot_general PRIVATE librssringoccs)

add_executable(mandelbrot_quartic mandelbrot_quartic.c)
target_link_libraries(mandelbrot_quartic PRIVATE librssringoccs)

add_executable(mandelbrot_set mandelbrot_set.c)
target_link_libraries(mandelbrot_set PRIVATE librssringoccs)
