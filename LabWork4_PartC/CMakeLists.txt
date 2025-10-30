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
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Подключаем заголовки для Task 4
target_include_directories(Task_4 PRIVATE Task_4/include)
target_include_directories(Task_4_Tests PRIVATE Task_4/include)
target_link_libraries(Task_4_Tests gtest gtest_main)

# Task 5 - основная программа
add_executable(Task_5
        Task_5/src/Task_5.c
        Task_5/src/func.c
)

# Устанавливаем стандарт C для основной программы
set_target_properties(Task_5 PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
)

# Task 5 - тесты
add_executable(Task_5_Tests
        Task_5/tests/test5.cpp
        Task_5/src/func.c
)

# Устанавливаем стандарт C++ для тестов
set_target_properties(Task_5_Tests PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Подключаем заголовки для Task 5
target_include_directories(Task_5 PRIVATE Task_5/include)
target_include_directories(Task_5_Tests PRIVATE Task_5/include)
target_link_libraries(Task_5_Tests gtest gtest_main)

# Task 6 - основная программа
add_executable(Task_6
        Task_6/src/Task_6.c
        Task_6/src/func.c
)

# Устанавливаем стандарт C для основной программы
set_target_properties(Task_6 PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
)

# Task 6 - тесты
add_executable(Task_6_Tests
        Task_6/tests/test6.cpp
        Task_6/src/func.c
)

# Устанавливаем стандарт C++ для тестов
set_target_properties(Task_6_Tests PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

# Подключаем заголовки для Task 6
target_include_directories(Task_6 PRIVATE Task_6/include)
target_include_directories(Task_6_Tests PRIVATE Task_6/include)
target_link_libraries(Task_6_Tests gtest gtest_main)