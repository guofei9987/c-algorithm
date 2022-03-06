#include "DynamicArrayP.h"

//初始化
Dynamic_Array_P *Init_Dynamic_Array_P() {
    Dynamic_Array_P *arr = (Dynamic_Array_P *) malloc(sizeof(Dynamic_Array_P));
    arr->capacity = 50;
    arr->size = 0;
    arr->pAddr = (void *) malloc(sizeof(void *) * arr->capacity);
    return arr;

}


void Push_Dynamic_Array_P(Dynamic_Array_P *arr, int idx, void *data) {
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
void Push_Last_Dynamic_Array_P(Dynamic_Array_P *arr, void *data) {

    Push_Dynamic_Array_P(arr, arr->size, data);

}


//打印
void Print_Dynamic_Array_P(Dynamic_Array_P *arr, PRINT_DATA printData) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < arr->size; i++) {
//        printf("%p,", *(arr->pAddr)[i]);
        printData(arr->pAddr[i]);
    }
    printf("\n");
}

//删除一个
//TODO:被删除的内存需要释放吗？
void Pop_Dynamic_Array_P(Dynamic_Array_P *arr, int idx) {
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
void *Get_Dynamic_Array_P(Dynamic_Array_P *arr, int idx) {
    if (idx >= arr->size) {
        return NULL;
    }
    return arr->pAddr[idx];
}

//赋值
void Set_Dynamic_Array_P(Dynamic_Array_P *arr, int idx, void *data) {
    arr->pAddr[idx] = data;
}

//查找
int Find_Dynamic_Array_P(Dynamic_Array_P *arr, void *data) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->pAddr[i] == data) {
            return i;
        }
    }
    return -1;
}


//从最后删除
void Pop_Last_Dynamic_Array_P(Dynamic_Array_P *arr) {
    Pop_Dynamic_Array_P(arr, arr->size - 1);
}


//释放空间
void Free_Dynamic_Array_P(Dynamic_Array_P *arr) {
    if (arr == NULL) {
        return;
    }
    if (arr->pAddr != NULL) {
        free(arr->pAddr);
    }
    free(arr);
}