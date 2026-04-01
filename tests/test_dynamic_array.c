#include <assert.h>

#include "c_algorithm/dynamic_array/dynamic_array.h"

static void test_push_and_expand(void) {
    c_algo_dynamic_array *arr = c_algo_dynamic_array_init(2);

    c_algo_dynamic_array_push(arr, 10);
    c_algo_dynamic_array_push(arr, 20);
    c_algo_dynamic_array_push(arr, 30);

    assert(arr->size == 3);
    assert(arr->capacity == 4);
    assert(c_algo_dynamic_array_get(arr, 0) == 10);
    assert(c_algo_dynamic_array_get(arr, 2) == 30);

    c_algo_dynamic_array_free(arr);
}

static void test_pop_tail(void) {
    c_algo_dynamic_array *arr = c_algo_dynamic_array_init(2);

    c_algo_dynamic_array_push(arr, 10);
    c_algo_dynamic_array_push(arr, 20);
    c_algo_dynamic_array_push(arr, 30);

    assert(c_algo_dynamic_array_pop_tail(arr) == 30);
    assert(arr->size == 2);
    assert(c_algo_dynamic_array_get(arr, 0) == 10);
    assert(c_algo_dynamic_array_get(arr, 1) == 20);

    assert(c_algo_dynamic_array_pop_tail(arr) == 20);
    assert(arr->size == 1);
    assert(c_algo_dynamic_array_pop_tail(arr) == 10);
    assert(arr->size == 0);

    c_algo_dynamic_array_free(arr);
}

static void test_pop_find_set_and_shrink(void) {
    c_algo_dynamic_array *arr = c_algo_dynamic_array_init(4);

    for (int i = 0; i < 4; i++) {
        c_algo_dynamic_array_push(arr, i);
    }

    c_algo_dynamic_array_pop(arr, 1);
    assert(arr->size == 3);
    assert(c_algo_dynamic_array_find(arr, 2) == 1);

    c_algo_dynamic_array_set(arr, 0, 42);
    assert(c_algo_dynamic_array_get(arr, 0) == 42);

    c_algo_dynamic_array_lose_weight(arr);
    assert(arr->capacity == arr->size);

    c_algo_dynamic_array_free(arr);
}

int main(void) {
    test_push_and_expand();
    test_pop_tail();
    test_pop_find_set_and_shrink();
    return 0;
}
