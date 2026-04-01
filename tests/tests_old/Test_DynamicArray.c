#include <assert.h>
#include "DynamicArray.h"
#include "RecurrentArray.h"
#include "Test_DynamicArray.h"


int test_DynamicArray() {
//    printf("======测试 %s ======\n", __FILE_NAME__);

    DynamicArray *arr = DynamicArray_Init(20);

    for (int i = 0; i < 20; i++) {
        DynamicArray_Push(arr, i);
    }

    DynamicArray_Print(arr);

    DynamicArray_Pop(arr, 3);
    DynamicArray_Print(arr);

    assert(DynamicArray_Find(arr, 5) == 4);
    assert(DynamicArray_Get(arr, 5) == 6);


    DynamicArray_Set(arr, 0, 30);
    DynamicArray_LoseWeight(arr);
    DynamicArray_Print(arr);

    DynamicArray_Free(arr);
//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;

}


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
