#include <stdio.h>

#include "DynamicArrayP.h"
#include "Test_DynamicArrayP.h"
#include "assert.h"

typedef struct PERSON {
    char name[64];
    int age;
} Person;


static void My_Print_P(Person *data) {
    printf("[name=%s,age=%d];", data->name, data->age);
}

static int My_COMPARE_DATA(const void *data1, const void *data2) {
    Person *data1_ = (Person *) data1;
    Person *data2_ = (Person *) data2;
    return (data1_->age == data2_->age) && (!strcmp(data1_->name, data2_->name));
}


int tst_DynamicArrayP() {
    printf("======测试 %s ======\n", __FILE_NAME__);

    DynamicArrayP *dynamicArray = DynamicArrayP_Init(50);

    Person p[] = {{"a", 1},
                  {"b", 2},
                  {"c", 3},
                  {"d", 4},
                  {"e", 5}
    };

    for (int i = 0; i < sizeof(p) / sizeof(Person); i++) {
        DynamicArrayP_PushTail(dynamicArray, &p[i]);
    }
    DynamicArrayP_Print(dynamicArray, (void *) My_Print_P);

    assert(((Person *) DynamicArrayP_GetByIdx(dynamicArray, 4))->age == 5);

    Person p_tmp = {"f", 9};
    DynamicArrayP_Push(dynamicArray, 2, &p_tmp);

    assert(((Person *) DynamicArrayP_GetByIdx(dynamicArray, 2))->age == 9);
    assert(dynamicArray->size == 6);


    DynamicArrayP_Pop(dynamicArray, 3);
    assert(((Person *) DynamicArrayP_GetByIdx(dynamicArray, 3))->age == 4);

    DynamicArrayP_Print(dynamicArray, (void *) My_Print_P);


    DynamicArrayP_PopTail(dynamicArray);
    assert(dynamicArray->size == 4);


    int idx_find = DynamicArrayP_Find(dynamicArray, &p[1], My_COMPARE_DATA);
    assert(idx_find == 1);

//    比较：内存相同
    Person new_person = {"b", 2};
    idx_find = DynamicArrayP_Find(dynamicArray, &new_person, My_COMPARE_DATA);
    assert(idx_find == 1);


    Person *p_find = DynamicArrayP_GetByIdx(dynamicArray, 2);
    assert(p_find->age == 9);

    DynamicArrayP_SetByIdx(dynamicArray, 2, &p[4]);
    DynamicArrayP_Print(dynamicArray, (void *) My_Print_P);
    assert(((Person *) DynamicArrayP_GetByIdx(dynamicArray, 2))->age == 5);


// 释放空间
    DynamicArrayP_Free(dynamicArray);

    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;
}