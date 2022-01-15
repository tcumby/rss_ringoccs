cmake_minimum_required(VERSION 3.20)

project(rss_ringoccs)


enable_language(C)

add_library(librssringoccs SHARED)

target_include_directories(librssringoccs ../include)
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
target_compile_options(librssringoccs PUBLIC
    -ansi
    -pedantic
    -pedantic-errors
    -Wall
    -Wextra
    -Wpedantic
    -Wmisleading-indentation
    -Wmissing-field-initializers
    -Wmissing-prototypes
    -Wold-style-definition
    -Winit-self
    -Wmissing-declarations
    -Wnull-dereference
    -Wwrite-strings
    -Wstrict-prototypes
    -g -fPIC -O3 -flto -c
)

file(GLOB LIBRSSRINGOCCS_HEADERS ../include/*.h )
set_property(TARGET librssringoccs
    PROPERTY
        C_STANDARD 90 # C89/90
        PUBLIC_HEADER ${LIBRSSRINGOCCS_HEADERS}
        OUTPUT_NAME rssringoccs
)

if(NOT WIN32 AND CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()


include(GNUInstallDirs)
install(TARGETS RSSRINGOCCS
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION  ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}}
)




