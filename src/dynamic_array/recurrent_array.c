#include "c_algorithm/dynamic_array/recurrent_array.h"

//循环array

c_algo_recurrent_array *c_algo_recurrent_array_init(int capacity) {
    c_algo_recurrent_array *arr = (c_algo_recurrent_array *) malloc(sizeof(c_algo_recurrent_array));
    arr->front = 1;
    arr->tail = 0;
    arr->capacity = capacity;
    arr->size = capacity + 1;// array 的大小
    arr->p_addr = (int *) malloc(sizeof(int) * arr->size);

    return arr;
}

//尾部插入
void c_algo_recurrent_array_push(c_algo_recurrent_array *arr, int val) {
    assert(!c_algo_recurrent_array_is_full(arr));
    arr->tail = (arr->tail + 1) % arr->size;
    arr->p_addr[arr->tail] = val;
}

// 获取头部
int c_algo_recurrent_array_get_front(c_algo_recurrent_array *arr) {
    assert(!c_algo_recurrent_array_is_empty(arr));
    return arr->p_addr[arr->front];
}

//删除头部
void c_algo_recurrent_array_del_front(c_algo_recurrent_array *arr) {
    assert(!c_algo_recurrent_array_is_empty(arr));
    arr->front = (arr->front + 1) % arr->size;
}

// 获取头部，然后删掉它
int c_algo_recurrent_array_pop_front(c_algo_recurrent_array *arr) {
    assert(!c_algo_recurrent_array_is_empty(arr));
    int tmp = arr->p_addr[arr->front];
    arr->front = (arr->front + 1) % arr->size;
    return tmp;
}

//获取尾巴
int c_algo_recurrent_array_get_tail(c_algo_recurrent_array *arr) {
    assert(!c_algo_recurrent_array_is_empty(arr));
    return arr->p_addr[arr->tail];
}

//去除尾巴并返回它
int c_algo_recurrent_array_pop_tail(c_algo_recurrent_array *arr) {
    assert(!c_algo_recurrent_array_is_empty(arr));
    int tmp = arr->p_addr[arr->tail];
    arr->tail -= 1;
    if (arr->tail == -1) {
        arr->tail = arr->size - 1;
    }
    return tmp;
}

//是否为空
int c_algo_recurrent_array_is_empty(c_algo_recurrent_array *arr) {
    return (arr->tail + 1) % arr->size == arr->front;
}

//是否已满
int c_algo_recurrent_array_is_full(c_algo_recurrent_array *arr) {
    return (arr->tail + 2) % arr->size == arr->front;
}

void c_algo_recurrent_array_free(c_algo_recurrent_array *arr) {
    free(arr->p_addr);
    free(arr);
}
