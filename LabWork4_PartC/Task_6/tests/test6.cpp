#include <gtest/gtest.h>
#include "func.h"

TEST(MagicSquareTest, CreateMatrix) {
    uint32_t** matrix = createSquareMatrix(3);
    ASSERT_NE(matrix, nullptr);

    // Проверяем, что матрица инициализирована нулями
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(matrix[i][j], 0);
        }
    }

    freeSquareMatrix(matrix, 3);
}

TEST(MagicSquareTest, OddOrder3) {
    uint32_t** square = generateOddMagicSquare(3);
    ASSERT_NE(square, nullptr);

    // Проверяем известный магический квадрат 3x3
    EXPECT_EQ(square[0][0], 8);
    EXPECT_EQ(square[0][1], 1);
    EXPECT_EQ(square[0][2], 6);
    EXPECT_EQ(square[1][0], 3);
    EXPECT_EQ(square[1][1], 5);
    EXPECT_EQ(square[1][2], 7);
    EXPECT_EQ(square[2][0], 4);
    EXPECT_EQ(square[2][1], 9);
    EXPECT_EQ(square[2][2], 2);

    EXPECT_TRUE(isMagicSquare(square, 3));
    freeSquareMatrix(square, 3);
}

TEST(MagicSquareTest, DoublyEvenOrder4) {
    uint32_t** square = generateDoublyEvenMagicSquare(4);
    ASSERT_NE(square, nullptr);

    // Проверяем сумму
    EXPECT_TRUE(isMagicSquare(square, 4));

    freeSquareMatrix(square, 4);
}