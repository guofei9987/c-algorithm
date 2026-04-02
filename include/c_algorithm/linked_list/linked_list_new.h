/*
侵入式链表：

优点：
- 零额外内存分配。不需要 malloc 单独节点，cache locality 更好
- 支持“一对象多链表”
缺点：
struct MyData {
    int value;
    struct ListNode list1;
    struct ListNode list2;
};
- 性能极高

缺点：
- 强耦合，业务代码必须包含链表节点（侵入性强）
- 可读性差
- 不安全。类型写错则会造成不可预知错误

典型应用：Linux 内核链表，Redis 链表
*/

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
