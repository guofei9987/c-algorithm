#include "assert.h"
#include "Test_Hash.h"
#include "Hash.h"
#include "convertor.h"

int test_Hash() {


    HashSet *hashSet = HashSet_Init(1024);
    for (int i = 0; i < 20; i++) {
//        重复加入
        HashMap_Add(hashSet, i / 2);
    }


    assert(HashMap_Has(hashSet, 1));
    assert(HashMap_Has(hashSet, 5));
    assert(!HashMap_Has(hashSet, 10));
    HashSet_del(hashSet, 5);
    HashSet_del(hashSet, 5);

    assert(!HashMap_Has(hashSet, 5));


    DynamicArray *dynamicArray = HashSet2Array(hashSet);
    DynamicArray_Print(dynamicArray);

    HashMap_Free(hashSet);
    DynamicArray_Free(dynamicArray);
    return 0;
}

