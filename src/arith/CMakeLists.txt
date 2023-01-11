file(
    GLOB_RECURSE arith_source_files
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)
add_library(arith ${arith_source_files})
target_include_directories(
    arith
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
include(Format)
Format(arith .)
