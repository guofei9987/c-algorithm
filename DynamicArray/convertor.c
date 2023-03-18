//各种数据类型之间的相互转换

#include "convertor.h"
#include "Hash.h"

DynamicArray *LinkedList2DynamicArray(LinkedList *linkedList) {
    DynamicArray *dynamicArray = DynamicArray_Init(30);
    LinkedNode *p = linkedList->head;
    while (p->next) {
        DynamicArray_Push(dynamicArray, p->next->val);
        p = p->next;
    }
    return dynamicArray;
}


DynamicArray *HashSet2Array(HashSet *obj) {
    DynamicArray *dynamicArray = DynamicArray_Init(30);
    for (int i = 0; i < obj->num_bucket; i++) {
        LinkedNode *p = obj->linkedList[i]->head;
        while (p->next) {
            DynamicArray_Push(dynamicArray, p->next->val);
            p = p->next;
        }
    }
    return dynamicArray;
}