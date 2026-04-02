#include <assert.h>
#include "c_algorithm/linked_list/linked_list.h"

static void test_linked_list(void) {
    LinkedList *linkedList = LinkedList_Init();
    LinkedList_AddAtHead(linkedList, 1);
    LinkedList_AddAtHead(linkedList, 2);
    LinkedList_AddAtTail(linkedList, 3);
    LinkedList_AddAtIndex(linkedList, 1, 5);

    assert(LinkedList_Get(linkedList, 1) == 5);

    LinkedList_DelAtIndex(linkedList, 1);

    assert(LinkedList_Get(linkedList, 1) == 1);
    assert(LinkedList_Find(linkedList, 3) == 2);
    assert(LinkedList_Find(linkedList, 42) == -1);
    assert(LinkedList_DelByVal(linkedList, 42) == 0);
    assert(LinkedList_DelByVal(linkedList, 3) == 1);

    // TODO: 正在迁移中，converter 还没迁移，先注释掉
    //     DynamicArray *dynamicArray = LinkedList2DynamicArray(linkedList);
    // DynamicArray_Print(dynamicArray);
    // free(dynamicArray);

    LinkedList_Free(linkedList);
}

int main(void) {
    test_linked_list();
    return 0;
}
