cmake_minimum_required(VERSION 3.20)
project(c_algorithm C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-O3")
add_subdirectory(lib bin)

# 测试
IF (DEFINED DO_TEST)
    message(STATUS "测试 ${DO_TEST}")
    add_subdirectory(tests c_algorithm_tests)
    enable_testing()
    add_test(NAME tests COMMAND c_algorithm_tests/c_algorithm_tests)
ENDIF ()