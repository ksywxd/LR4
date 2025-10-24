#include "func.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(InputTest, Choice1) {
    // Сохраняем оригинальные буферы
    std::streambuf* original_cin = std::cin.rdbuf();
    std::streambuf* original_cout = std::cout.rdbuf();

    // Перенаправляем ввод
    std::stringstream test_input("1\n");
    std::cin.rdbuf(test_input.rdbuf());

    // Перенаправляем вывод (чтобы не засорять консоль)
    std::stringstream test_output;
    std::cout.rdbuf(test_output.rdbuf());

    // Тестируем
    int choice = 0;
    checkInputChoice(choice);

    // Проверяем
    EXPECT_EQ(choice, 1);

    // Восстанавливаем буферы
    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);
}

TEST(InputTest, Choice2) {
    std::streambuf* original_cin = std::cin.rdbuf();
    std::streambuf* original_cout = std::cout.rdbuf();

    std::stringstream test_input("2\n");
    std::cin.rdbuf(test_input.rdbuf());

    std::stringstream test_output;
    std::cout.rdbuf(test_output.rdbuf());

    int choice = 0;
    checkInputChoice(choice);

    EXPECT_EQ(choice, 2);

    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);
}