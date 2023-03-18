#include "DynamicArrayP.h"

//初始化
DynamicArrayP *DynamicArrayP_Init(int capacity) {
    DynamicArrayP *arr = (DynamicArrayP *) malloc(sizeof(DynamicArrayP));
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (void *) malloc(sizeof(void *) * arr->capacity);
    return arr;

}


void DynamicArrayP_Push(DynamicArrayP *arr, int idx, void *data) {
    if (arr == NULL) {
        return;
    }
    if (idx < 0 || idx > arr->size) {
        return;
    }

    void **oldPAddr = arr->pAddr;
    if (arr->size == arr->capacity) {
        int new_capacity = arr->capacity * 2;
        void **newPAddr = (void *) malloc(sizeof(void *) * arr->capacity);

        for (int i = 0; i < idx; i++) {
            newPAddr[i] = oldPAddr[i];
        }
        newPAddr[idx] = data;
        for (int i = idx; i < arr->size; i++) {
            newPAddr[i + 1] = oldPAddr[i];
        }

        free(arr->pAddr);

        arr->pAddr = newPAddr;
        arr->capacity = new_capacity;
    } else {
        for (int i = arr->size; i > idx; i--) {
            oldPAddr[i] = oldPAddr[i - 1];
        }
        oldPAddr[idx] = data;
    }

    arr->size++;
}

//插入
void DynamicArrayP_PushTail(DynamicArrayP *arr, void *data) {
    DynamicArrayP_Push(arr, arr->size, data);
}


//打印
void DynamicArrayP_Print(DynamicArrayP *arr, PRINT_DATA printData) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
        printData(arr->pAddr[i]);
    }
    printf("\n");
}

//删除一个
// 被删除的 void *data 对应的内存不在这里释放，因为它不是 DynamicArray_Init 申请的
void DynamicArrayP_Pop(DynamicArrayP *arr, int idx) {
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
void *DynamicArrayP_GetByIdx(DynamicArrayP *arr, int idx) {
    if (idx >= arr->size) {
        return NULL;
    }
    return arr->pAddr[idx];
}

//赋值
void DynamicArrayP_SetByIdx(DynamicArrayP *arr, int idx, void *data) {
    arr->pAddr[idx] = data;
}


//查找，使用传入的 COMPARE_DATA 函数指针
int DynamicArrayP_Find(DynamicArrayP *arr, void *data, COMPARE_DATA compareData) {
    for (int i = 0; i < arr->size; i++) {
        if (compareData(arr->pAddr[i], data)) {
            return i;
        }
    }
    return -1;
}



//从最后删除
void DynamicArrayP_PopTail(DynamicArrayP *arr) {
    DynamicArrayP_Pop(arr, arr->size - 1);
}


//释放空间
//不释放void * 指向的数据，因为它不是在 DynamicArrayP 中分配的内存
void DynamicArrayP_Free(DynamicArrayP *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}