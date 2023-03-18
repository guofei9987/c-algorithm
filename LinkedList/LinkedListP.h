#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdlib.h>
#include<stdio.h>

//链表结点
typedef struct LINKED_NODE_P {
    struct LINKED_NODE_P *next;
    void *data;  //指向任何类型的数据
} LinkedNodeP;

//链表结构体
typedef struct LINKED_LIST {
    LinkedNodeP *head;
    int size;
} LinkedList;


//初始化链表
LinkedList *LinkedListP_New();

//TODO: 获取指定位置
int LinkedListP_GetByIdx(LinkedList *list, int idx);

//指定位置插入
void LinkedListP_Insert(LinkedList *list, int idx, void *data);

//删除指定位置的值
void LinkedListP_DelByIdx(LinkedList *list, int idx);

//获得链表的长度
int LinkedListP_Size(LinkedList *list);

//查找
int LinkedListP_Find(LinkedList *list, void *data);

//返回第一个结点
void *LinkedListP_GetFront(LinkedList *list);

//释放链表内存
void LinkedListP_Free(LinkedList *list);


//不知道用户要打印什么，所以定义一个打印函数指针，用户传入print即可
typedef void(*PRINTLINKNODE)(void *);

//打印链表结点
void Print_LinkList(LinkedList *list, PRINTLINKNODE print);

#endif