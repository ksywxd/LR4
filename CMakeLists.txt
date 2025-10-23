cmake_minimum_required(VERSION 3.30)
project(LR4)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

include_directories(Task_1/include)

add_executable(LR4
        Task_1/Task_1.cpp
        #Task_1/include/func.h
        Task_1/func.cpp
        )

add_executable(tests
        #Task_1/include/func.h
        Task_1/func.cpp
        Task_1/tests/test1.cpp)

target_link_libraries(tests gtest gtest_main)