#ifndef C_ALGORITHM_LINKEDLIST_H
#define C_ALGORITHM_LINKEDLIST_H


#include <stdlib.h>

//链表结点
typedef struct LINKED_NODE {
    int val;
    struct LINKED_NODE *next;
} LinkedNode;


typedef struct {
    LinkedNode *head;
    int size;
} LinkedList;

LinkedList *LinkedList_Init();

int LinkedList_Get(LinkedList *obj, int idx);

void LinkedList_AddAtHead(LinkedList *obj, int val);

void LinkedList_AddAtTail(LinkedList *obj, int val);

void LinkedList_AddAtIndex(LinkedList *obj, int idx, int val);

void LinkedList_DelAtIndex(LinkedList *obj, int idx);

int LinkedList_DelByVal(LinkedList *obj, int val);

int LinkedList_Find(LinkedList *obj, int val);

void LinkedList_Free(LinkedList *obj);

#endif //C_ALGORITHM_LINKEDLIST_H
