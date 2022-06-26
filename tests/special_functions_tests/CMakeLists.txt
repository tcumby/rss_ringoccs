cmake_minimum_required(VERSION 3.20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake")

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(APPLE)
        include(gcc-macos)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    elseif(UNIX)
        include(gcc)
        set(CMAKE_INSTALL_PREFIX "/usr/local")
    endif()
endif()

include(FetchGSL)

project(special_functions_tests)

set(test_apps bessel_j0_time_test)
foreach(app ${test_apps})
    if(MSVC)
        set_source_files_properties(${app}.c PROPERTIES LANGUAGE CXX)
    endif()
    add_executable(${app} ${app}.c)
    target_set_property(${app} PROPERTY C_STANDARD 99 INTERPROCEDURAL_OPTIMIZATION ${IPO_SUPPORTED})
    target_include_directories(
        ${app}
        PRIVATE "$<TARGET_PROPERTY:GSL::gsl,INTERFACE_INCLUDE_DIRECTORIES>"
    )
    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(
        ${app}
        PRIVATE rss::librssringoccs rss::librssringoccs_compare GSL::gsl
    )
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()
endforeach()

include(GNUInstallDirs)
install(
    TARGETS bessel_j0_time_test
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
