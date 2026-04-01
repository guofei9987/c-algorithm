//循环 Array，头尾插入和删除都是O(1)，可以用来作为 queue/stack 来使用
//当循环array为空和满的时候，都满足 front = tail
//因此2种设计：
// 1. 少用一个元素，front=tail为空。front=tail+1 为满。
// 2. 额外维护一个区分队列空和满的标志。
// 3. 扩展2，维护的是"元素个数"
// 这里实现第1种，这样"元素个数"可以用 (r-f+n)%n 来计算，节省维护 size 的消耗

#ifndef C_ALGO_RECURRENT_ARRAY_H
#define C_ALGO_RECURRENT_ARRAY_H

#include <assert.h>
#include <stdlib.h>

typedef struct c_algo_recurrent_array {
    int *p_addr; // 底层数组
    int front; // 头在数组中的位置
    int tail; // 尾在数组中的位置
    int size; // 底层数组的大小，永远为 capacity + 1，这是因为否则的话，front == tail 既可以表示空又可以表示满
    int capacity;
} c_algo_recurrent_array;

c_algo_recurrent_array *c_algo_recurrent_array_init(int capacity);

//尾部插入
void c_algo_recurrent_array_push(c_algo_recurrent_array *arr, int val);

// 获取头部
int c_algo_recurrent_array_get_front(c_algo_recurrent_array *arr);

//删除头部
void c_algo_recurrent_array_del_front(c_algo_recurrent_array *arr);

// 获取头部，然后删掉它
int c_algo_recurrent_array_pop_front(c_algo_recurrent_array *arr);

//获取尾巴
int c_algo_recurrent_array_get_tail(c_algo_recurrent_array *arr);

//去除尾巴并返回它
int c_algo_recurrent_array_pop_tail(c_algo_recurrent_array *arr);

//是否为空
int c_algo_recurrent_array_is_empty(c_algo_recurrent_array *arr);

//是否已满
int c_algo_recurrent_array_is_full(c_algo_recurrent_array *arr);

void c_algo_recurrent_array_free(c_algo_recurrent_array *arr);

#endif
