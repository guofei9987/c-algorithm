#include "c_algorithm/DynamicArray.h"

DynamicArray *DynamicArray_Init(int capacity) {
    DynamicArray *arr = (DynamicArray *) malloc(sizeof(DynamicArray));
    arr->capacity = capacity;
    arr->size = 0;
    arr->pAddr = (int *) malloc(sizeof(int) * arr->capacity);
    return arr;
}

void DynamicArray_Reloc(DynamicArray *arr, int new_capacity) {
    int *newPArr = (int *) malloc(sizeof(int) * new_capacity);
    memcpy(newPArr, arr->pAddr, sizeof(int) * arr->size);
    free(arr->pAddr);
    arr->pAddr = newPArr;
    arr->capacity = new_capacity;
}

void DynamicArray_LoseWeight(DynamicArray *arr) {
    if (arr->size == 0) {
        DynamicArray_Reloc(arr, 1);
    } else {
        DynamicArray_Reloc(arr, arr->size);
    }
}

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

void DynamicArray_Push(DynamicArray *arr, int val) {
    if (arr->size == arr->capacity) {
        DynamicArray_Reloc(arr, arr->capacity * 2);
    }
    arr->pAddr[arr->size] = val;
    arr->size++;
}

int DynamicArray_Pop_Tail(DynamicArray *arr) {
    return arr->pAddr[(arr->size--) - 1];
}

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

int DynamicArray_Get(DynamicArray *arr, int idx) {
    return arr->pAddr[idx];
}

void DynamicArray_Set(DynamicArray *arr, int idx, int val) {
    arr->pAddr[idx] = val;
}

int DynamicArray_Find(DynamicArray *arr, int val) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == val) {
            return i;
        }
    }
    return -1;
}

void DynamicArray_Free(DynamicArray *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}
