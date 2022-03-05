#include <stdio.h>
#include <string.h>
#include <string.h>
#include "LinkedList.h"

typedef struct PERSON {
    Linked_Node linkedNode;
    char name[64];
    int age;
} Person;

void My_Print1(Linked_Node *node) {
    Person *p = (Person *) node;
    printf("[name = %s, age = %d] -> ", p->name, p->age);
}

int My_Compare(Linked_Node *node1, Linked_Node *node2) {
    Person *p1 = (Person *) node1;
    Person *p2 = (Person *) node2;

    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
        return 0;
    }
    return -1;
}

int test_LinkedList() {

    Linked_List *linkedList = Init_Linked_List();
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "a");
    strcpy(p2.name, "b");
    strcpy(p3.name, "c");
    strcpy(p4.name, "d");
    strcpy(p5.name, "e");

    p1.age = 1;
    p2.age = 2;
    p3.age = 3;
    p4.age = 4;
    p5.age = 5;

    Insert_Linked_List(linkedList, 0, (Linked_Node *) &p1);
    Insert_Linked_List(linkedList, 0, (Linked_Node *) &p2);
    Insert_Linked_List(linkedList, 0, (Linked_Node *) &p3);
    Insert_Linked_List(linkedList, 0, (Linked_Node *) &p4);
    Insert_Linked_List(linkedList, 0, (Linked_Node *) &p5);

    Print_Linked_List(linkedList, My_Print1);

    Remove_Linked_List(linkedList, 1);

    Print_Linked_List(linkedList, My_Print1);

//    查找
    Person p_find;
    strcpy(p_find.name, "b");
    p_find.age = 2;
    int idx = Find_Linked_List(linkedList, (Linked_Node *) &p_find, My_Compare);
    printf("%d", idx);

//    释放内存
    Free_Linked_List(linkedList);
}