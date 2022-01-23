cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

project(glynn_fractals)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

add_executable(glynn_fractal glynn_fractal.c)
target_link_libraries(glynn_fractal PRIVATE librssringoccs)

add_executable(glynn_fractal_on_sphere_periodic_palette glynn_fractal_on_sphere_periodic_palette.c)
target_link_libraries(glynn_fractal_on_sphere_periodic_palette PRIVATE librssringoccs)

add_executable(glynn_fractal_periodic_palette glynn_fractal_periodic_palette.c)
target_link_libraries(glynn_fractal_periodic_palette PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    glynn_fractal
    glynn_fractal_on_sphere_periodic_palette
    glynn_fractal_periodic_palette
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)