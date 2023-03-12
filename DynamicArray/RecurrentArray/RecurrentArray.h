#ifndef C_ALGORITHM_RECURRENT_H
#define C_ALGORITHM_RECURRENT_H

#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE 100;

#define DATA_TYPE int

//循环array
typedef struct REC_ARRAY {
    DATA_TYPE *pAddr;
    int front;
    int tail;
    int size;
    int capacity;
} Rec_Array;


//当循环array为空和满的时候，都满足 front = tail
//因此2种设计：
// 1. 少用一个元素，front=tail为空。front=tail+1 为满。
// 2. 额外维护一个区分队列空和满的标志。
// 3. 扩展2，维护的是"元素个数"
// 准备实现第一种，因为"元素个数"可以用 (r-f+n)%n 来计算，节省维护 size 的消耗


Rec_Array *Init_REC_ARRAY(int capacity);

//尾部插入
void Push_Rec_Array(Rec_Array *arr, DATA_TYPE val);

// 获取头部
DATA_TYPE Get_Front_Rec_Array(Rec_Array *arr);

//删除头部
void Del_Front_Rec_Array(Rec_Array *arr);

// 获取头部，然后删掉它
DATA_TYPE Pop_Front_Rec_Array(Rec_Array *arr);


//获取尾巴
DATA_TYPE Get_Tail_Rec_Array(Rec_Array *arr);

//去除尾巴并返回它
DATA_TYPE Pop_Tail_Rec_Array(Rec_Array *arr);

//是否为空
int Is_Empty_Rec_Array(Rec_Array *arr);

//是否已满
int Is_Full_Rec_Array(Rec_Array *arr);


#endif //C_ALGORITHM_RECURRENT_H
