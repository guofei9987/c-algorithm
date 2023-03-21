//Dynamic Array，可以用来做 Stack
#ifndef DynamicArray_H
#define DynamicArray_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DynamicArray {
    int *pAddr;
    int capacity;
    int size;

} DynamicArray;

//初始化
DynamicArray *DynamicArray_Init(int capacity);

//重新分配内存
void DynamicArray_Reloc(DynamicArray *arr, int new_capacity);

// 减少内存消耗
void DynamicArray_LoseWeight(DynamicArray *arr);


//打印
void DynamicArray_Print(DynamicArray *arr);

//尾部插入，性能 O（1）
void DynamicArray_Push(DynamicArray *arr, int val);

//删除尾部并返回它（未测试）
int DynamicArray_Pop_Tail(DynamicArray *arr);

//删除
void DynamicArray_Pop(DynamicArray *arr, int idx);

int DynamicArray_Find(DynamicArray *arr, int val);

int DynamicArray_Get(DynamicArray *arr, int idx);

void DynamicArray_Set(DynamicArray *arr, int idx, int val);


// 释放空间
void DynamicArray_Free(DynamicArray *arr);

#endif //DynamicArray_H