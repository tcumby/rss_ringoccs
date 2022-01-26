cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(special_funtion_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)


add_executable(bessel_j0_time_test bessel_j0_time_test.c)
target_link_libraries(bessel_j0_time_test PRIVATE librssringoccs librssringoccs_compare)

include(GNUInstallDirs)
install(TARGETS
    bessel_j0_time_test
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)