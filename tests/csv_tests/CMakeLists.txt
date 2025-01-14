cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
    elseif(UNIX)
        include(gcc)
    endif()
endif()

include(FetchCerf)

project(csv_tests)

set(test_apps test_get_dlp_csv test_get_geo_csv test_get_tau_csv)
foreach(app ${test_apps})
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    add_executable(${app} ${app}.c)
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(
        ${app}
        PRIVATE rss::librssringoccs rss::librssringoccs_compare
    )
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()
