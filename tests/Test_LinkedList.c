#include "Test_LinkedList.h"
#include "LinkedList.h"
#include "convertor.h"

#include <assert.h>
#include <stdio.h>

int test_LinkedList() {
    printf("======测试 %s ======\n", __FILE_NAME__);

    LinkedList *linkedList = LinkedList_Init();
    LinkedListAddAtHead(linkedList, 1);
    LinkedListAddAtHead(linkedList, 2);
    LinkedListAddAtTail(linkedList, 3);
    LinkedListAddAtIndex(linkedList, 1, 5);

    assert(LinkedListGet(linkedList, 1) == 5);

    LinkedListDeleteAtIndex(linkedList, 1);

    assert(LinkedListGet(linkedList, 1) == 1);

    DynamicArray *dynamicArray = LinkedList2DynamicArray(linkedList);
    DynamicArray_Print(dynamicArray);
    free(dynamicArray);

    LinkedListFree(linkedList);


    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);

    return 0;
}
