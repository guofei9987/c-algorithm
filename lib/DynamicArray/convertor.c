//各种数据类型之间的相互转换
#include "convertor.h"
#include "DynamicArrayP.h"
#include "DynamicArray.h"
#include "Hash.h"
#include "HashTable.h"

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


DynamicArrayP *HashTable2ArrayP(HashTable *obj) {
    DynamicArrayP *dynamicArrayP=DynamicArrayP_Init(50);

    for (int i = 0; i < obj->num_buckets; i++) {
        LinkedNodeP *p = obj->linkedListP[i]->head;
        while (p->next) {
            DynamicArrayP_PushTail(dynamicArrayP, p->next->data);
            p = p->next;
        }
    }
    return dynamicArrayP;

}