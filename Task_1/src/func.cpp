#include "func.h"

void splitArray(const double* inputArray, int size,
                double*& negativeArray, int& negativeCount,
                double*& otherArray, int& otherCount) {

    negativeCount = 0;
    otherCount = 0;
    for (int i = 0; i < size; i++) {
        if (inputArray[i] < 0) {
            negativeCount++;
        } else {
            otherCount++;
        }
    }

    negativeArray = new double[negativeCount];
    otherArray = new double[otherCount];

    int negIndex = 0, otherIndex = 0;
    for (int i = 0; i < size; i++) {
        if (inputArray[i] < 0) {
            negativeArray[negIndex++] = inputArray[i];
        } else {
            otherArray[otherIndex++] = inputArray[i];
        }
    }
}