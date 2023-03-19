//
// Created by 郭飞 on 2023/3/18.
//
#include "HashTable.h"
#include "Test_HashTable.h"
#include "convertor.h"
#include <assert.h>

typedef struct PERSON {
    char name[64];
    int age;
} Person;


static void My_Print_P(void *data) {
    printf("%s: %s ,", ((KV *) data)->key, ((KV *) data)->val);
}


int test_HashTable() {
    printf("======测试 %s ======\n", __FILE_NAME__);

    HashTable *hashTable = HashTable_Init(20);
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
    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);

    return 0;
}
