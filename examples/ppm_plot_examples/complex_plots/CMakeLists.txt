cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(complex_plots)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

set(apps
    complex_cos_plots
    complex_erf_plots
    complex_erfc_plots
    complex_exp_plots
    complex_faddeeva_plots
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