cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
    elseif(UNIX)
        include(gcc)
    endif()
endif()

project(complex_plots LANGUAGES CXX)

set(apps
    complex_cos_plots
    complex_erf_plots
    complex_erfc_plots
    complex_exp_plots
    complex_log_plots
    complex_sin_plots
    complex_sqrt_plots
)

foreach(app ${apps})
    add_executable(${app} ${app}.c)
    set_property(TARGET ${app} PROPERTY C_STANDARD 99)
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(${app} PRIVATE rss::librssringoccs)
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

include(FetchCerf)
set(cerf_apps complex_faddeeva_plots)
foreach(app ${cerf_apps})
    add_executable(${app} ${app}.c)
    set_property(TARGET ${app} PROPERTY C_STANDARD 99)
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
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
    TARGETS ${apps} ${cerf_apps}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
