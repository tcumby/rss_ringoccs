cmake_minimum_required(VERSION 3.20)
include_guard()
include(FetchContent)

if (MSVC)
    set(CERF_CPP ON)
    set(LIB_MAN OFF)
    set(BUILD_SHARED_LIBS ON)
endif()

FetchContent_Declare(
    cerf_checkout
    GIT_REPOSITORY https://jugit.fz-juelich.de/mlz/libcerf.git
    GIT_TAG 33f93bb6239a078c17ed032edc7c8dd7e6cb922b # the commit corresponding to v1.13
)

FetchContent_MakeAvailable(cerf_checkout)

if (cerf_checkout_POPULATED)
    set(cerf_INCLUDE_DIRECTORY ${cerf_checkout_SOURCE_DIR}/lib)
else()
    message(FATAL_ERROR "cerf is not available")
endif()