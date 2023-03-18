#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdlib.h>
#include<stdio.h>

typedef struct LINKED_NODE {
    struct LINKED_NODE *next;
} Linked_Node;


typedef struct LINKED_LIST {
    Linked_Node head;
    int size;
} Linked_List;


//遍历函数指针
typedef void (*PRINT_NODE)(Linked_Node *);

//比较函数指针
typedef int (*COMPARE_NODE)(Linked_Node *, Linked_Node *);


Linked_List *Init_Linked_List();

//插入
void Insert_Linked_List(Linked_List *linkedList, int idx, Linked_Node *data);

//删除
void Remove_Linked_List(Linked_List *linkedList, int idx);

//查找
int Find_Linked_List(Linked_List *linkedList, Linked_Node *data, COMPARE_NODE compareNode);

//打印
void Print_Linked_List(Linked_List *linkedList, PRINT_NODE printNode);

//释放内存
void Free_Linked_List(Linked_List *linkedList);

#endif //LINKED_LIST_H