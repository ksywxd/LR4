#include "func.h"
#include <algorithm>

int howManyElAbove(int M, int N) {
    int count = 0;
    if (M <= N)
        count = (M * (2 * N - M - 1)) / 2;
    else
        count = (N * (N - 1)) / 2;
    return count;
}

double findMax(int M, int N, double** arr) {
    double* arrHigher = new double[howManyElAbove(M, N)];
    int count2 = 0;
    double max = 0;
    for (int j = 0; j < N; j++){
        for (int i = 0; i < M; i++){
            if (i + j < N - 1){
                arrHigher[count2++] = arr[i][j];
                max = std::max(max, arr[i][j]);
            }
        }
    }
    delete[] arrHigher;
    return max;
}