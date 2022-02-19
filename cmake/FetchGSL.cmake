cmake_minimum_required(VERSION 3.20)
include_guard()

if (APPLE OR UNIX)
    include(FindGSL)
    find_package(GSL REQUIRED)
    if (NOT GSL_FOUND)
        message(FATAL_ERROR "GSL was not found")
    endif()
else()
    find_package(gsl REQUIRED)
    if (NOT gsl_FOUND)
        message(FATAL_ERROR "GSL was not found")
    endif()
endif()



