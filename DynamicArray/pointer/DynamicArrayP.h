#ifndef DYNAMIC_ARRAY_P_H
#define DYNAMIC_ARRAY_P_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMIC_ARRAY_P {
    void **pAddr;
    int capacity;
    int size;
} Dynamic_Array_P;

//函数指针-打印一个节点
typedef void (*PRINT_DATA)(void *);

//函数指针-比较两个节点
typedef int (*COMPARE_DATA)(void *, void *);

//初始化
Dynamic_Array_P *Init_Dynamic_Array_P();

//打印
void Print_Dynamic_Array_P(Dynamic_Array_P *arr, PRINT_DATA printData);

//插入
void Push_Last_Dynamic_Array_P(Dynamic_Array_P *arr, void *data);

//删除
void Pop_Dynamic_Array_P(Dynamic_Array_P *arr, int idx);

//插入到末尾
void Push_Dynamic_Array_P(Dynamic_Array_P *arr, int idx, void *data);

//删除末尾
void Pop_Last_Dynamic_Array_P(Dynamic_Array_P *arr);


int Find_Dynamic_Array_P(Dynamic_Array_P *arr, void *data);

void *Get_Dynamic_Array_P(Dynamic_Array_P *arr, int idx);

void Set_Dynamic_Array_P(Dynamic_Array_P *arr, int idx, void *data);

// 释放空间
void Free_Dynamic_Array_P(Dynamic_Array_P *arr);

//TODO:释放所指向的数据


#endif //DYNAMIC_ARRAY_P_H