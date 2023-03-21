#include <assert.h>
#include "DynamicArray.h"
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
    DynamicArray_Print(arr);

    DynamicArray_Free(arr);
//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;

}