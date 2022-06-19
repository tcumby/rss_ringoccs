include_guard()

# Find gcc as installed by Homebrew
find_program(
    GCC
    NAMES gcc gcc-9 gcc-10 gcc-11
    PATHS /usr/local/Cellar /usr/local/opt /opt/local/bin
    NO_DEFAULT_PATH
)
if(GCC)
    set(CMAKE_C_COMPILER ${GCC})

    set(extraOpts
        "-ansi
            -pedantic
            -pedantic-errors
            -Wall
            -Wextra
            -Wpedantic
            -Wmisleading-indentation
            -Wmissing-field-initializers
            -Wmissing-prototypes
            -Wold-style-definition
            -Winit-self
            -Wmissing-declarations
            -Wnull-dereference
            -Wwrite-strings
            -Wstrict-prototypes
            -g -fPIC -O3 -flto -c"
    )
    set(CMAKE_C_FLAGS_DEBUG_INIT ${extraOpts})
else()
    message(FATAL_ERROR "gcc was not found")
endif()
