cmake_minimum_required(VERSION 3.30)
project(LR4)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

# Task 1 - основная программа
add_executable(Task_1
        Task_1/src/Task_1.cpp
        Task_1/src/func.cpp
)

# Task 1 - тесты
add_executable(Task_1_Tests
        Task_1/tests/test1.cpp
        Task_1/src/func.cpp
)

# Подключаем заголовки для Task 1
target_include_directories(Task_1 PRIVATE Task_1/include)
target_include_directories(Task_1_Tests PRIVATE Task_1/include)
target_link_libraries(Task_1_Tests gtest gtest_main)

# Task 3 - основная программа
add_executable(Task_3
        Task_3/src/Task_3.cpp
        Task_3/src/func3.cpp
)

# Task 3 - тесты
add_executable(Task_3_Tests
        Task_3/tests/test3.cpp
        Task_3/src/func3.cpp
)

# Подключаем заголовки для Task 3
target_include_directories(Task_3 PRIVATE Task_3/include)
target_include_directories(Task_3_Tests PRIVATE Task_3/include)
target_link_libraries(Task_3_Tests gtest gtest_main)