cmake_minimum_required(VERSION 3.20)
project(c_algorithm C)

set(CMAKE_C_STANDARD 99)

#include_directories(DynamicArray/int)
#include_directories(DynamicArray/pointer)
#include_directories(LinkedList/new)
#include_directories(LinkedList/old)
#
#add_executable(c_algorithm
#        main.c
#        DynamicArray/int/DynamicArray.c
#        DynamicArray/int/DynamicArray.h
#        DynamicArray/int/Test_DynamicArray.c
#        DynamicArray/pointer/DynamicArrayP.c
#        DynamicArray/pointer/DynamicArrayP.h
#        DynamicArray/pointer/Test_DynamicArrayP.c
#        LinkedList/new/LinkedList.c
#        LinkedList/new/LinkedList.h
#        LinkedList/new/Test_LinkedList.c
#        LinkedList/old/LinkList.c
#        LinkedList/old/LinkList.h
#        LinkedList/old/Test_LinkList.c
#        kmp.c
#        )


add_executable(c_algorithm
        main.c)