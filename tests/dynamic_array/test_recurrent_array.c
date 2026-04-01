#include <assert.h>

#include "c_algorithm/dynamic_array/recurrent_array.h"

static void test_rec_array_queue_behavior(void) {
    c_algo_recurrent_array *rec_array = c_algo_recurrent_array_init(4);

    assert(c_algo_recurrent_array_is_empty(rec_array));

    c_algo_recurrent_array_push(rec_array, 1);
    c_algo_recurrent_array_push(rec_array, 2);
    c_algo_recurrent_array_push(rec_array, 3);

    assert(!c_algo_recurrent_array_is_empty(rec_array));
    assert(c_algo_recurrent_array_get_front(rec_array) == 1);
    assert(c_algo_recurrent_array_get_tail(rec_array) == 3);
    assert(c_algo_recurrent_array_pop_front(rec_array) == 1);
    assert(c_algo_recurrent_array_pop_front(rec_array) == 2);

    c_algo_recurrent_array_push(rec_array, 4);
    c_algo_recurrent_array_push(rec_array, 5);

    assert(c_algo_recurrent_array_get_front(rec_array) == 3);
    assert(c_algo_recurrent_array_get_tail(rec_array) == 5);
    assert(c_algo_recurrent_array_pop_tail(rec_array) == 5);

    c_algo_recurrent_array_del_front(rec_array);
    assert(c_algo_recurrent_array_get_front(rec_array) == 4);

    c_algo_recurrent_array_free(rec_array);
}

int main(void) {
    test_rec_array_queue_behavior();
    return 0;
}
