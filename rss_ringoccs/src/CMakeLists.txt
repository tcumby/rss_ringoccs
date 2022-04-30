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
    target_link_libraries(${module} PRIVATE rss::librssringoccs)
    target_include_directories(
        ${module}
        PRIVATE
            "${Python_NumPy_INCLUDE_DIRS}"
            "${Python_INCLUDE_DIRS}"
            "${RSS_RINGOCCS_PARENT_DIR}"
    )
endforeach()
