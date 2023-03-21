#include <stdio.h>
#include "Test_RecurrentArray.h"
#include "RecurrentArray.h"

int test_Rec_Array() {

//    printf("======测试 %s ======\n", __FILE_NAME__);
    Rec_Array *recArray = Init_REC_ARRAY(10);

    Push_Rec_Array(recArray, 1);
    Push_Rec_Array(recArray, 2);
    Push_Rec_Array(recArray, 3);
    Push_Rec_Array(recArray, 4);

    assert(Get_Front_Rec_Array(recArray) == 1);
    assert(Pop_Front_Rec_Array(recArray) == 1);
    assert(Pop_Front_Rec_Array(recArray) == 2);
    Del_Front_Rec_Array(recArray);
    assert(Get_Front_Rec_Array(recArray) == 4);

//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;
}


