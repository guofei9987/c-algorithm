#include <assert.h>
#include "DynamicArray.h"
#include "Test_DynamicArray.h"



int test_DynamicArray() {
    printf("======测试 %s ======\n", __FILE_NAME__);

    Dynamic_Array *arr = Init_Dynamic_Array(20);

    for (int i = 0; i < 30; i++) {
        Push_Dynamic_Array(arr, i);
    }

    Print_Dynamic_Array(arr);

    Pop_Dynamic_Array(arr, 3);
    Print_Dynamic_Array(arr);

    assert(Find_Dynamic_Array(arr, 5) == 4);
    assert(Get_Dynamic_Array(arr, 5) == 6);


    Set_Dynamic_Array(arr, 0, 30);
    Print_Dynamic_Array(arr);

    Free_Dynamic_Array(arr);
    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;

}