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
