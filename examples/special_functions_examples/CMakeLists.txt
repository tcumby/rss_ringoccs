cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(special_functions_examples)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(complex_bessel_I0_plots complex_bessel_I0_plots.c)
target_link_libraries(complex_bessel_I0_plots PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    complex_bessel_I0_plots
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)