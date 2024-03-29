#include "HashTable.h"
#include <string.h>

//TODO：不会：
//接收 "比较key的函数"(函数指针)，返回 "比较KV的函数"（函数指针）
//做这个转化是为了复用 LinkedListP，而它对应的 cmp 函数指针，其输入是整个data



HashTable *HashTable_Init(int num_buckets,
                          unsigned hash(const void *key),
                          int cmp(const void *data1, const void *data2)
) {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->linkedListP = malloc(num_buckets * sizeof(LinkedListP));
    hashTable->cmp = cmp;
    hashTable->hash = hash;
    hashTable->num_buckets = num_buckets;

    for (int i = 0; i < num_buckets; i++) {
        hashTable->linkedListP[i] = LinkedListP_New();
    }
    return hashTable;
}


//向HashTable中塞入数据
void HashTable_Add(HashTable *obj, void *key, void *val) {
    KV *kv = malloc(sizeof(KV));
    kv->key = key;
    kv->val = val;

    LinkedListP_Insert(obj->linkedListP[obj->hash(key) % obj->num_buckets], 0, kv);
}


//删除数据
void HashTable_Del(HashTable *obj, void *key) {
    KV tmp = {key, NULL};
    LinkedListP_DelByVal(obj->linkedListP[obj->hash(key) % obj->num_buckets], &tmp, obj->cmp);
}


//根据 key，返回 val
void *HashTable_Get(HashTable *obj, void *key) {
    KV tmp = {key, NULL};
    LinkedNodeP *p = LinkedListP_Find2(obj->linkedListP[obj->hash(key) % obj->num_buckets], &tmp, obj->cmp);
    if (p == NULL) {
        return NULL;
    }
    return ((KV *) (p->data))->val;
}


//判断是否在 HashTable 里面
int HashTable_Has(HashTable *obj, void *key) {
    return HashTable_Get(obj, key) != NULL;
}


void HashTable_Free(HashTable *obj) {
    for (int i = 0; i < obj->num_buckets; i++) {
        LinkedListP_Free(obj->linkedListP[i]);
    }
    free(obj->linkedListP);
    free(obj);
}