
## 静态数组

略

## 动态数组

1动态数组，元素是int类型
2动态数组，元素 `void *`，这个动态数组的元素可以是任意类型
    - 可以自定义一个关于 `print` 的函数指针，从而调用 `DynamicArrayP_Print` 来打印整个动态数组
    - 

附加功能
1. 快速在末尾添加、删除（完成）
2. 实现 stack 的功能（完成）

## 循环数组

非常适合用来做 queue

附加功能
1. 动态扩容
2. 本身是array，因此也非常适合作为 stack，
3. 也就是首位插入都非常快的一种顺序表。


## 单向链表

1. 传统型链表
2. 挂载型链表


附加功能
1. 添加一个一直指向末尾的指针。非常适合用来做 queue


## 效率对比

动态数组：末尾增、删很快。任意位置取数很快。任意位置增删很慢。
- 改进为循环数组后，头部增删也快


链表：首取数很快。任意位置取数很慢。任意位置增删很快（但是得先取数）
- 增加尾部指针后，尾部取数也快


关于 stack 和 queue
- 顺序表适合做 stack。倒置适合做 queue
- 链表可以同时适合stack和queue
- 循环顺序表，同时适合 stack 和 queue



## kmp

BF(brute-force)在以下情况下表现很差
```c
char[] T = "aaaaaaaaab";
char[] pattern = "aaab";
```
最坏复杂度为 O(mn)

KMP 算法复杂度为 O(m+n)


https://www.bilibili.com/video/BV1jb411V78H

## list(广义表)

1. 类似python中的这种类型： [1,[1,2,3,[3,4]]]
2. 用链式存储实现




## 二叉树

## n叉树



