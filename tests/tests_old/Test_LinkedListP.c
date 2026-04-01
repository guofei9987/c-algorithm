#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListP.h"

//自定义数据类型
typedef struct PERSON {
    char name[64];
    int age;
    int score;
} Person;


//打印函数
void MyPrint(void *data) {
    Person *p = (Person *) data;
    printf("<Name:%s Age:%d Score:%d>\n", p->name, p->age, p->score);
}

//比较指针是否相同
static int MyCmp(const void *data1,const void *data2){
    return data1==data2;
}


int test_LinkList(void) {
//    printf("======测试 %s ======\n", __FILE_NAME__);


    //创建链表
    LinkedListP *linkedListP = LinkedListP_New();

    //创建数据

    Person p[] = {{"aaa", 18, 100},
                  {"bbb", 19, 99},
                  {"ccc", 20, 101},
                  {"ddd", 17, 97},
                  {"eee", 16, 59}};


    for (int i = 0; i < sizeof(p) / sizeof(Person); i++) {
        LinkedListP_Insert(linkedListP, 0, p + i);
    }

    //打印
    Print_LinkList(linkedListP, MyPrint);

    //删除3
    LinkedListP_DelByIdx(linkedListP, 3);

    //打印
    printf("---------------\n");
    Print_LinkList(linkedListP, MyPrint);

    //返回第一个结点
    printf("-----查找结果------------\n");
    Person *ret = (Person *) LinkedListP_GetFront(linkedListP);
    printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);

    //销毁链表
    LinkedListP_Free(linkedListP);

//    printf("=====测试完成 %s =====\n\n\n", __FILE_NAME__);
    return 0;
}