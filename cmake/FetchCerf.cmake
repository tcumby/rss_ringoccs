cmake_minimum_required(VERSION 3.20)
include_guard()
include(FetchContent)
FetchContent_Declare(
    cerf_checkout
    GIT_REPOSITORY https://jugit.fz-juelich.de/mlz/libcerf.git
    GIT_TAG 4f2c6384e12d51ea86302bab0c0cb53b2e948c19 # the commit corresponding to v1.17
)

FetchContent_MakeAvailable(cerf_checkout)