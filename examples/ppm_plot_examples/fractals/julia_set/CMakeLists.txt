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

project(julia_set)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)

add_executable(julia_set julia_set.c)
target_link_libraries(julia_set PRIVATE librssringoccs)

add_executable(julia_set_animation julia_set_animation.c)
target_link_libraries(julia_set_animation PRIVATE librssringoccs)

add_executable(julia_set_on_sphere julia_set_on_sphere.c)
target_link_libraries(julia_set_on_sphere PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    julia_set
    julia_set_animation
    julia_set_on_sphere
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)