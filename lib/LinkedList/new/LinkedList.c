#include "LinkedList.h"

Linked_List *Init_Linked_List() {
    Linked_List *linkedList = (Linked_List *) malloc(sizeof(Linked_List));
    linkedList->head.next = NULL;
    linkedList->size = 0;
    return linkedList;
}


void Insert_Linked_List(Linked_List *linkedList, int idx, Linked_Node *data) {
    if (linkedList == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    if (idx < 0 || idx > linkedList->size) {
        idx = linkedList->size;
    }

    Linked_Node *pCurr = &(linkedList->head);
    for (int i = 0; i < idx; i++) {
        pCurr = pCurr->next;
    }

    data->next = pCurr->next;
    pCurr->next = data;
    linkedList->size++;

}

void Remove_Linked_List(Linked_List *linkedList, int idx) {
    if (linkedList == NULL) {
        return;
    }
    if (idx < 0 || idx >= linkedList->size) {
        return;
    }

    Linked_Node *pCurr = &(linkedList->head);
    for (int i = 0; i < idx; i++) {
        pCurr = pCurr->next;
    }

    pCurr->next = pCurr->next->next;
    linkedList->size--;
}

int Find_Linked_List(Linked_List *linkedList, Linked_Node *data, COMPARE_NODE compareNode) {
    if (linkedList == NULL) {
        return -1;
    }
    if (data == NULL) {
        return -1;
    }

    Linked_Node *pCurr = &(linkedList->head);

    int idx = 0;

    while (pCurr != NULL) {
        if (compareNode(pCurr, data) == 0) {
            return idx;
        }
        pCurr = pCurr->next;
        idx++;
    }

    return idx;


}


void Print_Linked_List(Linked_List *linkedList, PRINT_NODE printNode) {
    if (linkedList == NULL) {
        return;
    }

    Linked_Node *pCurr = linkedList->head.next;
    while (pCurr != NULL) {
        printNode(pCurr);
        pCurr = pCurr->next;
    }
    printf("\n");
}


void Free_Linked_List(Linked_List *linkedList) {
    if (linkedList == NULL) {
        return;
    }

    free(linkedList);
}