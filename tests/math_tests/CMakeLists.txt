cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(math_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

set(test_apps
    abs_time_test
    absf_time_test
    absl_time_test
    copysign_time_test
    sin_time_test
    sinf_time_test
    sinl_time_test
)
foreach(app ${test_apps})
    add_executable(${app} ${app}.c)
    target_link_libraries(${app} PRIVATE rss::librssringoccs rss::librssringoccs_compare)
endforeach()

set(cerf_apps
    faddeeva_im_time_test
)
foreach(app ${cerf_apps})
    add_executable(${app} ${app}.c)
    target_include_directories(${app} PRIVATE ${cerf_INCLUDE_DIRECTORY})
    target_link_libraries(${app} PRIVATE rss::librssringoccs rss::librssringoccs_compare ${cerf_LIBRARY})
endforeach()

include(GNUInstallDirs)
install(TARGETS
    abs_time_test
    absf_time_test
    absl_time_test
    copysign_time_test
    faddeeva_im_time_test
    sin_time_test
    sinf_time_test
    sinl_time_test
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)