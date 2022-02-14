add_library(tasks
        tasks.c)

target_link_libraries(tasks data_structures)
target_link_libraries(tasks algorithms)