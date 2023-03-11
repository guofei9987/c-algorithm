#include <stdio.h>

#include "DynamicArrayP.h"
#include "Test_DynamicArrayP.h"

typedef struct PERSON {
    char name[64];
    int age;
} Person;


void My_Print_P(Person *data) {
    printf("[name=%s,age=%d];", data->name, data->age);
}


int tst_DynamicArrayP() {
    printf("======测试 %s ======\n", __FILE_NAME__);

    Dynamic_Array_P *dynamicArray = Init_Dynamic_Array_P();

    Person p[] = {{"a", 1},
                  {"b", 2},
                  {"c", 3},
                  {"d", 4},
                  {"e", 5}
    };

    for (int i = 0; i < sizeof(p) / sizeof(Person); i++) {
        Push_Last_Dynamic_Array_P(dynamicArray, &p[i]);
    }
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print_P);


    printf("\npush idx = 2:\n");
    Person p_tmp = {"f", 9};
    Push_Dynamic_Array_P(dynamicArray, 2, &p_tmp);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print_P);


    printf("\ndelete idx = 3:\n");
    Pop_Dynamic_Array_P(dynamicArray, 3);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print_P);

    printf("delete tail:\n");
    Pop_Last_Dynamic_Array_P(dynamicArray);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print_P);


    printf("\nfind idx by data:\n");
    int idx_find = Find_Dynamic_Array_P(dynamicArray, &p[1]);
    printf("result is idx=%d:\n", idx_find);

    printf("\nget data by idx=2:\n");
    Person *p_find = Get_Dynamic_Array_P(dynamicArray, 2);
    My_Print_P(p_find);
    printf("\n");

    Set_Dynamic_Array_P(dynamicArray, 2, &p[4]);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print_P);


// 释放空间
    Free_Dynamic_Array_P(dynamicArray);

    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;
}