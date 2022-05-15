from skbuild import setup  # type: ignore

# This seems to be needed to ensure Python uses the correct gcc. Without this
# You may get a linker warning, for example:
#       ld: warning: dylib (/usr/local/lib/librssringoccs.so) was built for
#       newer macOS version (10.15) than being linked (10.9)
# librssringoccs is built using a shell script and makes calls to gcc, whereas
# this file is using Python's distutils to handle the compiling. It seems
# Python may use the wrong compiler, causing this error. Setting the following
# CFLAG fixed the issue.

#   We only need this fix for macOS, so check what operating system is used.
# if platform.system() == "Darwin":
#     os.environ["CFLAGS"] = "-mmacosx-version-min=%s" % platform.mac_ver()[0]

setup(
    name="rss_ringoccs",
    packages=["rss_ringoccs"],
    version="1.3",
    author="Ryan Maguire",
    description="A suite of open-source C and Python-based analysis tools for Cassini Radio Science (RSS) ring "
    "occultations.",
    install_requires=[
        "cmake",
        "numpy",
        "scipy",
        "spiceypy",
        "matplotlib",
        "mayavi",
        "pandas",
        "PyMieScatt",
    ],
    cmake_install_dir="rss_ringoccs",
    cmake_args=["-DBUILD_EXAMPLES:BOOL=OFF", "-DBUILD_TESTS:BOOL=OFF"],
)
