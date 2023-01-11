add_executable(calc calc.cpp)
target_link_libraries(calc arith)

add_executable(cli cli.cpp)
target_link_libraries(cli docopt)

add_executable(3_insert_data 3_insert_data.cpp)
target_link_libraries(3_insert_data sqlite3 pthread dl)
include(Format)
Format(3_insert_data .)
