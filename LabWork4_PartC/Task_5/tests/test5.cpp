#include <gtest/gtest.h>
#include "func.h"


// Тест для функции IfValid (проверка увеличения счетчиков вокруг бомб)
TEST(MinesweeperTest, IfValidIncrementsCounter) {
    int M = 3, N = 3;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N];
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    // Устанавливаем бомбу в центре
    arr[1][1] = 9;

    // Проверяем соседей
    IfValid(arr, 0, 0, M, N);
    IfValid(arr, 1, 0, M, N);
    IfValid(arr, 2, 2, M, N);

    EXPECT_EQ(arr[0][0], 1);
    EXPECT_EQ(arr[1][0], 1);
    EXPECT_EQ(arr[2][2], 1);

    // Очистка
    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}

// Тест для проверки углового случая (левый верхний угол)
TEST(MinesweeperTest, TopLeftCorner) {
    int M = 3, N = 3;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N]{0};
    }

    arr[0][0] = 9; // Бомба в углу

    IfValid(arr, 0, 1, M, N);
    IfValid(arr, 1, 0, M, N);
    IfValid(arr, 1, 1, M, N);

    EXPECT_EQ(arr[0][1], 1);
    EXPECT_EQ(arr[1][0], 1);
    EXPECT_EQ(arr[1][1], 1);

    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}

// Тест для проверки граничных условий
TEST(MinesweeperTest, OutOfBounds) {
    int M = 2, N = 2;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N]{0};
    }

    // Вызов за границами массива
    IfValid(arr, -1, 0, M, N);
    IfValid(arr, 0, -1, M, N);
    IfValid(arr, 2, 0, M, N);
    IfValid(arr, 0, 2, M, N);

    // Массив не должен измениться
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            EXPECT_EQ(arr[i][j], 0);
        }
    }

    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}

// Тест для проверки инициализации поля
TEST(MinesweeperTest, FieldInitialization) {
    int M = 2, N = 2;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N];
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    // Проверяем инициализацию нулями
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            EXPECT_EQ(arr[i][j], 0);
        }
    }

    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}

// Тест для проверки поведения с уже установленной бомбой
TEST(MinesweeperTest, BombNotOverwritten) {
    int M = 3, N = 3;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N]{0};
    }

    arr[1][1] = 9; // Устанавливаем бомбу

    // Пытаемся установить еще одну бомбу в ту же ячейку
    IfValid(arr, 1, 1, M, N);

    EXPECT_EQ(arr[1][1], 9); // Должно остаться 9

    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}

// Тест полного сценария с одной бомбой
TEST(MinesweeperTest, SingleBombScenario) {
    int M = 3, N = 3;
    int** arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N]{0};
    }

    // Бомба в центре
    arr[1][1] = 9;

    // Обновляем всех соседей
    IfValid(arr, 0, 0, M, N);
    IfValid(arr, 0, 1, M, N);
    IfValid(arr, 0, 2, M, N);
    IfValid(arr, 1, 0, M, N);
    IfValid(arr, 1, 2, M, N);
    IfValid(arr, 2, 0, M, N);
    IfValid(arr, 2, 1, M, N);
    IfValid(arr, 2, 2, M, N);

    // Проверяем счетчики
    EXPECT_EQ(arr[0][0], 1);
    EXPECT_EQ(arr[0][1], 1);
    EXPECT_EQ(arr[0][2], 1);
    EXPECT_EQ(arr[1][0], 1);
    EXPECT_EQ(arr[1][2], 1);
    EXPECT_EQ(arr[2][0], 1);
    EXPECT_EQ(arr[2][1], 1);
    EXPECT_EQ(arr[2][2], 1);
    EXPECT_EQ(arr[1][1], 9); // Бомба нетронута

    for (int i = 0; i < M; i++) delete[] arr[i];
    delete[] arr;
}