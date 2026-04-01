#include <assert.h>

#include "RecurrentArray.h"

static void test_rec_array_queue_behavior(void) {
    Rec_Array *rec_array = RecArray_Init(4);

    assert(RecArray_IsEmpty(rec_array));

    RecArray_Push(rec_array, 1);
    RecArray_Push(rec_array, 2);
    RecArray_Push(rec_array, 3);

    assert(!RecArray_IsEmpty(rec_array));
    assert(RecArray_GetFront(rec_array) == 1);
    assert(RecArray_GetTail(rec_array) == 3);
    assert(Pop_Front_Rec_Array(rec_array) == 1);
    assert(Pop_Front_Rec_Array(rec_array) == 2);

    RecArray_Push(rec_array, 4);
    RecArray_Push(rec_array, 5);

    assert(RecArray_GetFront(rec_array) == 3);
    assert(RecArray_GetTail(rec_array) == 5);
    assert(RecArray_PopTail(rec_array) == 5);

    RecArray_DelFront(rec_array);
    assert(RecArray_GetFront(rec_array) == 4);

    RecArray_Free(rec_array);
}

int main(void) {
    test_rec_array_queue_behavior();
    return 0;
}
