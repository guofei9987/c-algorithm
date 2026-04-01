include(GNUInstallDirs)

add_library(c_algorithm STATIC
    DynamicArray.c
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

install(FILES ${PROJECT_SOURCE_DIR}/include/c_algorithm/DynamicArray.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/c_algorithm
)
