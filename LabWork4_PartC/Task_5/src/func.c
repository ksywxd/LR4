#include "func.h"

void IfValid(int** arr, int i, int j, int M, int N) {
    if (i >= 0 && i < M && j >= 0 && j < N) {
        if (arr[i][j] != 9) {
            arr[i][j]++;
        }
    }
}