#include "LinkedList.h"


//统一建造含 dummy 的 LinkedList
LinkedList *LinkedListCreate() {
    LinkedList *obj = malloc(sizeof(LinkedList));
    obj->size = 0;
    obj->head = malloc(sizeof(LinkedNode));
    obj->head->next = NULL;
    return obj;
}


int LinkedListGet(LinkedList *obj, int idx) {
    if (idx >= obj->size) {
        return -1;
    }
    LinkedNode *p = obj->head;
    for (int i = 0; i <= idx; i++) {
        p = p->next;
    }
    return p->val;
}

void LinkedListAddAtHead(LinkedList *obj, int val) {
    LinkedNode *new = malloc(sizeof(LinkedNode));
    new->val = val;
    new->next = obj->head->next;
    obj->head->next = new;

    obj->size++;
}

void LinkedListAddAtTail(LinkedList *obj, int val) {
    LinkedNode *p = obj->head;
    while (p->next) {
        p = p->next;
    }
    LinkedNode *new = malloc(sizeof(LinkedNode));
    new->val = val;
    new->next = NULL;
    p->next = new;

    obj->size++;
}

void LinkedListAddAtIndex(LinkedList *obj, int idx, int val) {
    if (idx > obj->size) {
        return;
    }
    LinkedNode *p = obj->head;
    for (int i = 0; i < idx; i++) {
        p = p->next;
    }
    LinkedNode *new = malloc(sizeof(LinkedNode));
    new->val = val;
    new->next = p->next;
    p->next = new;

    obj->size++;
}

void LinkedListDeleteAtIndex(LinkedList *obj, int idx) {
    if (idx >= obj->size) {
        return;
    }
    LinkedNode *p = obj->head;
    for (int i = 0; i < idx; i++) {
        p = p->next;
    }
//    通常需要释放内存
    LinkedNode *tmp = p->next;
    p->next = p->next->next;
    free(tmp);

    obj->size--;
}

//删除第一个出现的val，未充分测试
int LinkedListDelByVal(LinkedList *obj, int val) {
    LinkedNode *p = obj->head;
    while (p->next) {
        if (p->next->val == val) {
            LinkedNode *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            obj->size--;
            return 1; // 成功删除
        }
    }
    return 0;// 未找到
}



void LinkedListFree(LinkedList *obj) {
    LinkedNode *p = obj->head;
    while (p) {
        LinkedNode *p_next = p->next;
        free(p);
        p = p_next;
    }
}
