cmake_minimum_required(VERSION 3.20)
project(c_algorithm C)

set(CMAKE_C_STANDARD 99)

include_directories(DynamicArray/int)
include_directories(DynamicArray/pointer)
include_directories(DynamicArray/RecurrentArray)
include_directories(LinkedList/new)
include_directories(LinkedList/old)

add_executable(c_algorithm
        main.c
        DynamicArray/int/DynamicArray.c
        DynamicArray/int/DynamicArray.h
        DynamicArray/pointer/DynamicArrayP.c
        DynamicArray/pointer/DynamicArrayP.h
        DynamicArray/RecurrentArray/RecurrentArray.c
        DynamicArray/RecurrentArray/RecurrentArray.h
        LinkedList/new/LinkedList.c
        LinkedList/new/LinkedList.h
        LinkedList/new/Test_LinkedList.c
        LinkedList/old/LinkList.c
        LinkedList/old/LinkList.h
        tests/Test_LinkList.c
        tests/Test_DynamicArrayP.c
        tests/Test_DynamicArray.c
        tests/Test_RecurrentArray.c

        #        String/AC_KMP.c
#        String/AC_KMP.h
        kmp.c
        )

