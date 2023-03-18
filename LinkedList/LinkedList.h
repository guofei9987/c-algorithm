#ifndef C_ALGORITHM_LINKEDLIST_H
#define C_ALGORITHM_LINKEDLIST_H


#include <stdlib.h>

//链表结点
typedef struct LINKED_NODE {
    int val;  //指向任何类型的数据
    struct LINKED_NODE *next;
} LinkedNode;


typedef struct {
    LinkedNode *head;
    int size;
} LinkedList;

LinkedList *LinkedList_Init();

int LinkedListGet(LinkedList *obj, int idx);

void LinkedListAddAtHead(LinkedList *obj, int val);

void LinkedListAddAtTail(LinkedList *obj, int val);

void LinkedListAddAtIndex(LinkedList *obj, int idx, int val);

void LinkedListDeleteAtIndex(LinkedList *obj, int idx);

int LinkedList_DelByVal(LinkedList *obj, int val);

int LinkedList_Find(LinkedList *obj, int val);

void LinkedListFree(LinkedList *obj);

#endif //C_ALGORITHM_LINKEDLIST_H
