#include "func.h"
#include <gtest/gtest.h>

TEST(CuntTest, Square) {
    EXPECT_EQ(howManyElAbove(3,  3), 3);
    EXPECT_EQ(howManyElAbove(4, 4), 6);
}

TEST(CountElementsTest, Wide) {
    EXPECT_EQ(howManyElAbove(2, 4), 5);
    EXPECT_EQ(howManyElAbove(3, 5), 9);
}

TEST(CountElementsTest, Tall) {
    EXPECT_EQ(howManyElAbove(4, 2), 1);
    EXPECT_EQ(howManyElAbove(5, 3), 3);
}

TEST(CountElementsTest, Single) {
    EXPECT_EQ(howManyElAbove(1, 1), 0); // один элемент
}

TEST(CountElementsTest, SingleColumn) {
    EXPECT_EQ(howManyElAbove(3, 1), 0); // один столбец - нет элементов
    EXPECT_EQ(howManyElAbove(5, 1), 0);
}

TEST(CountElementsTest, SingleLine) {
    EXPECT_EQ(howManyElAbove(1, 3), 2); // одна строка - N-1 элемент
    EXPECT_EQ(howManyElAbove(1, 5), 4);
}

TEST(FindMaxTest, DoubleNumbers) {
    double** matrix = new double*[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new double[3];
    }

    matrix[0][0] = 1.5; matrix[0][1] = 2.7; matrix[0][2] = 3.1;
    matrix[1][0] = 4.2; matrix[1][1] = 9.8; matrix[1][2] = 6.4;  // 4.2 - максимум выше диагонали
    matrix[2][0] = 7.9; matrix[2][1] = 8.3; matrix[2][2] = 5.6;

    EXPECT_DOUBLE_EQ(findMax(3, 3, matrix), 4.2);

    for (int i = 0; i < 3; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//-----------------------------------------------------------------

