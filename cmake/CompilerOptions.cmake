include_guard()

if(APPLE)
    include(gcc-macos)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
    enable_language(C)
elseif(UNIX)
    include(gcc)
    set(CMAKE_INSTALL_PREFIX "/usr/local")
    enable_language(C)
elseif(WIN32)
    if(MSVC)
        # Compile as C++ for Microsoft Visual Studio to avoid the non-standard complex number implementation in the
        # C compiler
        list(APPEND CMAKE_CXX_SOURCE_FILE_EXTENSIONS c)
        enable_language(CXX)
        set(CMAKE_CXX_STANDARD 11)
        set(CMAKE_GENERATOR_PLATFORM x64 CACHE INTERNAL "")

        # Enable parallel builds
        add_compile_options("/MP")
    endif()
endif()
