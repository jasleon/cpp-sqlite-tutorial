cmake_minimum_required(VERSION 3.2)

project("cpp-project-template" VERSION 1.0.0 LANGUAGES CXX)
enable_testing()
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Configuring the toolchain p.103 from "Modern CMake for C++" by Rafal Swidzinski
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# C++ Best Practices website curated list of warnings by Jason Turner
# https://github.com/cpp-best-practices/cppbestpractices/blob/master/02-Use_the_Tools_Available.md#gcc--clang
add_compile_options(
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -pedantic
)

# Use include instead of add_subdirectory to avoid scope issues
# Check section 7.1.2 Scope from "Professional CMake" by Craig Scott
include(dependencies/CMakeLists.txt)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
