//
// Created by 郭飞 on 2023/3/18.
//
#include "HashTable.h"
#include "Test_HashTable.h"
#include "convertor.h"
#include <assert.h>


static void My_Print_P(void *data) {
    printf("%s: %s ,", ((KV *) data)->key, ((KV *) data)->val);
}

//比较两个key是否相同
static int cmp(const void *key1, const void *key2) {
    return !strcmp(key1, key2);
}

//TODO：如何省略掉。取决于如何返回一个指向函数的指针
static int cmp_KV(const void *data1, const void *data2) {
    return cmp(
            ((KV *) data1)->key,
            ((KV *) data2)->key);
}


//hash函数
static unsigned int hash(const void *key) {
    return (unsigned long) key >> 2;
}

int test_HashTable() {
//    printf("======测试 %s ======\n", __FILE_NAME__);

    HashTable *hashTable = HashTable_Init(20, hash, cmp_KV);
    char *keys[] = {"hello", "world", "you", "good"};
    char *val[] = {"12", "34", "56", "7"};
    for (int i = 0; i < 4; i++) {
        HashTable_Add(hashTable, keys[i], val[i]);
    }

    DynamicArrayP *dynamicArrayP = HashTable2ArrayP(hashTable);
    printf("hashTable: {");
    DynamicArrayP_Print(dynamicArrayP, My_Print_P);
    printf("\t}\n");

    assert(HashTable_Has(hashTable, "hello") == 1);
    assert(HashTable_Has(hashTable, "Hello") == 0);


    HashTable_Del(hashTable, "hello");
    assert(HashTable_Has(hashTable, "hello") == 0);


    assert(!strcmp(HashTable_Get(hashTable, "you"), "56"));
    assert(HashTable_Get(hashTable, "hello") == NULL);


    HashTable_Free(hashTable);
//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);

    return 0;
}


static void My_Print_P2(void *data) {
    KV *kv = (KV *) data;
    printf("%d: %s ,", *((int *) kv->key), kv->val);
}

//比较两个key是否相同
static int cmp2(const void *key1, const void *key2) {
    return *((int *) key1) == *((int *) key2);
}

//TODO：如何省略掉。取决于如何返回一个指向函数的指针
static int cmp_KV2(const void *data1, const void *data2) {
    return cmp2(
            ((KV *) data1)->key,
            ((KV *) data2)->key);
}

static unsigned int hash2(const void *key) {
    return (unsigned long) (*(int *) key);
}


int test_HashTable_int() {
//    printf("======测试 %s ======\n", __FILE_NAME__);

    HashTable *hashTable = HashTable_Init(20, hash2, cmp_KV2);
    int keys[] = {1, 2, 3, 4};
    char *val[] = {"12", "34", "56", "7"};
    for (int i = 0; i < 4; i++) {
        HashTable_Add(hashTable, &keys[i], val[i]);
    }

    DynamicArrayP *dynamicArrayP = HashTable2ArrayP(hashTable);
    printf("hashTable: {");
    DynamicArrayP_Print(dynamicArrayP, My_Print_P2);
    printf("\t}\n");

    int a = 3;
    assert(HashTable_Has(hashTable, &a));
    int b = 5;
    assert(!HashTable_Has(hashTable, &b));

    HashTable_Del(hashTable, &a);
    assert(!HashTable_Has(hashTable, &a));

    int c=1;
    assert(!strcmp(HashTable_Get(hashTable, &c), "12"));
    assert(HashTable_Get(hashTable, &a) == NULL);

    HashTable_Free(hashTable);
//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);

    return 0;
}
