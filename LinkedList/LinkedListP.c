#include"LinkedListP.h"

//初始化链表
LinkList *Init_LinkList() {

    LinkList *pLinklist = (LinkList *) malloc(sizeof(LinkList));
    pLinklist->size = 0;

    //头结点 不保存数据信息
    pLinklist->head = (LinkNode *) malloc(sizeof(LinkNode));
    pLinklist->head->data = NULL;
    pLinklist->head->next = NULL;

    return pLinklist;
}

//指定位置插入
void Insert_LinkList(LinkList *list, int pos, void *data) {

    if (list == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }

    if (pos < 0 || pos > list->size) {
        pos = list->size;
    }

    //创建新的结点
    LinkNode *newnode = (LinkNode *) malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;

    //找结点
    //辅助指针变量
    LinkNode *pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    //新结点入链表
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    list->size++;

}


//删除指定位置的值
void RemoveByPos_LinkList(LinkList *list, int pos) {
    if (list == NULL) {
        return;
    }

    if (pos < 0 || pos >= list->size) {
        return;
    }

    //查找删除结点的前一个结点
    LinkNode *pCurrent = list->head;
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }

    //缓存删除的结点
    LinkNode *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    //释放删除结点的内存
    free(pDel);

    list->size--;
}

//获得链表的长度
int Size_LinkList(LinkList *list) {
    return list->size;
}

//查找
int Find_LinkList(LinkList *list, void *data) {
    if (list == NULL) {
        return -1;
    }

    if (data == NULL) {
        return -1;
    }

    //遍历查找
    LinkNode *pCurrent = list->head->next;
    int i = 0;
    while (pCurrent != NULL) {
        if (pCurrent->data == data) {
            break;
        }
        i++;
        pCurrent = pCurrent->next;
    }

    return i;
}

//返回第一个结点
void *Front_LinkList(LinkList *list) {
    return list->head->next->data;
}

//打印链表结点
void Print_LinkList(LinkList *list, PRINTLINKNODE print) {
    if (list == NULL) {
        return;
    }
    //辅助指针变量
    LinkNode *pCurrent = list->head->next;
    while (pCurrent != NULL) {
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }

}

//释放链表内存
void FreeSpace_LinkList(LinkList *list) {

    if (list == NULL) {
        return;
    }

    //辅助指针变量
    LinkNode *pCurrent = list->head;
    while (pCurrent != NULL) {
        //缓存下一个结点
        LinkNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    //释放链表内存
    free(list);
}