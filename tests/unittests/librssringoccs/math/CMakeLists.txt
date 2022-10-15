include(GoogleTest)
find_package(GTest CONFIG REQUIRED)

project(math_unittests)
set(test_apps rss_ringoccs_abs_unittest)
foreach(app ${test_apps})
    add_executable(${app} ${app}.cpp)

    target_include_directories(${app} PUBLIC "${RSS_RINGOCCS_PARENT_DIR}")
    target_link_libraries(${app} PRIVATE rss::librssringoccs GTest::gtest_main)
    if(UNIX)
        target_link_libraries(${app} PRIVATE m)
    endif()

    add_test(NAME ${app} COMMAND "$<TARGET_FILE:${app}>")

    gtest_discover_tests(${app})
endforeach()

include(GNUInstallDirs)
install(
    TARGETS ${test_apps}
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
