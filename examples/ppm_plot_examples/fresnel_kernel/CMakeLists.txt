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

project(fresnel_kernel)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(stationary_phase_plot stationary_phase_plot.c)
target_link_libraries(stationary_phase_plot PRIVATE librssringoccs)
