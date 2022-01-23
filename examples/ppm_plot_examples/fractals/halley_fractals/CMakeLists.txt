cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(halley_fractals)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

add_executable(halley_fractal_on_sphere halley_fractal_on_sphere.c)
target_link_libraries(halley_fractal_on_sphere PRIVATE librssringoccs)

add_executable(halley_fractal_on_sphere_polynomial halley_fractal_on_sphere_polynomial.c)
target_link_libraries(halley_fractal_on_sphere_polynomial PRIVATE librssringoccs)

add_executable(halley_fractal_polynomial halley_fractal_polynomial.c)
target_link_libraries(halley_fractal_polynomial PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    halley_fractal_on_sphere
    halley_fractal_on_sphere_polynomial
    halley_fractal_polynomial
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)
