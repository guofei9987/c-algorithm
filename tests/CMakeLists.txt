cmake_minimum_required(VERSION 3.20)

project(c_algorithm_tests C)

set(CMAKE_C_STANDARD 99)


add_executable(c_algorithm_tests
        main.c
        tests/Test_DynamicArrayP.c
        tests/Test_DynamicArray.c
        tests/Test_RecurrentArray.c
        tests/Test_LinkedList.c
        tests/Test_LinkedList.h
        tests/Test_Hash.c
        tests/Test_Hash.h
        tests/Test_LinkedListP.c
        tests/Test_LinkedListP.h
        tests/Test_HashTable.c
        tests/Test_HashTable.h
        )


include_directories(/usr/local/include/c_algo)
target_link_libraries(c_algorithm_tests /usr/local/lib/libc_algo.dylib)