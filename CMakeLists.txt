cmake_minimum_required(VERSION 3.30)
project(LR4)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

include_directories(Task_1/include)
include_directories(Task_3/include)

# Task_1
add_executable(Task_1
        Task_1/Task_1.cpp
        Task_1/func.cpp
        Task_1/include/func.h
)

# Task_2
add_executable(Task_2
        Task_2/Task_2.cpp
)

# Task_3
add_executable(Task_3
        Task_3/Task_3.cpp
        Task_3/func3.cpp
        Task_3/include/func3.h
)

# Тесты для Task_1
add_executable(test1
        tests/test1.cpp
        Task_1/func.cpp
)
target_link_libraries(test1 gtest gtest_main)

# Тесты для Task_3
add_executable(test3
        tests/test3.cpp
        Task_3/Task_3.cpp
)
target_link_libraries(test3 gtest gtest_main)