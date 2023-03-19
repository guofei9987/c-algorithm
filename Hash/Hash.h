//
// Created by 郭飞 on 2023/3/18.
//

#ifndef C_ALGORITHM_HASH_H
#define C_ALGORITHM_HASH_H

#include "LinkedList.h"

//下面构建HashMap
typedef struct HashElement {
    LinkedList *link;
} HashElement;

typedef struct HashSet {
    LinkedList **linkedList;
    int num_bucket;
} HashSet;


HashSet *HashSet_Init(int num_bucket);

//向HashMap中塞入数据
void HashMap_Add(HashSet *obj, int key);

//删除数据
void HashSet_del(HashSet *obj, int key);

//判断是否在 HashSet 里面
int HashMap_Has(HashSet *obj, int key);

void HashMap_Free(HashSet *obj);

#endif //C_ALGORITHM_HASH_H
