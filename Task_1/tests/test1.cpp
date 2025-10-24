#include "func.h"
#include <gtest/gtest.h>

TEST(SplitArrayTest, OnlyNegativeNumbers) {
    double input[] = {-1.0, -2.2, -3.0};
    double* negativeArray = nullptr;
    double* otherArray = nullptr;
    int negativeCount, otherCount;

    splitArray(input, 3, negativeArray, negativeCount, otherArray, otherCount);

    EXPECT_EQ(negativeCount, 3);
    EXPECT_EQ(otherCount, 0);

    delete[] negativeArray;
    delete[] otherArray;
}

TEST(SplitArrayTest, OnlyPositiveAndZero) {
    double input[] = {1.0, 0.0, 2.5, 3.0};
    double* negativeArray = nullptr;
    double* otherArray = nullptr;
    int negativeCount, otherCount;

    splitArray(input, 4, negativeArray, negativeCount, otherArray, otherCount);

    EXPECT_EQ(negativeCount, 0);
    EXPECT_EQ(otherCount, 4);

    delete[] negativeArray;
    delete[] otherArray;
}

TEST(SplitArrayTest, MixedNumbers) {
    double input[] = {1.0, -2.0, 0, -4.5, 3.0};
    double* negativeArray = nullptr;
    double* otherArray = nullptr;
    int negativeCount, otherCount;

    splitArray(input, 5, negativeArray, negativeCount, otherArray, otherCount);

    // Проверяем количества
    EXPECT_EQ(negativeCount, 2);
    EXPECT_EQ(otherCount, 3);

    delete[] negativeArray;
    delete[] otherArray;
}