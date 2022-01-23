cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
elseif (UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
endif()

project(math_plots)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(abs_plot abs_plot.c)
target_link_libraries(abs_plot PRIVATE librssringoccs)

add_executable(erfcx_plot erfcx_plot.c)
target_link_libraries(erfcx_plot PRIVATE librssringoccs)

add_executable(max_func_average_number_of_attributes max_func_average_number_of_attributes.c)
target_link_libraries(max_func_average_number_of_attributes PRIVATE librssringoccs)

add_executable(merge_sort_iterative merge_sort_iterative.c)
target_link_libraries(merge_sort_iterative PRIVATE librssringoccs)

add_executable(merge_sort_recursive merge_sort_recursive.c)
target_link_libraries(merge_sort_recursive PRIVATE librssringoccs)

add_executable(sin_plot sin_plot.c)
target_link_libraries(sin_plot PRIVATE librssringoccs)

include(GNUInstallDirs)
install(TARGETS
    abs_plot
    erfcx_plot
    max_func_average_number_of_attributes
    merge_sort_iterative
    merge_sort_recursive
    sin_plot
    RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
)
