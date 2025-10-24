#include "func3.h"

bool checkIsMatrix(int N, int** arr){
    int* sumAllHorizontalLines = new int[N];
    for (int i = 0; i < N; i++){
        int sumLine = 0;
        for (int j = 0; j < N; j++){
            sumLine += arr[i][j];
        }
        sumAllHorizontalLines[i] = sumLine;
    }

    int MAINSUM = sumAllHorizontalLines[0];
    for (int i = 0; i < N; i++){
        if (MAINSUM != sumAllHorizontalLines[i]){
            delete[] sumAllHorizontalLines;
            return false;
        }
    }
    delete[] sumAllHorizontalLines;

    int* sumAllVerticalLines = new int[N];
    int sumDiagonal1 = 0;
    int sumDiagonal2 = 0;
    for (int j = 0; j < N; j++){
        int sumLine = 0;
        for (int i = 0; i < N; i++){
            sumLine += arr[i][j];
            if (i == j) {
                sumDiagonal1 += arr[i][j];
            }
            if ((i + j) == (N - 1)) {
                sumDiagonal2 += arr[i][j];
            }
        }
        sumAllVerticalLines[j] = sumLine;
        if (sumLine != MAINSUM){
            delete[] sumAllVerticalLines;
            return false;
        }
    }
    if (sumDiagonal1 != MAINSUM || sumDiagonal2 != MAINSUM){
        delete[] sumAllVerticalLines;
        return false;
    }
    delete[] sumAllVerticalLines;
    return true;
}