cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(newton_fractals)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

add_executable(newton_fractal newton_fractal.c)
target_link_libraries(newton_fractal PRIVATE librssringoccs)

add_executable(newton_fractal_on_sphere newton_fractal_on_sphere.c)
target_link_libraries(newton_fractal_on_sphere PRIVATE librssringoccs)

add_executable(newton_fractal_on_torus newton_fractal_on_torus.c)
target_link_libraries(newton_fractal_on_torus PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    newton_fractal
    newton_fractal_on_sphere
    newton_fractal_on_torus
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)
