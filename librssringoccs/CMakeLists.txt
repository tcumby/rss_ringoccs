cmake_minimum_required(3.18)

project(librssringoccs)

add_library(RSSRINGOCCS SHARED)

target_include_directories(RSSRINGOCCS ../include)

add_subdirectory("complex")
add_subdirectory("csv_tools")
add_subdirectory("diffraction")
add_subdirectory("fft")
add_subdirectory("fresnel_kernel")
add_subdirectory("fresnel_transform")
add_subdirectory("geometry")
add_subdirectory("interpolate")
add_subdirectory("math")
add_subdirectory("numerical")
add_subdirectory("ppm_plot")
add_subdirectory("reconstruction")
add_subdirectory("special_functions")
add_subdirectory("string")

include(GNUInstallDirs)
install(TARGETS RSSRINGOCCS
    RUNTIME ${CMAKE_INSTALL_BINDIR}
    LIBRARY ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE ${CMAKE_INSTALL_LIBDIR}
)




