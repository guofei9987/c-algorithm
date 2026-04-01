#include "Test_LinkedList.h"
#include "LinkedList.h"
#include "convertor.h"

#include <assert.h>
#include <stdio.h>

int test_LinkedList() {
//    printf("======测试 %s ======\n", __FILE_NAME__);

    LinkedList *linkedList = LinkedList_Init();
    LinkedList_AddAtHead(linkedList, 1);
    LinkedList_AddAtHead(linkedList, 2);
    LinkedList_AddAtTail(linkedList, 3);
    LinkedList_AddAtIndex(linkedList, 1, 5);

    assert(LinkedList_Get(linkedList, 1) == 5);

    LinkedList_DelAtIndex(linkedList, 1);

    assert(LinkedList_Get(linkedList, 1) == 1);

    DynamicArray *dynamicArray = LinkedList2DynamicArray(linkedList);
    DynamicArray_Print(dynamicArray);
    free(dynamicArray);

    LinkedList_Free(linkedList);


//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);

    return 0;
}
