#include "RecurrentArray.h"
//循环array


Rec_Array *RecArray_Init(int capacity) {
    Rec_Array *arr = (Rec_Array *) malloc(sizeof(Rec_Array));
    arr->front = 1;
    arr->tail = 0;
    arr->capacity = capacity;
    arr->size = capacity + 1;// array 的大小
    arr->pAddr = (DATA_TYPE *) malloc(sizeof(DATA_TYPE) * arr->size);

    return arr;
};

//尾部插入
void RecArray_Push(Rec_Array *arr, DATA_TYPE val) {
    assert(!RecArray_IsFull(arr));
    arr->tail = (arr->tail + 1) % arr->size;
    arr->pAddr[arr->tail] = val;
};

// 获取头部
DATA_TYPE RecArray_GetFront(Rec_Array *arr) {
    assert(!RecArray_IsFull(arr));
    return arr->pAddr[arr->front];
}

//删除头部
void RecArray_DelFront(Rec_Array *arr) {
    assert(!RecArray_IsFull(arr));
    arr->front = (arr->front + 1) % arr->size;
}

// 获取头部，然后删掉它
DATA_TYPE Pop_Front_Rec_Array(Rec_Array *arr) {
    assert(!RecArray_IsFull(arr));
    DATA_TYPE tmp = arr->pAddr[arr->front];
    arr->front = (arr->front + 1) % arr->size;
    return tmp;
}



//获取尾巴
DATA_TYPE RecArray_GetTail(Rec_Array *arr) {
    assert(!RecArray_IsFull(arr));
    return arr->pAddr[arr->tail];
}

//去除尾巴并返回它
DATA_TYPE RecArray_PopTail(Rec_Array *arr) {
    assert(!RecArray_IsFull(arr));
    DATA_TYPE tmp = arr->pAddr[arr->tail];
    arr->tail -= 1;
    if (arr->tail == -1) {
        arr->tail = arr->size - 1;
    }
    return tmp;
}

//是否为空
int RecArray_IsEmpty(Rec_Array *arr) {
    return (arr->tail + 1) % arr->size == arr->front;
}

//是否已满
int RecArray_IsFull(Rec_Array *arr) {
    return (arr->tail + 2) % arr->size == arr->front;
};

void RecArray_Free(Rec_Array *arr) {
    free(arr->pAddr);
    free(arr);
}