#ifndef C_ALGORITHM_HASHTABLE_H
#define C_ALGORITHM_HASHTABLE_H

#include "LinkedListP.h"

typedef struct KV {
    void *key;
    void *val;
} KV;

typedef struct HashTable {
    LinkedListP **linkedListP;
    int num_buckets;

    int (*cmp)(const void *key1, const void *key2);

    unsigned (*hash)(const void *key);
} HashTable;


HashTable *HashTable_Init(int num_bucket);

//向HashTable中塞入数据
void HashTable_Add(HashTable *obj, void *key, void *val);

//删除数据
void HashTable_Del(HashTable *obj, void *key);

//判断是否在 HashTable 里面
int HashTable_Has(HashTable *obj, void *key);

//根据 key，返回 val
void *HashTable_Get(HashTable *obj, void *key);

void HashTable_Free(HashTable *obj);

#endif //C_ALGORITHM_HASHTABLE_H
