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

set(test_apps linear_interpolate_plot sin_interpolate_plot)

foreach(app ${test_apps})
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    add_executable(${app} ${app}.c)
    set_target_properties(
        ${app}
        PROPERTY
        C_STANDARD
        99
        INTERPROCEDURAL_OPTIMIZATION
        ${IPO_SUPPORTED}
    )
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(
        ${app}
        PRIVATE rss::librssringoccs rss::librssringoccs_compare
    )
    target_include_directories(${app} PRIVATE "${GSL_INCLUDE_DIRS}")
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()
