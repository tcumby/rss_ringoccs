project(python_modules)

if(NOT DEFINED Python_NumPy_INCLUDE_DIRS)
    find_package(Python COMPONENTS Development NumPy)
    if(Python_NumPy_FOUND)
        message(STATUS "Building against NumPy ${Python_NumPy_VERSION}")
    else()
        message(FATAL_ERROR "NumPy not found")
    endif()
endif()

set(modules diffraction_correction_class special_functions_module)

foreach(module ${modules})
    add_library(${module} SHARED ${module}.c)
    if(MSVC)
        set_source_files_properties(${module}.c PROPERTIES LANGUAGE CXX)
    endif()
    set_target_properties(${module} PROPERTIES CXX_STANDARD 20 C_STANDARD 99)
    target_link_directories(${module} PRIVATE ${Python_LIBRARY_DIRS})
    target_link_libraries(
        ${module}
        PRIVATE rss::librssringoccs ${Python_LIBRARIES}
    )
    target_include_directories(
        ${module}
        PRIVATE
            "${Python_NumPy_INCLUDE_DIRS}"
            "${Python_INCLUDE_DIRS}"
            "${RSS_RINGOCCS_PARENT_DIR}"
    )
endforeach()

set(diffraction_sources
    rss_ringoccs_Py_DLP_to_C_DLP.c
    rss_ringoccs_C_Tau_to_Py_Tau.c
    rss_ringoccs_Get_Py_Perturb.c
    rss_ringoccs_Get_Py_Range.c
    rss_ringoccs_Get_Py_Vars_From_Self.c
)

foreach(source ${diffraction_sources})
    if(MSVC)
        set_source_files_properties(${source} PROPERTIES LANGUAGE CXX)
    endif()
endforeach()

target_sources(diffraction_correction_class PRIVATE ${diffraction_sources})
