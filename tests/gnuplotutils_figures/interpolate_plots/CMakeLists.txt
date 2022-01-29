cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()


project(interpolate_plots_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(linear_interpolate_plot linear_interpolate_plot.c)
target_link_libraries(linear_interpolate_plot PRIVATE librssringoccs librssringoccs_compare)

add_executable(sin_interpolate_plot sin_interpolate_plot.c)
target_link_libraries(sin_interpolate_plot PRIVATE librssringoccs librssringoccs_compare)


