#include "RecurrentArray.h"


Rec_Array *Init_REC_ARRAY(int capacity) {
    Rec_Array *arr = (Rec_Array *) malloc(sizeof(Rec_Array));
    arr->front = 1;
    arr->tail = 0;
    arr->capacity = capacity;
    arr->size = capacity + 1;// array 的大小
    arr->pAddr = (DATA_TYPE *) malloc(sizeof(DATA_TYPE) * arr->size);

    return arr;
};

//尾部插入
void Push_Rec_Array(Rec_Array *arr, DATA_TYPE val) {
    assert(!Is_Full_Rec_Array(arr));
    arr->tail = (arr->tail + 1) % arr->size;
    arr->pAddr[arr->tail] = val;
};

// 获取头部
DATA_TYPE Get_Front_Rec_Array(Rec_Array *arr) {
    assert(!Is_Full_Rec_Array(arr));
    return arr->pAddr[arr->front];
}

//删除头部
void Del_Front_Rec_Array(Rec_Array *arr) {
    assert(!Is_Full_Rec_Array(arr));
    arr->front = (arr->front + 1) % arr->size;
}

// 获取头部，然后删掉它
DATA_TYPE Pop_Front_Rec_Array(Rec_Array *arr) {
    assert(!Is_Full_Rec_Array(arr));
    DATA_TYPE tmp = arr->pAddr[arr->front];
    arr->front = (arr->front + 1) % arr->size;
    return tmp;
}



//获取尾巴
DATA_TYPE Get_Tail_Rec_Array(Rec_Array *arr);

//去除尾巴并返回它
DATA_TYPE Pop_Tail_Rec_Array(Rec_Array *arr);

//是否为空
int Is_Empty_Rec_Array(Rec_Array *arr) {
    return (arr->tail + 1) % arr->size == arr->front;
};

//是否已满
int Is_Full_Rec_Array(Rec_Array *arr) {
    return (arr->tail + 2) % arr->size == arr->front;
};

void Free_Push_Rec_Array(Rec_Array *arr) {

    free(arr->pAddr);
    free(arr);
}