#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMIC_ARRAY {
    void **pAddr;
    int capacity;
    int size;
} Dynamic_Array;

//遍历函数指针
typedef void (*PRINT_DATA)(void *);

//比较函数指针
typedef int (*COMPARE_DATA)(void *, void *);

//初始化
Dynamic_Array *Init_Dynamic_Array();

//打印
void Print_Dynamic_Array(Dynamic_Array *arr, PRINT_DATA printData);

//插入
void Push_Last_Dynamic_Array(Dynamic_Array *arr, void *data);

//删除
void Pop_Dynamic_Array(Dynamic_Array *arr, int idx);

//插入到末尾
void Push_Dynamic_Array(Dynamic_Array *arr, int idx, void *data);

//删除末尾
void Pop_Last_Dynamic_Array(Dynamic_Array *arr);


int Find_Dynamic_Array(Dynamic_Array *arr, void *data);

void *Get_Dynamic_Array(Dynamic_Array *arr, int idx);

void Set_Dynamic_Array(Dynamic_Array *arr, int idx, void *data);

// 释放空间
void Free_Dynamic_Array(Dynamic_Array *arr);

//TODO:释放所指向的数据


#endif //DYNAMIC_ARRAY_H