#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tests/Test_DynamicArray.h"
#include "tests/Test_DynamicArrayP.h"
#include "tests/Test_RecurrentArray.h"
#include "tests/Test_LinkedList.h"
#include "tests/Test_Hash.h"
#include "tests/Test_LinkedListP.h"
#include "tests//Test_HashTable.h"

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
    return 0;
}



