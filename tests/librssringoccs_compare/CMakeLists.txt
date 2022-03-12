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

project(rssringoccs_compare_library)

enable_language(C)

add_library(librssringoccs_compare SHARED)
target_sources(
    librssringoccs_compare
    PRIVATE
        rss_ringoccs_compare_real_in_real_out_double.c
        rss_ringoccs_compare_complex_in_complex_out_float.c
        rss_ringoccs_compare_real_in_real_out_ldouble.c
        rss_ringoccs_compare_complex_in_complex_out_ldouble.c
        rss_ringoccs_accuracy_complex_in_complex_out_ldouble.c
        rss_ringoccs_compare_complex_in_complex_out_double.c
        rss_ringoccs_accuracy_complex_in_complex_out_float.c
        rss_ringoccs_compare_real_in_real_out_float.c
        rss_ringoccs_time_test_funcs.c
        rss_ringoccs_accuracy_complex_in_complex_out_double.c
)

target_include_directories(
    librssringoccs_compare
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../include
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../../..
)

set_target_properties(
    librssringoccs_compare
    PROPERTIES
        IMPORTED_LOCATION $<TARGET_FILE:tgt>
        IMPORTED_IMPLIB $<TARGET_LINKER_FILE:rss::librssringoccs>
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR}
)
target_link_libraries(librssringoccs_compare rss::librssringoccs)

generate_export_header(
    librssringoccs_compare # generates the export header shared_EXPORTS.h automatically
    BASE_NAME librssringoccs_compare
    EXPORT_MACRO_NAME RSS_RINGOCCS_COMPARE_EXPORT
    EXPORT_FILE_NAME librssringoccs_compare_exports.h
    STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
)

target_include_directories(
    librssringoccs_compare
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

set_property(
    TARGET librssringoccs_compare
    PROPERTY
        C_STANDARD
        90 # C89/90
        INTERPROCEDURAL_OPTIMIZATION
        TRUE
        PUBLIC_HEADER
        ${librssringoccs_HEADERS}
        OUTPUT_NAME
        rssringoccs_compare
)

# Copy the header to ../../include since some tests depended upon it being there
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/rss_ringoccs_compare_funcs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/rss_ringoccs_compare_funcs.h
    COPYONLY
)

# Add an alias so we can link to it in other builds in tests/
add_library(rss::librssringoccs_compare ALIAS librssringoccs_compare)

include(GNUInstallDirs)
install(
    TARGETS librssringoccs_compare
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}}
)
