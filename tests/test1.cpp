#include <func.h>
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// функция для тестирования с перенаправлением ввода/вывода
void testCheckInputChoice(const std::string& input, int& result_choice, std::string& output) {
    // Сохраняем оригинальные буферы
    std::streambuf* original_cin = std::cin.rdbuf();
    std::streambuf* original_cout = std::cout.rdbuf();

    // Перенаправляем ввод
    std::stringstream input_stream(input);
    std::cin.rdbuf(input_stream.rdbuf());

    // Перенаправляем вывод
    std::stringstream output_stream;
    std::cout.rdbuf(output_stream.rdbuf());

    // Вызываем тестируемую функцию
    checkInputChoice(result_choice);
    output = output_stream.str();

    // Восстанавливаем буферы
    std::cin.rdbuf(original_cin);
    std::cout.rdbuf(original_cout);
}

// Тесты
TEST(CheckInputChoiceSimpleTest, Input1) {
    int choice;
    std::string output;
    testCheckInputChoice("1\n", choice, output);
    EXPECT_EQ(choice, 1);
}

TEST(CheckInputChoiceSimpleTest, Input3) {
    int choice;
    std::string output;
    testCheckInputChoice("3\n", choice, output);
    EXPECT_EQ(choice, 3);
}

TEST(CheckInputChoiceSimpleTest, Input0Then1) {
    int choice;
    std::string output;
    testCheckInputChoice("0\n1\n", choice, output);
    EXPECT_EQ(choice, 1);
    EXPECT_NE(output.find("Incorrect input. Enter 1, 2, or 3."), std::string::npos);
}

TEST(CheckInputChoiceSimpleTest, Input4Then3) {
    int choice;
    std::string output;
    testCheckInputChoice("4\n3\n", choice, output);
    EXPECT_EQ(choice, 3);
    EXPECT_NE(output.find("Incorrect input. Enter 1, 2, or 3."), std::string::npos);
}

TEST(CheckInputChoiceSimpleTest, InputLettersThen1) {
    int choice;
    std::string output;
    testCheckInputChoice("abc\n1\n", choice, output);
    EXPECT_EQ(choice, 1);
    EXPECT_NE(output.find("Incorrect input. Enter a single number."), std::string::npos);
}