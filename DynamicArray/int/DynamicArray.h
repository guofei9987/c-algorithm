#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct DYNAMIC_ARRAY {
    int *pAddr;
    int capacity;
    int size;

} Dynamic_Array;

//初始化
Dynamic_Array *Init_Dynamic_Array();

//打印
void Print_Dynamic_Array(Dynamic_Array *arr);

//插入
void Push_Dynamic_Array(Dynamic_Array *arr, int val);

//删除
void Pop_Dynamic_Array(Dynamic_Array *arr,int idx);

int Find_Dynamic_Array(Dynamic_Array *arr,int val);
int Get_Dynamic_Array(Dynamic_Array *arr, int idx);
void Set_Dynamic_Array(Dynamic_Array *arr, int idx, int val);

// 释放空间
void Free_Dynamic_Array(Dynamic_Array *arr);

#endif //DYNAMIC_ARRAY_H