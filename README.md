
# c- algorithm

用 c 实现常见的数据结构

如何安装
```bash
git clone git@github.com:guofei9987/c-algorithm.git
cd c-algorithm/
cmake -B ./build
cd build/
sudo make install

# 测试：
cmake .. -DDO_TEST="True"
make
ctest
```

## 静态数组

略

## 动态数组

1. 动态数组，元素是int类型
    - 实现在 [/DynamicArray/int](/lib/DynamicArray/int)
2. 动态数组，NodeData 是 `void *`，因此动态数组的元素可以是 **任意类型**
    - 实现在 [/DynamicArray/pointer](/lib/DynamicArray/pointer)
    - 可以自定义一个关于 **打印** 的函数指针，从而调用 `DynamicArrayP_Print` 来打印整个动态数组
    - 可以自定义一个关于 **比较** 的函数指针，从而调用 `DynamicArrayP_Find` 来查找符合某种条件的元素
    - 末尾添加/删除的复杂度 为 **O(1)**
    - 可以用来实现高效的 **Stack**
3. 循环数组，元素是 int 类型
    - 实现在 [/DynamicArray/RecurrentArray](/lib/DynamicArray/RecurrentArray)
    - 在 开头/末尾 的 添加/删除/修改，复杂度都是  **O(1)**
    - 暂时不支持 **动态扩容**，但可以新建时指定内存大小
    - 暂时不支持 **任意类型**
    - 可以用来实现高效的 **Stack** 和 **Queue**

## 单向链表

1. 单向链表，元素是 int 类型
    - 实现在 [/LinkedList/LinkedList.h](/lib/LinkedList/LinkedList.h)
2. 链表，NodeData是 `void *`，因此其元素可以是 **任意类型**
    - 实现在 [/LinkedList/LinkedListP.h](/lib/LinkedList/LinkedListP.h)





TODO:
1. 添加一个一直指向末尾的指针。非常适合用来做 queue


## Hash

1. HashSet，其元素是 int
    - 实现在 [/Hash/Hash.h](/lib/Hash/Hash.h)
    - 底层复用了 [/LinkedList/LinkedList.h](/lib/LinkedList/LinkedList.h)
2. HashTable，基本元素是 `void *`，因此其元素可以是 **任意类型**
    - 实现在 [/Hash/Hash.h](/lib/Hash/Hash.h)
    - 底层复用了 [/LinkedList/LinkedListP.h](/lib/LinkedList/LinkedListP.h)



## 相互转化

实现在 [/DynamicArray/convertor.h](/lib/DynamicArray/convertor.h)
1. 实现了 **LinkedList** 转 **DynamicArray**
2. 实现了 **HashSet** 转 **DynamicArray**
3. 实现了 **HashTable** 转 **DynamicArrayP**



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



