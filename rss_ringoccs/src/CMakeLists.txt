project(python_modules)
include(CMakePrintHelpers)

if(SKBUILD)
    find_package(NumPy REQUIRED)
    find_package(PythonExtensions REQUIRED)
else()
    if(NOT DEFINED Python_NumPy_INCLUDE_DIRS)
        find_package(Python COMPONENTS Development NumPy)
    endif()
    cmake_print_variables(Python_NumPy_FOUND)

    set(NumPy_VERSION ${Python_NumPy_VERSION})
    set(NumPy_FOUND ${Python_NumPy_FOUND})
    set(NumPy_INCLUDE_DIRS ${Python_NumPy_INCLUDE_DIRS})
endif()

if(NumPy_FOUND)
    message(STATUS "Building against NumPy ${NumPy_VERSION}")
else()
    message(FATAL_ERROR "NumPy not found")
endif()

cmake_print_variables(PYTHON_EXECUTABLE)
cmake_print_variables(NumPy_INCLUDE_DIRS)

set(modules _diffrec _special_functions)
set(module_diffrec_source diffraction_correction_class)
set(module_special_functions_source special_functions_module)
foreach(module ${modules})
    if(SKBUILD)
        add_library(${module} MODULE ${module${module}_source}.c)
        python_extension_module(${module})
        set_target_properties(
			${module}
       		PROPERTIES
				INSTALL_RPATH "$ORIGIN"
				BUILD_WITH_INSTALL_RPATH TRUE
        	)
    else()
        add_library(${module} SHARED ${module${module}_source}.c)
    endif()

    if(MSVC)
        set_source_files_properties(
            ${module${module}_source}.c
            PROPERTIES LANGUAGE CXX
        )
    endif()
    set_target_properties(
        ${module}
        PROPERTIES
            CXX_STANDARD 20
            C_STANDARD 99
            INTERPROCEDURAL_OPTIMIZATION ${IPO_SUPPORTED}
    )
    target_link_directories(${module} PRIVATE ${Python_LIBRARY_DIRS})
    target_link_libraries(${module} rss::librssringoccs ${Python_LIBRARIES})
    target_include_directories(
        ${module}
        PRIVATE
            "${Python_NumPy_INCLUDE_DIRS}"
            "${NumPy_INCLUDE_DIRS}"
            "${Python_INCLUDE_DIRS}"
            "${RSS_RINGOCCS_PARENT_DIR}"
    )
    if(SKBUILD)
        # sci-kit build defines its own CMake variables that must be used in place of those created by FindPython
        target_include_directories(${module} PRIVATE "${Python_INCLUDE_DIR}")

        target_link_libraries(${module} ${Python_LIBRARY})
    endif()
endforeach()

# For Python < 3.7, the parts of the Python API used by diffraction_correction_class.c are not const-correct for
# injesting string literals and building on MSVC errors since we're building as C++, which is less forgiving of these
# conversions.
cmake_print_variables(Python_VERSION)
if("${Python_VERSION}" VERSION_LESS "3.7.0")
    if(MSVC)
        # Enable string literal type conversion
        target_compile_options(_diffrec PRIVATE "/Zc:strictStrings-")

        # Remove the compile option that disables string liter type conversion, if present
        get_target_property(target_options _diffrec COMPILE_OPTIONS)
        if(target_options)
            list(REMOVE_ITEM target_options "/Zc:strictStrings")
            set_property(
                TARGET _diffrec
                PROPERTY COMPILE_OPTIONS ${target_options}
            )
        endif()
        unset(target_options)
    endif()
endif()

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

target_sources(_diffrec PRIVATE ${diffraction_sources})

if(NOT DEFINED SKBUILD)
    include(GNUInstallDirs)
    install(
        TARGETS ${modules}
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}}
    )
else()
    install(TARGETS ${modules} DESTINATION .)
endif()
