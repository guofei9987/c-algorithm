#include "DynamicArray.h"

//初始化
Dynamic_Array *Init_Dynamic_Array(int capacity) {
    Dynamic_Array *arr = (Dynamic_Array *) malloc(sizeof(Dynamic_Array));
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (int *) malloc(sizeof(int) * arr->capacity);
    return arr;
}

//重新分配内存
void Reloc_Dynamic_Array(Dynamic_Array *arr, int new_capacity) {
//    assert(new_capacity>arr->size)
    int *newPArr = (int *) malloc(sizeof(int) * arr->capacity);
    memcpy(newPArr, arr->pAddr, sizeof(int) * arr->size);
    free(arr->pAddr);
    arr->pAddr = newPArr;
    arr->capacity = new_capacity;
}

// 减少内存消耗
void Lose_Weight_Dynamic_Array(Dynamic_Array *arr) {
    if (arr->size == 0) {
        Reloc_Dynamic_Array(arr, 1);
    } else {
        Reloc_Dynamic_Array(arr, arr->size);
    }
}


//尾部插入
void Push_Dynamic_Array(Dynamic_Array *arr, int val) {
    if (arr->size == arr->capacity) {
        Reloc_Dynamic_Array(arr, arr->capacity * 2);
    }
    arr->pAddr[arr->size] = val;
    arr->size++;
}

//删除尾部并返回它（未测试）
int Pop_Tail_Dynamic_Array(Dynamic_Array *arr) {
    return arr->pAddr[(arr->size--) - 1];
}

//打印
void Print_Dynamic_Array(Dynamic_Array *arr) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        printf("%d,", arr->pAddr[i]);
    }
    printf("\n");
}

//删除一个
void Pop_Dynamic_Array(Dynamic_Array *arr, int idx) {
    if (arr == NULL) {
        return;
    }
    if (idx < 0 || idx >= arr->size) {
        return;
    }

    arr->size--;
    for (int i = idx; i < arr->size; i++) {
        arr->pAddr[i] = arr->pAddr[i + 1];
    }

}

//取一个
int Get_Dynamic_Array(Dynamic_Array *arr, int idx) {
    return arr->pAddr[idx];
}

//赋值
void Set_Dynamic_Array(Dynamic_Array *arr, int idx, int val) {
    arr->pAddr[idx] = val;
}

//查找
int Find_Dynamic_Array(Dynamic_Array *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == val) {
            return i;
        }
    }
    return -1;
}


//释放空间
void Free_Dynamic_Array(Dynamic_Array *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}