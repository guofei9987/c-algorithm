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

void HashMap_Add(HashSet *obj, int key);

void HashSet_del(HashSet *obj, int key);

int HashMap_Has(HashSet *obj, int key);


#endif //C_ALGORITHM_HASH_H
