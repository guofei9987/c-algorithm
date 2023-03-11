////
//// Created by 郭飞 on 2022/3/6.
////
//#include<stdio.h>
////#include "kmp.h"
////int main() {
////    int i = KMP("ababcabcacbab", "abcac");
////    printf("%d", i);
////    return 0;
////}
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include "DynamicArray/int/DynamicArray.h"
#include "DynamicArray/RecurrentArray/RecurrentArray.h"


//循环 Array
int test_Rec_Array() {
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

    return 0;
}


int test_DynamicArray() {

    Dynamic_Array *arr = Init_Dynamic_Array();

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
    return 0;

}

int main() {

    test_Rec_Array();

    test_DynamicArray();

//    int **returnColumnSizes;
//    printf("%ld",sizeof **returnColumnSizes);



}