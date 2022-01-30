cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()


project(special_functions_plots_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(bessel_i0_plots bessel_i0_plots.c)
target_link_libraries(bessel_i0_plots PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(bessel_j0_plots bessel_j0_plots.c)
target_link_libraries(bessel_j0_plots PRIVATE rss::librssringoccs rss::librssringoccs_compare)
