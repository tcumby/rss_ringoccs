cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
if (APPLE)
    include(gcc-macos)
elseif (UNIX)
    include(gcc)
endif()
endif()

include(FetchCerf)

project(csv_tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

add_executable(test_get_dlp_csv test_get_dlp_csv.c)
target_link_libraries(test_get_dlp_csv PRIVATE librssringoccs librssringoccs_compare)

add_executable(test_get_geo_csv test_get_geo_csv.c)
target_link_libraries(test_get_geo_csv PRIVATE librssringoccs librssringoccs_compare)

add_executable(test_get_tau_csv test_get_tau_csv.c)
target_link_libraries(test_get_tau_csv PRIVATE librssringoccs librssringoccs_compare)
