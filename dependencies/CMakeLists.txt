# Adapt recipe from "CMake Cookbook" by Radovan Bast, Roberto Di Remigio
# https://github.com/dev-cafe/cmake-cookbook/tree/v1.0/chapter-04/recipe-03
include(FetchContent)

# Show the output associated with populating the specified content
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # release-1.11.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)

    # Prevent GoogleTest from using PThreads
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

    # Add the targets: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
        ${googletest_SOURCE_DIR}
        ${googletest_BINARY_DIR}
    )
endif()

FetchContent_Declare(
    docopt
    GIT_REPOSITORY https://github.com/docopt/docopt.cpp.git
    GIT_TAG        42ebcec9dc2c99a1b3a4542787572045763ad196 # v0.6.3
)
FetchContent_MakeAvailable(docopt)

FetchContent_Declare(
    sqlite_content
    URL            https://www.sqlite.org/2021/sqlite-amalgamation-3360000.zip # 3.36.0
    URL_HASH       SHA3_256=d25609210ec93b3c8c7da66a03cf82e2c9868cfbd2d7d866982861855e96f972
)
FetchContent_GetProperties(sqlite_content)
if(NOT sqlite_content_POPULATED)
    FetchContent_Populate(sqlite_content)
    add_library(sqlite3 ${sqlite_content_SOURCE_DIR}/sqlite3.c)
    include_directories(${sqlite_content_SOURCE_DIR})
endif()
