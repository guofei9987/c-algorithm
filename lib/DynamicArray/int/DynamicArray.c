#include "DynamicArray.h"

//初始化
DynamicArray *DynamicArray_Init(int capacity) {
    DynamicArray *arr = (DynamicArray *) malloc(sizeof(DynamicArray));
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (int *) malloc(sizeof(int) * arr->capacity);
    return arr;
}

//重新分配内存
void DynamicArray_Reloc(DynamicArray *arr, int new_capacity) {
//    assert(new_capacity>arr->size)
    int *newPArr = (int *) malloc(sizeof(int) * arr->capacity);
    memcpy(newPArr, arr->pAddr, sizeof(int) * arr->size);
    free(arr->pAddr);
    arr->pAddr = newPArr;
    arr->capacity = new_capacity;
}

// 减少内存消耗
void DynamicArray_LoseWeight(DynamicArray *arr) {
    if (arr->size == 0) {
        DynamicArray_Reloc(arr, 1);
    } else {
        DynamicArray_Reloc(arr, arr->size);
    }
}


//尾部插入
void DynamicArray_Push(DynamicArray *arr, int val) {
    if (arr->size == arr->capacity) {
        DynamicArray_Reloc(arr, arr->capacity * 2);
    }
    arr->pAddr[arr->size] = val;
    arr->size++;
}

//删除尾部并返回它（未测试）
int DynamicArray_Pop_Tail(DynamicArray *arr) {
    return arr->pAddr[(arr->size--) - 1];
}

//打印
void DynamicArray_Print(DynamicArray *arr) {
    if (arr == NULL) {
        return;
    }
    printf("<Dynamic Array>: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d,", arr->pAddr[i]);
    }
    printf("\n");
}

//删除最后一个
void DynamicArray_Pop(DynamicArray *arr, int idx) {
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
int DynamicArray_Get(DynamicArray *arr, int idx) {
    return arr->pAddr[idx];
}

//赋值
void DynamicArray_Set(DynamicArray *arr, int idx, int val) {
    arr->pAddr[idx] = val;
}

//查找
int DynamicArray_Find(DynamicArray *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == val) {
            return i;
        }
    }
    return -1;
}


//释放空间
void DynamicArray_Free(DynamicArray *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}