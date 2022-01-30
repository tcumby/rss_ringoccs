cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

include(FetchCerf)

project(complex_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(complex_abs_squared_alt_time_test complex_abs_squared_alt_time_test.c)
target_link_libraries(complex_abs_squared_alt_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_abs_squared_time_test complex_abs_squared_time_test.c)
target_link_libraries(complex_abs_squared_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_abs_time_test complex_abs_time_test.c)
target_link_libraries(complex_abs_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_absf_squared_time_test complex_absf_squared_time_test.c)
target_link_libraries(complex_absf_squared_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_absf_time_test complex_absf_time_test.c)
target_link_libraries(complex_absf_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_absl_squared_time_test complex_absl_squared_time_test.c)
target_link_libraries(complex_absl_squared_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_absl_time_test complex_absl_time_test.c)
target_link_libraries(complex_absl_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_argument_time_test complex_argument_time_test.c)
target_link_libraries(complex_argument_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_argumentf_time_test complex_argumentf_time_test.c)
target_link_libraries(complex_argumentf_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_argumentl_time_test complex_argumentl_time_test.c)
target_link_libraries(complex_argumentl_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_conjugate_alt_time_test complex_conjugate_alt_time_test.c)
target_link_libraries(complex_conjugate_alt_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_conjugate_time_test complex_conjugate_time_test.c)
target_link_libraries(complex_conjugate_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_conjugatef_time_test complex_conjugatef_time_test.c)
target_link_libraries(complex_conjugatef_time_test  PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_conjugatel_time_test complex_conjugatel_time_test.c)
target_link_libraries(complex_conjugatel_time_test  PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_cos_time_test complex_cos_time_test.c)
target_link_libraries(complex_cos_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_cosf_time_test complex_cosf_time_test.c)
target_link_libraries(complex_cosf_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_cosl_time_test complex_cosl_time_test.c)
target_link_libraries(complex_cosl_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_dist_time_test complex_dist_time_test.c)
target_link_libraries(complex_dist_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_distf_time_test complex_distf_time_test.c)
target_link_libraries(complex_distf_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_distl_time_test complex_distl_time_test.c)
target_link_libraries(complex_distl_time_test   PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_divide_time_test complex_divide_time_test.c)
target_link_libraries(complex_divide_time_test  PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_dividef_time_test complex_dividef_time_test.c)
target_link_libraries(complex_dividef_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_dividel_time_test complex_dividel_time_test.c)
target_link_libraries(complex_dividel_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_erf_time_test complex_erf_time_test.c)
target_link_libraries(complex_erf_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare cerf_LIBRARY)

add_executable(complex_erfc_time_test complex_erfc_time_test.c)
target_link_libraries(complex_erfc_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare cerf_LIBRARY)

add_executable(complex_exp_time_test complex_exp_time_test.c)
target_link_libraries(complex_exp_time_test PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_expf_time_test complex_expf_time_test.c)
target_link_libraries(complex_expf_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_expl_time_test complex_expl_time_test.c)
target_link_libraries(complex_expl_time_test    PRIVATE rss::librssringoccs rss::librssringoccs_compare)

add_executable(complex_faddeeva_tests complex_faddeeva_tests.c)
target_link_libraries(complex_faddeeva_tests    PRIVATE rss::librssringoccs rss::librssringoccs_compare cerf_LIBRARY)

include(GNUInstallDirs)
install(TARGETS
    complex_abs_squared_alt_time_test
    complex_abs_squared_time_test
    complex_abs_time_test
    complex_absf_squared_time_test
    complex_absf_time_test
    complex_absl_squared_time_test
    complex_absl_time_test
    complex_argument_time_test
    complex_argumentf_time_test
    complex_argumentl_time_test
    complex_conjugate_alt_time_test
    complex_conjugate_time_test
    complex_conjugatef_time_test
    complex_conjugatel_time_test
    complex_cos_time_test
    complex_cosf_time_test
    complex_cosl_time_test
    complex_dist_time_test
    complex_distf_time_test
    complex_distl_time_test
    complex_divide_time_test
    complex_dividef_time_test
    complex_dividel_time_test
    complex_erf_time_test
    complex_erfc_time_test
    complex_exp_time_test
    complex_expf_time_test
    complex_expl_time_test
    complex_faddeeva_tests
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)