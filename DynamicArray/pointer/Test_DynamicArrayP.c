#include <stdio.h>

#include "DynamicArrayP.h"

typedef struct PERSON {
    char name[64];
    int age;
} Person;


void My_Print(Person *data) {
    printf("[name=%s,age=%d];", data->name, data->age);
}


int tst_DynamicArrayP() {

    Dynamic_Array_P *dynamicArray = Init_Dynamic_Array_P();


    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "a");
    strcpy(p2.name, "b");
    strcpy(p3.name, "c");
    strcpy(p4.name, "d");
    strcpy(p5.name, "e");

    p1.age = 1;
    p2.age = 2;
    p3.age = 3;
    p4.age = 4;
    p5.age = 5;

    Push_Last_Dynamic_Array_P(dynamicArray, &p1);
    Push_Last_Dynamic_Array_P(dynamicArray, &p2);
    Push_Last_Dynamic_Array_P(dynamicArray, &p3);
    Push_Last_Dynamic_Array_P(dynamicArray, &p4);
    Push_Last_Dynamic_Array_P(dynamicArray, &p5);


    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print);
    printf("\npush idx = 2:\n");
    Push_Dynamic_Array_P(dynamicArray, 2, &p5);


    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print);

    printf("\ndelete idx = 3:\n");
    Pop_Dynamic_Array_P(dynamicArray, 3);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print);

    printf("delete tail:\n");
    Pop_Last_Dynamic_Array_P(dynamicArray);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print);


    printf("\nfind idx by data:\n");
    int idx_find = Find_Dynamic_Array_P(dynamicArray, &p2);
    printf("result is idx=%d:\n", idx_find);

    printf("get data by idx=2:");
    Person *p_find = Get_Dynamic_Array_P(dynamicArray, 2);
    My_Print(p_find);
    printf("\n");

    Set_Dynamic_Array_P(dynamicArray, 2, &p4);
    Print_Dynamic_Array_P(dynamicArray, (void *) My_Print);


// 释放空间
    Free_Dynamic_Array_P(dynamicArray);

}