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

project(math_examples)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../..)

# abs_example.c lacks a main() at the moment. Once there is an implementation, uncomment the following lines
# set(apps
#     abs_example
# )
# foreach(app ${apps})
#     add_executable(${app} ${app}.c)
#     target_link_libraries(${app} PRIVATE rss::librssringoccs)
# endforeach()

# include(GNUInstallDirs)
# install(TARGETS
#     ${apps}
#     RUNTIME DESTINATION  ${CMAKE_INSTALL_BINDIR}
#     LIBRARY DESTINATION  ${CMAKE_INSTALL_LIBDIR}
# )