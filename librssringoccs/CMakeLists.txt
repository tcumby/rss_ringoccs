cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(rss_ringoccs)

enable_language(C)

add_library(librssringoccs SHARED)

target_include_directories(librssringoccs PUBLIC ../include ../..)
add_subdirectory("complex")
add_subdirectory("csv_tools")
add_subdirectory("diffraction")
add_subdirectory("fft")
add_subdirectory("fresnel_kernel")
add_subdirectory("fresnel_transform")
add_subdirectory("geometry")
add_subdirectory("interpolate")
add_subdirectory("math")
add_subdirectory("numerical")
add_subdirectory("ppm_plot")
add_subdirectory("reconstruction")
add_subdirectory("special_functions")
add_subdirectory("string")
target_compile_definitions(librssringoccs PUBLIC -DNDEBUG)


file(GLOB LIBRSSRINGOCCS_HEADERS ../include/*.h )
set_property(TARGET librssringoccs
    PROPERTY
        C_STANDARD 90 # C89/90
        PUBLIC_HEADER ${LIBRSSRINGOCCS_HEADERS}
        OUTPUT_NAME rssringoccs
)


include(GNUInstallDirs)
install(TARGETS librssringoccs
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION  ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}}
)




