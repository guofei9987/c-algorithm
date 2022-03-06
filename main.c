//
// Created by 郭飞 on 2022/3/6.
//
#include<stdio.h>
#include "kmp.h"
int main() {
    int i = KMP("ababcabcacbab", "abcac");
    printf("%d", i);
    return 0;
}