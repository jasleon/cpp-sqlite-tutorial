add_executable(calc calc.cpp)
target_link_libraries(calc arith)

add_executable(cli cli.cpp)
target_link_libraries(cli docopt)
