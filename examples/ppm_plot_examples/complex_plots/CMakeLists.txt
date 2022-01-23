cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(complex_plots)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(complex_cos_plots complex_cos_plots.c)
target_link_libraries(complex_cos_plots PRIVATE librssringoccs)

add_executable(complex_erf_plots complex_erf_plots.c)
target_link_libraries(complex_erf_plots PRIVATE librssringoccs)

add_executable(complex_erfc_plots complex_erfc_plots.c)
target_link_libraries(complex_erfc_plots PRIVATE librssringoccs)

add_executable(complex_exp_plots complex_exp_plots.c)
target_link_libraries(complex_exp_plots PRIVATE librssringoccs)

add_executable(complex_faddeeva_plots complex_faddeeva_plots.c)
target_link_libraries(complex_faddeeva_plots PRIVATE librssringoccs)

add_executable(complex_log_plots complex_log_plots.c)
target_link_libraries(complex_log_plots PRIVATE librssringoccs)

add_executable(complex_sin_plots complex_sin_plots.c)
target_link_libraries(complex_sin_plots PRIVATE librssringoccs)

add_executable(complex_sqrt_plots complex_sqrt_plots.c)
target_link_libraries(complex_sqrt_plots PRIVATE librssringoccs)
