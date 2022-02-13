cmake_minimum_required(VERSION 3.20)
include_guard()
include(FetchContent)

FetchContent_Declare(
    vcpkg_checkout
    GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
    GIT_TAG 2022.02.02
)

FetchContent_MakeAvailable(vcpkg_checkout)

if (vcpkg_checkout_Populated)
    set(vcpkg_toolchain_file "${vcpkg_checkout_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()
