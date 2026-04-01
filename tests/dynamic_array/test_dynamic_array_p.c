#include <assert.h>
#include <string.h>

#include "c_algorithm/dynamic_array/dynamic_array_p.h"

typedef struct PERSON {
    char name[64];
    int age;
} Person;

static void print_person(void *data) {
    Person *person = (Person *) data;
    printf("[name=%s,age=%d];", person->name, person->age);
}

static int compare_person(const void *left, const void *right) {
    const Person *person_left = (const Person *) left;
    const Person *person_right = (const Person *) right;
    return (person_left->age == person_right->age) &&
           (strcmp(person_left->name, person_right->name) == 0);
}

static void test_dynamic_array_p_operations(void) {
    c_algo_dynamic_array_p *dynamic_array = c_algo_dynamic_array_p_init(2);

    Person people[] = {
        {"a", 1},
        {"b", 2},
        {"c", 3},
        {"d", 4},
        {"e", 5},
    };

    for (int i = 0; i < (int) (sizeof(people) / sizeof(Person)); i++) {
        c_algo_dynamic_array_p_push_tail(dynamic_array, &people[i]);
    }

    assert(((Person *) c_algo_dynamic_array_p_get_by_idx(dynamic_array, 4))->age == 5);

    Person inserted = {"f", 9};
    c_algo_dynamic_array_p_push(dynamic_array, 2, &inserted);
    assert(((Person *) c_algo_dynamic_array_p_get_by_idx(dynamic_array, 2))->age == 9);
    assert(dynamic_array->size == 6);

    c_algo_dynamic_array_p_pop(dynamic_array, 3);
    assert(((Person *) c_algo_dynamic_array_p_get_by_idx(dynamic_array, 3))->age == 4);

    c_algo_dynamic_array_p_pop_tail(dynamic_array);
    assert(dynamic_array->size == 4);

    assert(c_algo_dynamic_array_p_find(dynamic_array, &people[1], compare_person) == 1);

    Person same_value = {"b", 2};
    assert(c_algo_dynamic_array_p_find(dynamic_array, &same_value, compare_person) == 1);

    assert(((Person *) c_algo_dynamic_array_p_get_by_idx(dynamic_array, 2))->age == 9);

    c_algo_dynamic_array_p_set_by_idx(dynamic_array, 2, &people[4]);
    assert(((Person *) c_algo_dynamic_array_p_get_by_idx(dynamic_array, 2))->age == 5);

    c_algo_dynamic_array_p_print(dynamic_array, print_person);
    c_algo_dynamic_array_p_free(dynamic_array);
}

int main(void) {
    test_dynamic_array_p_operations();
    return 0;
}
