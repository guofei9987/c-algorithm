#include <stdio.h>
#include "Test_RecurrentArray.h"
#include "RecurrentArray.h"

int test_Rec_Array() {

//    printf("======测试 %s ======\n", __FILE_NAME__);
    Rec_Array *recArray = RecArray_Init(10);

    RecArray_Push(recArray, 1);
    RecArray_Push(recArray, 2);
    RecArray_Push(recArray, 3);
    RecArray_Push(recArray, 4);

    assert(RecArray_GetFront(recArray) == 1);
    assert(Pop_Front_Rec_Array(recArray) == 1);
    assert(Pop_Front_Rec_Array(recArray) == 2);
    RecArray_DelFront(recArray);
    assert(RecArray_GetFront(recArray) == 4);
    RecArray_Free(recArray);

//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;
}


