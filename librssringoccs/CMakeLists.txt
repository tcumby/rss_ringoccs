cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    elseif(UNIX)
        include(gcc)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    endif()
endif()

include(GenerateExportHeader)

project(rssringoccs_library)

if(MSVC)
    file(GLOB_RECURSE CFILES "*.c")
    set_source_files_properties(${CFILES} PROPERTIES LANGUAGE CXX)
endif()

add_library(librssringoccs SHARED)
if(UNIX)
    target_link_libraries(librssringoccs PRIVATE m)
endif()

target_include_directories(
    librssringoccs
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
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
generate_export_header(
    librssringoccs # generates the export header shared_EXPORTS.h automatically
    BASE_NAME librssringoccs
    EXPORT_MACRO_NAME RSS_RINGOCCS_EXPORT
    EXPORT_FILE_NAME librssringoccs_exports.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
)
target_include_directories(librssringoccs PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
file(GLOB LIBRSSRINGOCCS_HEADERS ../include/*.h)
set_target_properties(
    librssringoccs
    PROPERTIES
        LANGUAGE $<IF:$<C_COMPILER_ID:MSVC>CXX,C>
        INTERPROCEDURAL_OPTIMIZATION TRUE
        PUBLIC_HEADER "${LIBRSSRINGOCCS_HEADERS}"
        OUTPUT_NAME rssringoccs
        IMPORTED_LOCATION $<TARGET_FILE:tgt>
        IMPORTED_IMPLIB $<TARGET_LINKER_FILE:librssringoccs>
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(rss::librssringoccs ALIAS librssringoccs)

if(NOT DEFINED SKBUILD)
    include(GNUInstallDirs)
    install(
        TARGETS librssringoccs
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}}
    )
else()
    install(TARGETS librssringoccs DESTINATION .)
endif()
