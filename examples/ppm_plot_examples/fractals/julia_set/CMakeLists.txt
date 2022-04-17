cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    elseif(UNIX)
        include(gcc)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    endif()
endif()

project(julia_set)

set(apps julia_set julia_set_animation julia_set_on_sphere)

foreach(app ${apps})
    add_executable(${app} ${app}.c)
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(${app} PRIVATE rss::librssringoccs)
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

include(GNUInstallDirs)
install(
    TARGETS ${apps}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
