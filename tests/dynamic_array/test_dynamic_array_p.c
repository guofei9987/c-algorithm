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
    DynamicArrayP *dynamic_array = DynamicArrayP_Init(2);

    Person people[] = {
        {"a", 1},
        {"b", 2},
        {"c", 3},
        {"d", 4},
        {"e", 5},
    };

    for (int i = 0; i < (int) (sizeof(people) / sizeof(Person)); i++) {
        DynamicArrayP_PushTail(dynamic_array, &people[i]);
    }

    assert(((Person *) DynamicArrayP_GetByIdx(dynamic_array, 4))->age == 5);

    Person inserted = {"f", 9};
    DynamicArrayP_Push(dynamic_array, 2, &inserted);
    assert(((Person *) DynamicArrayP_GetByIdx(dynamic_array, 2))->age == 9);
    assert(dynamic_array->size == 6);

    DynamicArrayP_Pop(dynamic_array, 3);
    assert(((Person *) DynamicArrayP_GetByIdx(dynamic_array, 3))->age == 4);

    DynamicArrayP_PopTail(dynamic_array);
    assert(dynamic_array->size == 4);

    assert(DynamicArrayP_Find(dynamic_array, &people[1], compare_person) == 1);

    Person same_value = {"b", 2};
    assert(DynamicArrayP_Find(dynamic_array, &same_value, compare_person) == 1);

    assert(((Person *) DynamicArrayP_GetByIdx(dynamic_array, 2))->age == 9);

    DynamicArrayP_SetByIdx(dynamic_array, 2, &people[4]);
    assert(((Person *) DynamicArrayP_GetByIdx(dynamic_array, 2))->age == 5);

    DynamicArrayP_Print(dynamic_array, print_person);
    DynamicArrayP_Free(dynamic_array);
}

int main(void) {
    test_dynamic_array_p_operations();
    return 0;
}
