#include "c_algorithm/dynamic_array/dynamic_array_p.h"

#include <assert.h>

//初始化
c_algo_dynamic_array_p *c_algo_dynamic_array_p_init(int capacity) {
    c_algo_dynamic_array_p *arr = (c_algo_dynamic_array_p *) malloc(sizeof(c_algo_dynamic_array_p));
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (void *) malloc(sizeof(void *) * arr->capacity);
    return arr;
}

void c_algo_dynamic_array_p_push(c_algo_dynamic_array_p *arr, int idx, void *data) {
    if (arr->size == arr->capacity) {
        c_algo_dynamic_array_p_reloc(arr, arr->capacity * 2);
    }

    for (int i = arr->size; i > idx; i--) {
        arr->pAddr[i] = arr->pAddr[i - 1];
    }

    arr->pAddr[idx] = data;
    arr->size++;
}

// 尾部插入
void c_algo_dynamic_array_p_push_tail(c_algo_dynamic_array_p *arr, void *data) {
    c_algo_dynamic_array_p_push(arr, arr->size, data);
}

//打印
void c_algo_dynamic_array_p_print(c_algo_dynamic_array_p *arr, c_algo_dynamic_array_p_print_data print_data) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        print_data(arr->pAddr[i]);
    }
    printf("\n");
}

// 删除一个
// 被删除的 void *data 对应的内存不在这里释放，因为它不是 c_algo_dynamic_array_p_init 申请的
void c_algo_dynamic_array_p_pop(c_algo_dynamic_array_p *arr, int idx) {
    if (arr == NULL) {
        return;
    }
    if (idx < 0 || idx >= arr->size) {
        return;
    }

    arr->size--;
    for (int i = idx; i < arr->size; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
}

//取一个
void *c_algo_dynamic_array_p_get_by_idx(c_algo_dynamic_array_p *arr, int idx) {
    if (idx >= arr->size) {
        return NULL;
    }
    return arr->pAddr[idx];
}

//赋值
void c_algo_dynamic_array_p_set_by_idx(c_algo_dynamic_array_p *arr, int idx, void *data) {
    arr->pAddr[idx] = data;
}

//查找，使用传入的 compare_data 函数指针
int c_algo_dynamic_array_p_find(c_algo_dynamic_array_p *arr, void *data, c_algo_dynamic_array_p_compare_data compare_data) {
    for (int i = 0; i < arr->size; i++) {
        if (compare_data(arr->pAddr[i], data)) {
            return i;
        }
    }
    return -1;
}

//从最后删除
void c_algo_dynamic_array_p_pop_tail(c_algo_dynamic_array_p *arr) {
    c_algo_dynamic_array_p_pop(arr, arr->size - 1);
}

// 重新分配内存
void c_algo_dynamic_array_p_reloc(c_algo_dynamic_array_p *arr, int new_capacity) {
    assert(new_capacity >= arr->size);
    void **newPArr = (void **) malloc(sizeof(void *) * new_capacity);
    memcpy(newPArr, arr->pAddr, sizeof(void *) * arr->size);
    free(arr->pAddr);
    arr->pAddr = newPArr;
    arr->capacity = new_capacity;
}

void c_algo_dynamic_array_p_lose_weight(c_algo_dynamic_array_p *arr) {
    if (arr->size == 0) {
        c_algo_dynamic_array_p_reloc(arr, 1);
    } else {
        c_algo_dynamic_array_p_reloc(arr, arr->size);
    }
}

// 释放空间
// 不释放void * 指向的数据，因为它不是在 DynamicArrayP 中分配的内存
void c_algo_dynamic_array_p_free(c_algo_dynamic_array_p *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}
