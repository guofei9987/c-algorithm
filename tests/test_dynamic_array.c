#include <assert.h>

#include "c_algorithm/DynamicArray.h"

static void test_push_and_expand(void) {
    DynamicArray *arr = DynamicArray_Init(2);

    DynamicArray_Push(arr, 10);
    DynamicArray_Push(arr, 20);
    DynamicArray_Push(arr, 30);

    assert(arr->size == 3);
    assert(arr->capacity == 4);
    assert(DynamicArray_Get(arr, 0) == 10);
    assert(DynamicArray_Get(arr, 2) == 30);

    DynamicArray_Free(arr);
}

static void test_pop_find_set_and_shrink(void) {
    DynamicArray *arr = DynamicArray_Init(4);

    for (int i = 0; i < 4; i++) {
        DynamicArray_Push(arr, i);
    }

    DynamicArray_Pop(arr, 1);
    assert(arr->size == 3);
    assert(DynamicArray_Find(arr, 2) == 1);

    DynamicArray_Set(arr, 0, 42);
    assert(DynamicArray_Get(arr, 0) == 42);

    DynamicArray_LoseWeight(arr);
    assert(arr->capacity == arr->size);

    DynamicArray_Free(arr);
}

int main(void) {
    test_push_and_expand();
    test_pop_find_set_and_shrink();
    return 0;
}
