#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int*** create3DArray(uint32_t n) {
    int*** arr = (int***)malloc(n * sizeof(int**));
    if (arr == NULL) {
        return NULL;
    }

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = (int**)malloc(n * sizeof(int*));
        if (arr[i] == NULL) {
            // Освобождаем уже выделенную память в случае ошибки
            for (uint32_t j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }

        for (uint32_t j = 0; j < n; j++) {
            arr[i][j] = (int*)malloc(n * sizeof(int));
            if (arr[i][j] == NULL) {
                // Освобождаем уже выделенную память в случае ошибки
                for (uint32_t k = 0; k < j; k++) {
                    free(arr[i][k]);
                }
                free(arr[i]);
                for (uint32_t k = 0; k < i; k++) {
                    for (uint32_t l = 0; l < n; l++) {
                        free(arr[k][l]);
                    }
                    free(arr[k]);
                }
                free(arr);
                return NULL;
            }
        }
    }
    return arr;
}

void free3DArray(int ***arr, uint32_t n) {
    if (arr == NULL) return;

    for (uint32_t i = 0; i < n; i++) {
        if (arr[i] != NULL) {
            for (uint32_t j = 0; j < n; j++) {
                free(arr[i][j]);
            }
            free(arr[i]);
        }
    }
    free(arr);
}

long long findMaxSum(long long* sums) {
    long long max_sum = sums[0];
    if (sums[1] > max_sum) max_sum = sums[1];
    if (sums[2] > max_sum) max_sum = sums[2];
    if (sums[3] > max_sum) max_sum = sums[3];
    return max_sum;
}

void calculateDiagonals(int*** arr, uint32_t n, long long* sums) {
    sums[0] = 0;
    sums[1] = 0;
    sums[2] = 0;
    sums[3] = 0;

    for (uint32_t i = 0; i < n; i++) {
        sums[0] += arr[i][i][i];                          // (i,i,i)
        sums[1] += arr[i][i][n-1-i];                     // (i,i,n-1-i)
        sums[2] += arr[i][n-1-i][i];                     // (i,n-1-i,i)
        sums[3] += arr[i][n-1-i][n-1-i];                // (i,n-1-i,n-1-i)
    }
}

void printFull3DArray(int ***arr, uint32_t n) {
    for (uint32_t layer = 0; layer < n; layer++) {
        printf("Level %u:\n", layer);

        for (uint32_t row = 0; row < n; row++) {
            for (uint32_t col = 0; col < n; col++) {
                printf("%3d ", arr[layer][row][col]);
            }
            printf("\n");
        }
        printf("\n");
    }
}