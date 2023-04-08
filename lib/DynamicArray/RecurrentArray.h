//循环 Array，头尾插入和删除都是O(1)，可以用来作为 queue/stack 来使用
//当循环array为空和满的时候，都满足 front = tail
//因此2种设计：
// 1. 少用一个元素，front=tail为空。front=tail+1 为满。
// 2. 额外维护一个区分队列空和满的标志。
// 3. 扩展2，维护的是"元素个数"
// 这里实现第1种，这样"元素个数"可以用 (r-f+n)%n 来计算，节省维护 size 的消耗

#ifndef C_ALGORITHM_RECURRENT_H
#define C_ALGORITHM_RECURRENT_H

#include <stdlib.h>
#include <assert.h>



#define DATA_TYPE int
typedef struct REC_ARRAY {
    DATA_TYPE *pAddr;
    int front;
    int tail;
    int size; // size 的大小，永远为 capacity + 1
    int capacity;
} Rec_Array;





Rec_Array *RecArray_Init(int capacity);

//尾部插入
void RecArray_Push(Rec_Array *arr, DATA_TYPE val);

// 获取头部
DATA_TYPE RecArray_GetFront(Rec_Array *arr);

//删除头部
void RecArray_DelFront(Rec_Array *arr);

// 获取头部，然后删掉它
DATA_TYPE Pop_Front_Rec_Array(Rec_Array *arr);


//获取尾巴
DATA_TYPE RecArray_GetTail(Rec_Array *arr);

//去除尾巴并返回它
DATA_TYPE RecArray_PopTail(Rec_Array *arr);

//是否为空
int RecArray_IsEmpty(Rec_Array *arr);

//是否已满
int RecArray_IsFull(Rec_Array *arr);

void RecArray_Free(Rec_Array *arr);
#endif //C_ALGORITHM_RECURRENT_H
