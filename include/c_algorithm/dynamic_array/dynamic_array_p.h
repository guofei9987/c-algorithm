#ifndef C_ALGO_DYNAMIC_ARRAY_P_H
#define C_ALGO_DYNAMIC_ARRAY_P_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DYNAMIC_ARRAY_P {
    void **pAddr;
    int capacity;
    int size;
} c_algo_dynamic_array_p;

//函数指针-打印一个节点
typedef void (*c_algo_dynamic_array_p_print_data)(void *);

//函数指针-比较两个节点，不同返回0
typedef int (*c_algo_dynamic_array_p_compare_data)(const void *, const void *);

//初始化
c_algo_dynamic_array_p *c_algo_dynamic_array_p_init(int capacity);

//打印
void c_algo_dynamic_array_p_print(c_algo_dynamic_array_p *arr, c_algo_dynamic_array_p_print_data print_data);

//删除
void c_algo_dynamic_array_p_pop(c_algo_dynamic_array_p *arr, int idx);

//插入
void c_algo_dynamic_array_p_push(c_algo_dynamic_array_p *arr, int idx, void *data);

//插入到末尾
void c_algo_dynamic_array_p_push_tail(c_algo_dynamic_array_p *arr, void *data);

//删除末尾，有问题
void c_algo_dynamic_array_p_pop_tail(c_algo_dynamic_array_p *arr);

int c_algo_dynamic_array_p_find(c_algo_dynamic_array_p *arr, void *data, c_algo_dynamic_array_p_compare_data compare_data);

void *c_algo_dynamic_array_p_get_by_idx(c_algo_dynamic_array_p *arr, int idx);

void c_algo_dynamic_array_p_set_by_idx(c_algo_dynamic_array_p *arr, int idx, void *data);

void c_algo_dynamic_array_p_reloc(c_algo_dynamic_array_p *arr, int new_capacity);

void c_algo_dynamic_array_p_lose_weight(c_algo_dynamic_array_p *arr);

// 释放空间
void c_algo_dynamic_array_p_free(c_algo_dynamic_array_p *arr);

#endif
