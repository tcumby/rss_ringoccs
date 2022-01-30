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

add_executable(abs_time_test abs_time_test.c)
target_link_libraries(abs_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(absf_time_test absf_time_test.c)
target_link_libraries(absf_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(absl_time_test absl_time_test.c)
target_link_libraries(absl_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(copysign_time_test copysign_time_test.c)
target_link_libraries(copysign_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(faddeeva_im_time_test faddeeva_im_time_test.c)
target_link_libraries(faddeeva_im_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(sin_time_test sin_time_test.c)
target_link_libraries(sin_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(sinf_time_test sinf_time_test.c)
target_link_libraries(sinf_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(sinl_time_test sinl_time_test.c)
target_link_libraries(sinl_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

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