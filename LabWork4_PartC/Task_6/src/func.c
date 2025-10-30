// func.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "func.h"

uint32_t** createSquareMatrix(uint32_t n) {
    uint32_t** arr = (uint32_t**)malloc(n * sizeof(uint32_t*));
    if (arr == NULL) return NULL;

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = (uint32_t*)calloc(n, sizeof(uint32_t));
        if (arr[i] == NULL) {
            for (uint32_t j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }
    return arr;
}

void freeSquareMatrix(uint32_t** matrix, uint32_t n) {
    if (matrix == NULL) return;

    for (uint32_t i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

uint32_t** generateOddMagicSquare(uint32_t n) {
    uint32_t** arr = createSquareMatrix(n);
    if (arr == NULL) return NULL;

    uint32_t i = 0;
    uint32_t j = (n - 1) / 2;

    for (uint32_t num = 1; num <= n * n; num++) {
        uint32_t prevI = i;
        uint32_t prevJ = j;
        arr[i][j] = num;

        i = (i == 0) ? n - 1 : i - 1;
        j = (j == n - 1) ? 0 : j + 1;

        if (arr[i][j] != 0) {
            i = (prevI + 1) % n;
            j = prevJ;
        }
    }

    return arr;
}

uint32_t** generateDoublyEvenMagicSquare(uint32_t n) {
    uint32_t** arr = createSquareMatrix(n);
    if (arr == NULL) return NULL;

    uint32_t count = 1;
    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < n; j++) {
            arr[i][j] = count++;
        }
    }

    uint32_t k = n / 4;
    uint32_t m = n / 2;
    const uint32_t C = n * n + 1;

    for (uint32_t i = 0; i < k; i++) {
        for (uint32_t j = k; j < k + m; j++) {
            arr[i][j] = C - arr[i][j];
        }
    }

    for (uint32_t i = k; i < k + m; i++) {
        for (uint32_t j = 0; j < k; j++) {
            arr[i][j] = C - arr[i][j];
        }
    }

    for (uint32_t i = k; i < k + m; i++) {
        for (uint32_t j = k + m; j < n; j++) {
            arr[i][j] = C - arr[i][j];
        }
    }

    for (uint32_t i = k + m; i < n; i++) {
        for (uint32_t j = k; j < k + m; j++) {
            arr[i][j] = C - arr[i][j];
        }
    }

    return arr;
}

uint32_t** generateSinglyEvenMagicSquare(uint32_t n) {
    uint32_t** arr = createSquareMatrix(n);
    if (arr == NULL) return NULL;

    uint32_t m = n / 2;

    // Создаем временный массив для подквадрата
    uint32_t** temp = createSquareMatrix(m);
    if (temp == NULL) {
        freeSquareMatrix(arr, n);
        return NULL;
    }

    // Заполняем подквадрат методом для нечетного порядка
    uint32_t i_temp = 0;
    uint32_t j_temp = (m - 1) / 2;
    for (uint32_t num = 1; num <= m * m; num++) {
        uint32_t prevI = i_temp;
        uint32_t prevJ = j_temp;
        temp[i_temp][j_temp] = num;

        i_temp = (i_temp == 0) ? m - 1 : i_temp - 1;
        j_temp = (j_temp == m - 1) ? 0 : j_temp + 1;
        if (temp[i_temp][j_temp] != 0) {
            i_temp = (prevI + 1) % m;
            j_temp = prevJ;
        }
    }

    // Заполняем основные подквадраты
    for (uint32_t i = 0; i < m; i++) {
        for (uint32_t j = 0; j < m; j++) {
            arr[i][j] = temp[i][j];                       // A
            arr[i][j + m] = temp[i][j] + 2 * m * m;       // B
            arr[i + m][j] = temp[i][j] + 3 * m * m;       // C
            arr[i + m][j + m] = temp[i][j] + m * m;       // D
        }
    }

    // Перестановки
    uint32_t k = (n - 2) / 4;

    // Столбцы в A <-> D
    for (uint32_t i = 0; i < m; i++) {
        for (uint32_t j = 0; j < k; j++) {
            uint32_t temp_val = arr[i][j];
            arr[i][j] = arr[i + m][j];
            arr[i + m][j] = temp_val;
        }
    }

    // Столбцы в B <-> C
    for (uint32_t i = 0; i < m; i++) {
        for (uint32_t j = n - k + 1; j < n; j++) {
            uint32_t temp_val = arr[i][j];
            arr[i][j] = arr[i + m][j];
            arr[i + m][j] = temp_val;
        }
    }

    // Центральные элементы
    uint32_t temp_val = arr[k][0];
    arr[k][0] = arr[k + m][0];
    arr[k + m][0] = temp_val;

    temp_val = arr[k][k];
    arr[k][k] = arr[k + m][k];
    arr[k + m][k] = temp_val;

    freeSquareMatrix(temp, m);
    return arr;
}

int isMagicSquare(uint32_t** square, uint32_t n) {
    if (square == NULL) return 0;

    uint32_t magicSum = n * (n * n + 1) / 2;

    // Проверка строк
    for (uint32_t i = 0; i < n; i++) {
        uint32_t rowSum = 0;
        for (uint32_t j = 0; j < n; j++) {
            rowSum += square[i][j];
        }
        if (rowSum != magicSum) return 0;
    }

    // Проверка столбцов
    for (uint32_t j = 0; j < n; j++) {
        uint32_t colSum = 0;
        for (uint32_t i = 0; i < n; i++) {
            colSum += square[i][j];
        }
        if (colSum != magicSum) return 0;
    }

    // Проверка главной диагонали
    uint32_t diag1Sum = 0;
    for (uint32_t i = 0; i < n; i++) {
        diag1Sum += square[i][i];
    }
    if (diag1Sum != magicSum) return 0;

    // Проверка побочной диагонали
    uint32_t diag2Sum = 0;
    for (uint32_t i = 0; i < n; i++) {
        diag2Sum += square[i][n - 1 - i];
    }
    if (diag2Sum != magicSum) return 0;

    return 1;
}
