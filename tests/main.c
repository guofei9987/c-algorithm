#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tests/Test_DynamicArray.h"
#include "tests/Test_DynamicArrayP.h"
#include "tests/Test_LinkedList.h"
#include "tests/Test_Hash.h"
#include "tests/Test_LinkedListP.h"
#include "tests/Test_HashTable.h"
#include "tests/Test_String.h"

int main() {

//    循环 Array
    test_Rec_Array();

    test_DynamicArray();

    tst_DynamicArrayP();

    test_LinkedList();
    test_LinkList();


    test_Hash();

    test_HashTable();
    test_HashTable_int();

//    test_AC_DAT();

     test_ac_dat_keywords();

     test_ac_dat_pattern();
    return 0;
}


