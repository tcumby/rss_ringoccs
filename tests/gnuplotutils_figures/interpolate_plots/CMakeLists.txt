cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
    elseif(UNIX)
        include(gcc)
    endif()
endif()

include(FetchGSL)

project(interpolate_plots_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

set(test_apps linear_interpolate_plot sin_interpolate_plot)
foreach(app ${test_apps})
    add_executable(${app} ${app}.c)
    target_link_libraries(
        ${app}
        PRIVATE rss::librssringoccs rss::librssringoccs_compare
    )
    target_include_directories(${app} PRIVATE "${GSL_INCLUDE_DIRS}")
endforeach()
