#include <stdio.h>

#include "DynamicArray.h"

int main() {

    Dynamic_Array *arr = Init_Dynamic_Array();

    for (int i = 0; i < 30; i++) {
        Push_Dynamic_Array(arr, i);
    }

    Print_Dynamic_Array(arr);

    Pop_Dynamic_Array(arr, 3);
    Print_Dynamic_Array(arr);

    printf("%d\n", Find_Dynamic_Array(arr, 5));
    printf("%d\n", Get_Dynamic_Array(arr, 5));


    Set_Dynamic_Array(arr, 0, 30);
    Print_Dynamic_Array(arr);

    Free_Dynamic_Array(arr);


}