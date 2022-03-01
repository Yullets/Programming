add_library(tasks
        tasks.c
        tests.c
        stringTasks.c stringTests.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)
target_link_libraries(tasks string_)