cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
    elseif(UNIX)
        include(gcc)
    endif()
endif()

project(glynn_fractals)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

set(apps
    glynn_fractal
    glynn_fractal_on_sphere_periodic_palette
    glynn_fractal_periodic_palette
)

foreach(app ${apps})
    add_executable(${app} ${app}.c)
    target_link_libraries(${app} PRIVATE rss::librssringoccs)
endforeach()

include(GNUInstallDirs)
install(
    TARGETS ${apps}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
