project(python_modules)

add_library(diffraction SHARED diffraction_correction_class.c)
if(MSVC)
    set_source_files_properties(
        diffraction_correction_class.c
        PROPERTIES LANGUAGE CXX
    )
endif()
target_link_libraries(diffraction PRIVATE rss::librssringoccs)

add_library(special_function SHARED special_function_module.c)
if(MSVC)
    set_source_files_properties(
        special_function_module.c
        PROPERTIES LANGUAGE CXX
    )
endif()
target_link_libraries(diffraction PRIVATE rss::librssringoccs)
