add_library(tasks
        tasks.c
        tests.c
        string_.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)