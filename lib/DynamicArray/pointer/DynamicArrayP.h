#ifndef DYNAMIC_ARRAY_P_H
#define DYNAMIC_ARRAY_P_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMIC_ARRAY_P {
    void **pAddr;
    int capacity;
    int size;
} DynamicArrayP;

//函数指针-打印一个节点
typedef void (*PRINT_DATA)(void *);

//函数指针-比较两个节点，不同返回0
typedef int (*COMPARE_DATA)(const void *, const void *);

//初始化
DynamicArrayP *DynamicArrayP_Init(int capacity);

//打印
void DynamicArrayP_Print(DynamicArrayP *arr, PRINT_DATA printData);


//删除
void DynamicArrayP_Pop(DynamicArrayP *arr, int idx);

//插入
void DynamicArrayP_Push(DynamicArrayP *arr, int idx, void *data);

//插入到末尾
void DynamicArrayP_PushTail(DynamicArrayP *arr, void *data);


//删除末尾，有问题
void DynamicArrayP_PopTail(DynamicArrayP *arr);


int DynamicArrayP_Find(DynamicArrayP *arr, void *data, COMPARE_DATA compareData);

void *DynamicArrayP_GetByIdx(DynamicArrayP *arr, int idx);

void DynamicArrayP_SetByIdx(DynamicArrayP *arr, int idx, void *data);

void DynamicArrayP_Reloc(DynamicArrayP *arr, int new_capacity);

void DynamicArrayP_LoseWeight(DynamicArrayP *arr);

// 释放空间
void DynamicArrayP_Free(DynamicArrayP *arr);

#endif //DYNAMIC_ARRAY_P_H