add_library(tasks
        tasks.c
        tests.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)