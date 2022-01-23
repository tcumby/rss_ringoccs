cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(complex_examples)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(complex_abs_example complex_abs_example.c)
add_executable(complex_abs_squared_example complex_abs_squared_example.c)
add_executable(complex_absf_example complex_absf_example.c)
add_executable(complex_absf_squared_example complex_absf_squared_example.c)
add_executable(complex_absl_example complex_absl_example.c)
add_executable(complex_absl_squared_example complex_absl_squared_example.c)
add_executable(complex_add_example complex_add_example.c)
add_executable(complex_add_imag_example complex_add_imag_example.c)
add_executable(complex_add_imagf_example complex_add_imagf_example.c)
add_executable(complex_add_imagl_example complex_add_imagl_example.c)
add_executable(complex_add_real_example complex_add_real_example.c)
add_executable(complex_add_realf_example complex_add_realf_example.c)
add_executable(complex_add_reall_example complex_add_reall_example.c)
add_executable(complex_addf_example complex_addf_example.c)
add_executable(complex_addl_example complex_addl_example.c)
add_executable(complex_argument_example complex_argument_example.c)
add_executable(complex_argumentf_example complex_argumentf_example.c)
add_executable(complex_argumentl_example complex_argumentl_example.c)
add_executable(complex_compare_example complex_compare_example.c)
add_executable(complex_comparef_example complex_comparef_example.c)
add_executable(complex_comparel_example complex_comparel_example.c)
add_executable(complex_conjugate_example complex_conjugate_example.c)
add_executable(complex_conjugatef_example complex_conjugatef_example.c)
add_executable(complex_conjugatel_example complex_conjugatel_example.c)
add_executable(complex_cos_example complex_cos_example.c)
add_executable(complex_cosf_example complex_cosf_example.c)
add_executable(complex_cosl_example complex_cosl_example.c)
add_executable(complex_dist_example complex_dist_example.c)
add_executable(complex_distf_example complex_distf_example.c)
add_executable(complex_distl_example complex_distl_example.c)
add_executable(complex_divide_example complex_divide_example.c)
add_executable(complex_dividef_example complex_dividef_example.c)
add_executable(complex_dividel_example complex_dividel_example.c)
add_executable(complex_exp_example complex_exp_example.c)

target_link_libraries(complex_abs_example PRIVATE librssringoccs)
target_link_libraries(complex_abs_squared_example PRIVATE librssringoccs)
target_link_libraries(complex_absf_example PRIVATE librssringoccs)
target_link_libraries(complex_absf_squared_example PRIVATE librssringoccs)
target_link_libraries(complex_absl_example PRIVATE librssringoccs)
target_link_libraries(complex_absl_squared_example PRIVATE librssringoccs)
target_link_libraries(complex_add_example PRIVATE librssringoccs)
target_link_libraries(complex_add_imag_example PRIVATE librssringoccs)
target_link_libraries(complex_add_imagf_example PRIVATE librssringoccs)
target_link_libraries(complex_add_imagl_example PRIVATE librssringoccs)
target_link_libraries(complex_add_real_example PRIVATE librssringoccs)
target_link_libraries(complex_add_realf_example PRIVATE librssringoccs)
target_link_libraries(complex_add_reall_example PRIVATE librssringoccs)
target_link_libraries(complex_addf_example PRIVATE librssringoccs)
target_link_libraries(complex_addl_example PRIVATE librssringoccs)
target_link_libraries(complex_argument_example PRIVATE librssringoccs)
target_link_libraries(complex_argumentf_example PRIVATE librssringoccs)
target_link_libraries(complex_argumentl_example PRIVATE librssringoccs)
target_link_libraries(complex_compare_example PRIVATE librssringoccs)
target_link_libraries(complex_comparef_example PRIVATE librssringoccs)
target_link_libraries(complex_comparel_example PRIVATE librssringoccs)
target_link_libraries(complex_conjugate_example PRIVATE librssringoccs)
target_link_libraries(complex_conjugatef_example PRIVATE librssringoccs)
target_link_libraries(complex_conjugatel_example PRIVATE librssringoccs)
target_link_libraries(complex_cos_example PRIVATE librssringoccs)
target_link_libraries(complex_cosf_example PRIVATE librssringoccs)
target_link_libraries(complex_cosl_example PRIVATE librssringoccs)
target_link_libraries(complex_dist_example PRIVATE librssringoccs)
target_link_libraries(complex_distf_example PRIVATE librssringoccs)
target_link_libraries(complex_distl_example PRIVATE librssringoccs)
target_link_libraries(complex_divide_example PRIVATE librssringoccs)
target_link_libraries(complex_dividef_example PRIVATE librssringoccs)
target_link_libraries(complex_dividel_example PRIVATE librssringoccs)
target_link_libraries(complex_exp_example PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    complex_abs_example
    complex_abs_squared_example
    complex_absf_example
    complex_absf_squared_example
    complex_absl_example
    complex_absl_squared_example
    complex_add_example
    complex_add_imag_example
    complex_add_imagf_example
    complex_add_imagl_example
    complex_add_real_example
    complex_add_realf_example
    complex_add_reall_example
    complex_addf_example
    complex_addl_example
    complex_argument_example
    complex_argumentf_example
    complex_argumentl_example
    complex_compare_example
    complex_comparef_example
    complex_comparel_example
    complex_conjugate_example
    complex_conjugatef_example
    complex_conjugatel_example
    complex_cos_example
    complex_cosf_example
    complex_cosl_example
    complex_dist_example
    complex_distf_example
    complex_distl_example
    complex_divide_example
    complex_dividef_example
    complex_dividel_example
    complex_exp_example
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)