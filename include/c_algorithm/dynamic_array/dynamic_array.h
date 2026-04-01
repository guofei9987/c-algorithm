// Dynamic Array，可以用来做 Stack
#ifndef C_ALGO_DYNAMIC_ARRAY_H
#define C_ALGO_DYNAMIC_ARRAY_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c_algo_dynamic_array {
    int *pAddr;
    int capacity;
    int size;
} c_algo_dynamic_array;

// 初始化
c_algo_dynamic_array *c_algo_dynamic_array_init(int capacity);

// 重新分配内存
void c_algo_dynamic_array_reloc(c_algo_dynamic_array *arr, int new_capacity);

// 减少内存消耗
void c_algo_dynamic_array_lose_weight(c_algo_dynamic_array *arr);

// 打印
void c_algo_dynamic_array_print(c_algo_dynamic_array *arr);

// 尾部插入，性能 O(1)
void c_algo_dynamic_array_push(c_algo_dynamic_array *arr, int val);

// 删除尾部并返回它，要求 arr 非空且至少有一个元素
int c_algo_dynamic_array_pop_tail(c_algo_dynamic_array *arr);

// 删除指定索引
void c_algo_dynamic_array_pop(c_algo_dynamic_array *arr, int idx);

int c_algo_dynamic_array_find(c_algo_dynamic_array *arr, int val);

int c_algo_dynamic_array_get(c_algo_dynamic_array *arr, int idx);

void c_algo_dynamic_array_set(c_algo_dynamic_array *arr, int idx, int val);

// 释放空间
void c_algo_dynamic_array_free(c_algo_dynamic_array *arr);

#endif
