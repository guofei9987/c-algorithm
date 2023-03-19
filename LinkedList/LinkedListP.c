#include"LinkedListP.h"

//初始化链表
LinkedListP *LinkedListP_New() {

    LinkedListP *pLinklist = (LinkedListP *) malloc(sizeof(LinkedListP));
    pLinklist->size = 0;

    //头结点 不保存数据信息
    pLinklist->head = (LinkedNodeP *) malloc(sizeof(LinkedNodeP));
    pLinklist->head->data = NULL;
    pLinklist->head->next = NULL;

    return pLinklist;
}

//指定位置插入
void LinkedListP_Insert(LinkedListP *list, int idx, void *data) {

    if (list == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }

    if (idx < 0 || idx > list->size) {
        idx = list->size;
    }

    //创建新的结点
    LinkedNodeP *newnode = (LinkedNodeP *) malloc(sizeof(LinkedNodeP));
    newnode->data = data;
    newnode->next = NULL;

    //找结点
    //辅助指针变量
    LinkedNodeP *pCurrent = list->head;
    for (int i = 0; i < idx; i++) {
        pCurrent = pCurrent->next;
    }

    //新结点入链表
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    list->size++;

}


//删除指定位置的值
void LinkedListP_DelByIdx(LinkedListP *list, int idx) {
    if (list == NULL) {
        return;
    }

    if (idx < 0 || idx >= list->size) {
        return;
    }

    //查找删除结点的前一个结点
    LinkedNodeP *pCurrent = list->head;
    for (int i = 0; i < idx; i++) {
        pCurrent = pCurrent->next;
    }

    //缓存删除的结点
    LinkedNodeP *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    //释放删除结点的内存
    free(pDel);

    list->size--;
}

//获得链表的长度
int LinkedListP_Size(LinkedListP *list) {
    return list->size;
}

//查找
int LinkedListP_Find(LinkedListP *list, void *data, LinkedList_Cmp_Fun linkedListCmpFun) {
    if (list == NULL) {
        return -1;
    }

    if (data == NULL) {
        return -1;
    }

    //遍历查找
    LinkedNodeP *pCurrent = list->head->next;
    int i = 0;
    while (pCurrent != NULL) {
        if (linkedListCmpFun(pCurrent->data, data)) {
            return i;
        }
        i++;
        pCurrent = pCurrent->next;
    }
    return -1;
}


//查找第一个命中，并返回其指针
void *LinkedListP_Find2(LinkedListP *list, void *data, LinkedList_Cmp_Fun linkedListCmpFun) {
    LinkedNodeP *pCurrent = list->head->next;
    while (pCurrent != NULL) {
        if (linkedListCmpFun(pCurrent->data, data)) {
            return pCurrent;
        }
        pCurrent = pCurrent->next;
    }
    return NULL;
}


//删除第一个出现的
int LinkedListP_DelByVal(LinkedListP *list, void *data, LinkedList_Cmp_Fun linkedListCmpFun) {
    LinkedNodeP *p = list->head;
    while (p->next) {
        if (linkedListCmpFun(p->next->data, data)) {
            LinkedNodeP *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            list->size--;
            return 1;// 成功删除

        }
    }
    return 0;// 未找到
};


//返回第一个结点
void *LinkedListP_GetFront(LinkedListP *list) {
    return list->head->next->data;
}

//打印链表结点
void Print_LinkList(LinkedListP *list, PRINTLINKNODE print) {
    if (list == NULL) {
        return;
    }
    //辅助指针变量
    LinkedNodeP *pCurrent = list->head->next;
    while (pCurrent != NULL) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }

}

//释放链表内存
void LinkedListP_Free(LinkedListP *list) {

    if (list == NULL) {
        return;
    }

    //辅助指针变量
    LinkedNodeP *pCurrent = list->head;
    while (pCurrent != NULL) {
        //缓存下一个结点
        LinkedNodeP *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    //释放链表内存
    free(list);
}