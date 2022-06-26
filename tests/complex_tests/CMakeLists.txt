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

project(complex_tests LANGUAGES CXX)

set(test_apps
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
    complex_exp_time_test
    complex_expf_time_test
    complex_expl_time_test
)
foreach(app ${test_apps})
    add_executable(${app} ${app}.c)
    set_target_properties(
        ${app}
        PROPERTY
        C_STANDARD
        99
        INTERPROCEDURAL_OPTIMIZATION
        ${IPO_SUPPORTED}
    )
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(
        ${app}
        PRIVATE rss::librssringoccs rss::librssringoccs_compare
    )
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

set(cerf_apps
    complex_erf_time_test
    complex_erfc_time_test
    complex_faddeeva_tests
)
foreach(app ${cerf_apps})
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
    target_include_directories(${app} PRIVATE ${cerf_INCLUDE_DIRECTORY})
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(
        ${app}
        PRIVATE
            rss::librssringoccs
            rss::librssringoccs_compare
            $<IF:$<BOOL:${CERF_CPP}>,cerfcpp,cerf>
    )
    if(MSVC)
        target_compile_options(${app} PRIVATE /DCERF_AS_CPP)
    else()
        if(CERF_CPP)
            target_compile_options(${app} PRIVATE -DCERF_AS_CPP)
        endif()
    endif()
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

include(GNUInstallDirs)
install(
    TARGETS
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
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
