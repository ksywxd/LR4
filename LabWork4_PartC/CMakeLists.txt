cmake_minimum_required(VERSION 3.30)
project(LabWork4_PartC)

set(CMAKE_CXX_STANDARD 20)

# Task 4 - основная программа
add_executable(Task_4
        Task_4/src/Task_4.c
        Task_4/src/func.c
)

# Устанавливаем стандарт C для основной программы
set_target_properties(Task_4 PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
)


# Task 4 - тесты
add_executable(Task_4_Tests
        Task_4/tests/test4.cpp
        Task_4/src/func.c
)

# Устанавливаем стандарт C++ для тестов
set_target_properties(Task_4_Tests PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
)

# Подключаем заголовки для Task 4
target_include_directories(Task_4 PRIVATE Task_4/include)
target_include_directories(Task_4_Tests PRIVATE Task_4/include)
target_link_libraries(Task_4_Tests gtest gtest_main)

