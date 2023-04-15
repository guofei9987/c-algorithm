cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-O3")

project(c_algorithm C)

include_directories(DynamicArray)

include_directories(DynamicArray/pointer)
include_directories(LinkedList)
include_directories(Hash)

set(C_ALGO_H
        DynamicArray/DynamicArray.h
        DynamicArray/pointer/DynamicArrayP.h
        DynamicArray/RecurrentArray.h
        DynamicArray/convertor.h
        LinkedList/LinkedList.h
        LinkedList/LinkedListP.h
        Hash/Hash.h
        Hash/HashTable.h
        String/AC_DAT.h
        #        String/AC_KMP.c
        #        String/AC_KMP.h
        )


set(C_ALGO_SRC
        DynamicArray/DynamicArray.c
        DynamicArray/pointer/DynamicArrayP.c
        DynamicArray/RecurrentArray.c
        DynamicArray/convertor.c
        LinkedList/LinkedList.c
        LinkedList/LinkedListP.c
        Hash/Hash.c
        Hash/HashTable.c
        String/AC_DAT.c
        )

ADD_LIBRARY(c_algo SHARED ${C_ALGO_H} ${C_ALGO_SRC})
ADD_LIBRARY(c_algo_static STATIC ${C_ALGO_H} ${C_ALGO_SRC})

INSTALL(FILES ${C_ALGO_H} DESTINATION include/c_algo)
# 动态库
INSTALL(TARGETS c_algo LIBRARY DESTINATION lib)
#静态库
INSTALL(TARGETS c_algo_static ARCHIVE DESTINATION lib)
