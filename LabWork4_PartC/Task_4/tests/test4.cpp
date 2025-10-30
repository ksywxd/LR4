#include <gtest/gtest.h>
#include "func.h"

TEST(DiagonalTest, FindMaxDiagonalSum) {
    long long sums1[4] = {10, 20, 15, 25};
    EXPECT_EQ(findMaxSum(sums1), 25);

    long long sums2[4] = {100, 50, 75, 25};
    EXPECT_EQ(findMaxSum(sums2), 100);

    long long sums3[4] = {5, 5, 5, 5};
    EXPECT_EQ(findMaxSum(sums3), 5);

    long long sums4[4] = {-10, -5, -20, -1};
    EXPECT_EQ(findMaxSum(sums4), -1);
}

TEST(DiagonalTest, CalculateDiagonals2x2x2) {
    int ***arr = create3DArray(2);
    ASSERT_TRUE(arr != nullptr);

    // Заполняем тестовыми значениями
    // Уровень 0
    arr[0][0][0] = 1; arr[0][0][1] = 2;
    arr[0][1][0] = 3; arr[0][1][1] = 4;

    // Уровень 1
    arr[1][0][0] = 5; arr[1][0][1] = 6;
    arr[1][1][0] = 7; arr[1][1][1] = 8;

    long long sums[4];
    calculateDiagonals(arr, 2, sums);

    // Проверяем вычисления:
    // Диагональ 1: (0,0,0)=1 + (1,1,1)=8 = 9
    // Диагональ 2: (0,0,1)=2 + (1,1,0)=7 = 9
    // Диагональ 3: (0,1,0)=3 + (1,0,1)=6 = 9
    // Диагональ 4: (0,1,1)=4 + (1,0,0)=5 = 9
    EXPECT_EQ(sums[0], 9);
    EXPECT_EQ(sums[1], 9);
    EXPECT_EQ(sums[2], 9);
    EXPECT_EQ(sums[3], 9);

    free3DArray(arr, 2);
}

TEST(DiagonalTest, CalculateDiagonals3x3x3) {
    int ***arr = create3DArray(3);
    ASSERT_TRUE(arr != nullptr);

    // Заполняем последовательными числами для простоты проверки
    int counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arr[i][j][k] = counter++;
            }
        }
    }

    long long sums[4];
    calculateDiagonals(arr, 3, sums);

    // Проверяем вычисления для известной последовательности
    // Диагональ 1: (0,0,0)=1 + (1,1,1)=14 + (2,2,2)=27 = 42
    // Диагональ 2: (0,0,2)=3 + (1,1,1)=14 + (2,2,0)=25 = 42
    // Диагональ 3: (0,2,0)=7 + (1,1,1)=14 + (2,0,2)=21 = 42
    // Диагональ 4: (0,2,2)=9 + (1,1,1)=14 + (2,0,0)=19 = 42
    EXPECT_EQ(sums[0], 42);
    EXPECT_EQ(sums[1], 42);
    EXPECT_EQ(sums[2], 42);
    EXPECT_EQ(sums[3], 42);

    free3DArray(arr, 3);
}

TEST(EdgeCaseTest, SingleElement) {
    int ***arr = create3DArray(1);
    ASSERT_TRUE(arr != nullptr);

    arr[0][0][0] = 42;

    long long sums[4];
    calculateDiagonals(arr, 1, sums);

    // Для матрицы 1x1x1 все диагонали равны одному элементу
    EXPECT_EQ(sums[0], 42);
    EXPECT_EQ(sums[1], 42);
    EXPECT_EQ(sums[2], 42);
    EXPECT_EQ(sums[3], 42);
    EXPECT_EQ(findMaxSum(sums), 42);

    free3DArray(arr, 1);
}