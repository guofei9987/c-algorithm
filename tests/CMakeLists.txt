add_executable(dynamic_array_test
    test_dynamic_array.c
)

target_link_libraries(dynamic_array_test PRIVATE c_algorithm)

add_test(NAME dynamic_array_test COMMAND dynamic_array_test)
