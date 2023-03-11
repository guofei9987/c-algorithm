#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tests/Test_DynamicArray.h"
#include "tests/Test_DynamicArrayP.h"
#include "tests/Test_LinkList.h"
#include "tests/Test_RecurrentArray.h"


int main() {

//    循环 Array
    test_Rec_Array();

    test_DynamicArray();

    tst_DynamicArrayP();

    test_LinkList();

    return 0;
}