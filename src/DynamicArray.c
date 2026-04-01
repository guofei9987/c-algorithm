#include "c_algorithm/DynamicArray.h"

//动态数组初始化
c_algo_dynamic_array *c_algo_dynamic_array_init(int capacity) {
//    申请内存
    c_algo_dynamic_array *arr = (c_algo_dynamic_array *) malloc(sizeof(c_algo_dynamic_array));
//    初始化
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (int *) malloc(sizeof(int) * arr->capacity);
    return arr;
}

//重新分配内存
void c_algo_dynamic_array_reloc(c_algo_dynamic_array *arr, int new_capacity) {
//    assert(new_capacity>arr->size)
    int *newPArr = (int *) malloc(sizeof(int) * new_capacity);
    memcpy(newPArr, arr->pAddr, sizeof(int) * arr->size);
    free(arr->pAddr);
    arr->pAddr = newPArr;
    arr->capacity = new_capacity;
}

// 减少内存消耗
void c_algo_dynamic_array_lose_weight(c_algo_dynamic_array *arr) {
    if (arr->size == 0) {
        c_algo_dynamic_array_reloc(arr, 1);
    } else {
        c_algo_dynamic_array_reloc(arr, arr->size);
    }
}

// 打印
void c_algo_dynamic_array_print(c_algo_dynamic_array *arr) {
    if (arr == NULL) {
        return;
    }
    printf("<Dynamic Array>: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d,", arr->pAddr[i]);
    }
    printf("\n");
}

// 尾部插入
void c_algo_dynamic_array_push(c_algo_dynamic_array *arr, int val) {
    if (arr->size == arr->capacity) {
        c_algo_dynamic_array_reloc(arr, arr->capacity * 2);
    }
    arr->pAddr[arr->size] = val;
    arr->size++;
}

// 删除尾部并返回它
int c_algo_dynamic_array_pop_tail(c_algo_dynamic_array *arr) {
    return arr->pAddr[(arr->size--) - 1];
}

// 根据索引删除
void c_algo_dynamic_array_pop(c_algo_dynamic_array *arr, int idx) {
    if (arr == NULL) {
        return;
    }

// 判断索引是否有效
    if (idx < 0 || idx >= arr->size) {
        return;
    }

// 删除，并填补空洞
    arr->size--;
    for (int i = idx; i < arr->size; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }
}

// 取一个
int c_algo_dynamic_array_get(c_algo_dynamic_array *arr, int idx) {
    return arr->pAddr[idx];
}

// 赋值
void c_algo_dynamic_array_set(c_algo_dynamic_array *arr, int idx, int val) {
    arr->pAddr[idx] = val;
}

// 查找
int c_algo_dynamic_array_find(c_algo_dynamic_array *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == val) {
            return i;
        }
    }
    return -1;
}

// 释放空间
void c_algo_dynamic_array_free(c_algo_dynamic_array *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}
