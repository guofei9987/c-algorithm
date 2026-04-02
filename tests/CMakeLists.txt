add_executable(dynamic_array_test
    dynamic_array/test_dynamic_array.c
)

target_link_libraries(dynamic_array_test PRIVATE c_algorithm)

add_test(NAME dynamic_array_test COMMAND dynamic_array_test)

add_executable(dynamic_array_p_test
    dynamic_array/test_dynamic_array_p.c
)

target_link_libraries(dynamic_array_p_test PRIVATE c_algorithm)

add_test(NAME dynamic_array_p_test COMMAND dynamic_array_p_test)

add_executable(recurrent_array_test
    dynamic_array/test_recurrent_array.c
)

target_link_libraries(recurrent_array_test PRIVATE c_algorithm)

add_test(NAME recurrent_array_test COMMAND recurrent_array_test)

add_executable(linked_list_test
    linked_list/test_linked_list.c
)

target_link_libraries(linked_list_test PRIVATE c_algorithm)

add_test(NAME linked_list_test COMMAND linked_list_test)

add_executable(linked_list_p_test
    linked_list/test_linked_list_p.c
)

target_link_libraries(linked_list_p_test PRIVATE c_algorithm)

add_test(NAME linked_list_p_test COMMAND linked_list_p_test)

add_executable(linked_list_new_test
    linked_list/test_linked_list_new.c
)

target_link_libraries(linked_list_new_test PRIVATE c_algorithm)

add_test(NAME linked_list_new_test COMMAND linked_list_new_test)
