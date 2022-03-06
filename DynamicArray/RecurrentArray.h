#ifndef C_ALGORITHM_RECURRENT_H
#define C_ALGORITHM_RECURRENT_H

#define MAX_SIZE 100;

//循环array
typedef struct REC_ARRAY {
    void *pAddr;
    int front;
    int tail;
    int size;
    int capacity;
} RecArray;


//当循环array为空和满的时候，都满足 front = tail
//因此2种设计：
// 1. 少用一个元素，front=tail为空。front=tail+1 为满。
// 2. 额外维护一个区分队列空和满的标志。
// 3. 扩展2，维护的是"元素个数"
// 准备实现第一种，因为"元素个数"可以用 (r-f+n)%n 来计算，节省维护 size 的消耗

#endif //C_ALGORITHM_RECURRENT_H
