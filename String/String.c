//
// Created by 郭飞 on 2023/2/23.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//写一个类似 array of string 的结构

struct String {
    char *data;
    int len;
    int cap;
};

//新建
struct String *string_build(char *s, int len_s, int cap) {
    struct String *string = malloc(sizeof(struct String));
    string->data = calloc(cap, sizeof(char));
    strcpy(string->data, s);
    string->len = len_s;
    string->cap = cap;
    return string;
}

//添加一个char
struct String *string_append(struct String *string, char c) {
    if (string->len + 1 > string->cap) {
//        需要扩展内存
        string->cap = string->cap * 2 + 1;
        string->data = realloc(string->data, string->cap);
    }

    string->data[string->len] = c;
    string->len += 1;

    string->data[string->len] = 0;

    return string;
}

//添加一个 char *
struct String *string_add(struct String *string, char *s, int len_s) {
    if (string->len + len_s > string->cap) {
//      扩展内存
        string->cap = string->len + len_s;
        string->data = realloc(string->data, string->cap);
    }
//    这个性能高呢，还是用for循环性能高呢？
    memcpy(string->data + string->len, s, len_s);
    return string;
}


//减少内存占用
struct String loss_weight();

//销毁
//手动free（2次）即可

int main() {

    char *s = "hello world!";
    struct String *s1 = string_build(s, strlen(s), 30);

//    添加一个字符
    string_append(s1, '?');

//    t添加一个字符串
    char *s2 = "hello clang";
    string_add(s1, s2, strlen(s2));
    printf("%s\n", s1->data);
}





