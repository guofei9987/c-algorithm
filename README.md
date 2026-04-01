
# c-algorithm

用 C 实现常见的数据结构。

## 当前改造进度

项目正在逐步从旧的 `lib/` 结构迁移到更标准的库目录结构。

第一步已经完成：

1. 建立了 `src/`
2. 建立了 `include/`
3. 将 `DynamicArray` 的实现迁移到了 `src/dynamic_array/dynamic_array.c`
4. 将 `DynamicArray` 的公开头文件放到了 `include/c_algorithm/dynamic_array/dynamic_array.h`
5. 建立了对应测试 `tests/test_dynamic_array.c`
6. 将 `DynamicArrayP` 迁移到了 `src/dynamic_array/dynamic_array_p.c` 和 `include/c_algorithm/dynamic_array/dynamic_array_p.h`
7. 将 `DynamicArrayP` 的命名统一到了 `c_algo_dynamic_array_p_*`
8. 将 `RecurrentArray` 迁移到了 `src/dynamic_array/recurrent_array.c` 和 `include/c_algorithm/dynamic_array/recurrent_array.h`
9. 将 `RecurrentArray` 的命名统一到了 `c_algo_recurrent_array_*`

## 如何构建和运行测试

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

如果你只想运行 `DynamicArray` 测试可执行文件，也可以直接执行：

```bash
./build/tests/dynamic_array_test
```

## 如何使用这个库

构建并安装

```bash
cmake -S . -B build
cmake --build build
cmake --install build
```

使用
```c
#include "c_algorithm/dynamic_array/dynamic_array.h"

int main(void) {
    c_algo_dynamic_array *arr = c_algo_dynamic_array_init(2);
    c_algo_dynamic_array_push(arr, 10);
    c_algo_dynamic_array_push(arr, 20);
    c_algo_dynamic_array_push(arr, 30);

    c_algo_dynamic_array_print(arr);
    c_algo_dynamic_array_free(arr);
    return 0;
}
```

# 算法
## 静态数组

略

## 动态数组

1. 动态数组，元素是int类型
    - 实现在 [/DynamicArray/int](/lib/DynamicArray/int)
2. 动态数组，NodeData 是 `void *`，因此动态数组的元素可以是 **任意类型**
    - 实现在 [/DynamicArray/pointer](/lib/DynamicArray/pointer)
    - 可以自定义一个关于 **打印** 的函数指针，从而调用 `c_algo_dynamic_array_p_print` 来打印整个动态数组
    - 可以自定义一个关于 **比较** 的函数指针，从而调用 `c_algo_dynamic_array_p_find` 来查找符合某种条件的元素
    - 末尾添加/删除的复杂度 为 **O(1)**
    - 可以用来实现高效的 **Stack**
3. 循环数组，元素是 int 类型
    - 新结构实现在 `src/dynamic_array/recurrent_array.c`
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
