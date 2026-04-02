include(GNUInstallDirs)

add_library(c_algorithm STATIC
    dynamic_array/dynamic_array.c
    dynamic_array/dynamic_array_p.c
    dynamic_array/recurrent_array.c
    linked_list/linked_list.c
    linked_list/linked_list_p.c
    linked_list/linked_list_new.c
)

add_library(c_algorithm::c_algorithm ALIAS c_algorithm)

target_include_directories(c_algorithm
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS c_algorithm
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES ${PROJECT_SOURCE_DIR}/include/c_algorithm/dynamic_array/dynamic_array.h
    ${PROJECT_SOURCE_DIR}/include/c_algorithm/dynamic_array/dynamic_array_p.h
    ${PROJECT_SOURCE_DIR}/include/c_algorithm/dynamic_array/recurrent_array.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/c_algorithm/dynamic_array
)

install(FILES ${PROJECT_SOURCE_DIR}/include/c_algorithm/linked_list/linked_list.h
    ${PROJECT_SOURCE_DIR}/include/c_algorithm/linked_list/linked_list_p.h
    ${PROJECT_SOURCE_DIR}/include/c_algorithm/linked_list/linked_list_new.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/c_algorithm/linked_list
)
