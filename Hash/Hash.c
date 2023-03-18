#include <stdio.h>
#include "Hash.h"
#include "LinkedList.h"
#include "DynamicArray.h"
// 要做 dict：可以改动 LinkedNode，它的值字段改为 int key, int val
// 要支持所有类型：LinkedNode 的字段可以用 void*
// 这里只实现一个最简单的：HashSet<int>


//全局最多运行一次
void init_scatter() {
    static int has_scatter = 0;
    static unsigned long scatter[256];
    if (!has_scatter) {
        has_scatter = 1;
        for (int i = 0; i < 256; i++) {
            scatter[i] = rand();
        }
        printf("Hash scatter inited ok\n");
    }
}


// str -> hash
int hash_str(int len_str, const char *str) {
    static unsigned long scatter[256];
    int h = 0;
    for (int i = 0; i < len_str; i++) {
        h = (h << 1) + scatter[(unsigned char) str[i]];
    }
    return h;
}

// int -> hash
int hash_int(int x) {
    return x;
}


//下面构建HashMap
typedef struct HashElement {
    LinkedList *link;
} HashElement;

typedef struct HashSet {
    HashElement *hashElement;
    int num_bucket;
} HashSet;


HashSet *HashSet_Init(int num_bucket) {
    HashSet *obj = malloc(sizeof(HashSet));
    obj->hashElement = malloc(num_bucket * sizeof(HashElement));
    obj->num_bucket = num_bucket;
    return obj;
}

void HashMap_Add(HashSet *obj, int key) {
    LinkedListAddAtHead(obj->hashElement[hash_int(key) % obj->num_bucket].link, key);
}

void HashSet_del(HashSet *obj, int key) {
    LinkedListDelByVal(obj->hashElement[hash_int(key) % obj->num_bucket].link, key);
}


void HashSet2Array(HashSet *obj) {
    Dynamic_Array *dynamicArray = Init_Dynamic_Array(30);

//    Push_Dynamic_Array(dynamicArray,)

}