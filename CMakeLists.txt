cmake_minimum_required(VERSION 3.20)
project(c_algorithm C)

set(CMAKE_C_STANDARD 99)

include_directories(DynamicArray/int)
include_directories(DynamicArray/pointer)
include_directories(DynamicArray/RecurrentArray)
include_directories(DynamicArray)
include_directories(LinkedList)
include_directories(Hash)

add_executable(c_algorithm
        main.c
        DynamicArray/int/DynamicArray.c
        DynamicArray/int/DynamicArray.h
        DynamicArray/pointer/DynamicArrayP.c
        DynamicArray/pointer/DynamicArrayP.h
        DynamicArray/RecurrentArray/RecurrentArray.c
        DynamicArray/RecurrentArray/RecurrentArray.h
        DynamicArray/convertor.c
        DynamicArray/convertor.h
        LinkedList/LinkedList.c
        LinkedList/LinkedList.h
        LinkedList/old/Test_LinkList.c
        Hash/Hash.c
        Hash/Hash.h
        tests/Test_DynamicArrayP.c
        tests/Test_DynamicArray.c
        tests/Test_RecurrentArray.c
        tests/Test_LinkedList.c
        tests/Test_LinkedList.h
        tests/Test_Hash.c
        tests/Test_Hash.h
        #        String/AC_KMP.c
#        String/AC_KMP.h
        kmp.c
        )

