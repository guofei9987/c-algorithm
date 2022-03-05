#include "Dynamic_Array.h"

//初始化
Dynamic_Array *Init_Dynamic_Array() {
    Dynamic_Array *arr = (Dynamic_Array *) malloc(sizeof(Dynamic_Array));
    arr->capacity = 20;
    arr->size = 0;
    arr->pAddr = (int *) malloc(sizeof(int) * arr->capacity);
    return arr;
}

//插入
void Push_Dynamic_Array(Dynamic_Array *arr, int val) {
    if (arr == NULL) {
        return;
    }

    if (arr->size == arr->capacity) {
        int new_capacity = arr->capacity * 2;
        int *newPArr = (int *) malloc(sizeof(int) * arr->capacity);
        memcpy(newPArr, arr->pAddr, sizeof(int) * arr->capacity);
        free(arr->pAddr);

        arr->pAddr = newPArr;
        arr->capacity = new_capacity;
    }
    arr->pAddr[arr->size] = val;
    arr->size++;

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