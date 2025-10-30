#ifndef LR4_FUNC_H
#define LR4_FUNC_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

long long findMaxSum(long long* sums);
void free3DArray(int*** arr, uint32_t n);
int*** create3DArray(uint32_t n);
void calculateDiagonals(int*** arr, uint32_t n, long long* sums);
void printFull3DArray(int ***arr, uint32_t n);

#ifdef __cplusplus
}
#endif

#endif //LR4_FUNC_H