cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(complex_plots LANGUAGES CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

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
    target_link_libraries(${app} PRIVATE rss::librssringoccs)
endforeach()

include(GNUInstallDirs)
install(TARGETS
    ${apps}
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)

include(FetchCerf)
set(cerf_apps
    complex_faddeeva_plots
)
foreach(app ${cerf_apps})
    add_executable(${app} ${app}.c)
    set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    target_include_directories(${app} PRIVATE ${cerf_INCLUDE_DIRECTORY})
    target_link_libraries(${app} PRIVATE rss::librssringoccs rss::librssringoccs_compare ${cerf_LIBRARY})
    if(MSVC)
        target_compile_options(${app} PRIVATE /DCERF_AS_CPP)
    else()
        target_compile_options(${app} PRIVATE -DCERF_AS_CPP)
    endif()
endforeach()