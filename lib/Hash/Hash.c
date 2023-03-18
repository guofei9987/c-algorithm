#include <stdio.h>
#include "Hash.h"

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


HashSet *HashSet_Init(int num_bucket) {
    HashSet *obj = malloc(sizeof(HashSet));
    obj->linkedList = malloc(num_bucket * sizeof(LinkedList));

    for (int i = 0; i < num_bucket; i++) {
        obj->linkedList[i] = LinkedList_Init();
    }


    obj->num_bucket = num_bucket;
    return obj;
}


void HashMap_Add(HashSet *obj, int key) {
    LinkedList *tmp = obj->linkedList[hash_int(key) % obj->num_bucket];
    if (LinkedList_Find(tmp, key) == -1) {
        LinkedListAddAtHead(tmp, key);
    }
}

int HashMap_Has(HashSet *obj, int key) {
    return LinkedList_Find(
            obj->linkedList[hash_int(key) % obj->num_bucket], key) != -1;
}

void HashSet_del(HashSet *obj, int key) {
    LinkedList_DelByVal(obj->linkedList[hash_int(key) % obj->num_bucket], key);
}



void HashMap_Free(HashSet *obj) {
    for (int i = 0; i < obj->num_bucket; i++) {
        LinkedListFree(obj->linkedList[i]);
    }
    free(obj->linkedList);
    free(obj);
}