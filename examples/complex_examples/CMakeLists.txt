cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
    elseif(UNIX)
        include(gcc)
    endif()
endif()

project(complex_examples)

set(apps
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
)

foreach(app ${apps})
    add_executable(${app} ${app}.c)
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(${app} PRIVATE rss::librssringoccs)
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

include(GNUInstallDirs)
install(
    TARGETS ${apps}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
