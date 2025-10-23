#include <gtest/gtest.h>
#include <func3.h>

TEST(MatrixTest, OneElement) {
    int N = 1;
    int* row = new int[1]{5};
    int** matrix = &row;

    EXPECT_TRUE(checkIsMatrix(N, matrix));
    delete[] row;
}

TEST(MatrixTest, TwoSameElements) {
    int N = 2;
    int** matrix = new int*[2];
    matrix[0] = new int[2]{1, 1};
    matrix[1] = new int[2]{1, 1};

    EXPECT_TRUE(checkIsMatrix(N, matrix));

    delete[] matrix[0];
    delete[] matrix[1];
    delete[] matrix;
}

TEST(MatrixTest, TwoDifferentElements) {
    int N = 2;
    int** matrix = new int*[2];
    matrix[0] = new int[2]{1, 2};
    matrix[1] = new int[2]{3, 4};

    EXPECT_FALSE(checkIsMatrix(N, matrix));

    delete[] matrix[0];
    delete[] matrix[1];
    delete[] matrix;
}