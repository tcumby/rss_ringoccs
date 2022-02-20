cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

include(FetchGSL)
project(special_functions_plots_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

include(CMakePrintHelpers)
set(test_apps
    bessel_i0_plots
    bessel_j0_plots
)
foreach(app ${test_apps})
    add_executable(${app} ${app}.c)
    target_include_directories(${app} PRIVATE "$<TARGET_PROPERTY:GSL::gsl,INTERFACE_INCLUDE_DIRECTORIES>")
    target_link_libraries(${app} PRIVATE rss::librssringoccs rss::librssringoccs_compare GSL::gsl)
endforeach()

