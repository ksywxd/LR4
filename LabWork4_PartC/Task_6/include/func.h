#ifndef LR4_FUNC_H
#define LR4_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

    // Основные функции для генерации магических квадратов
    uint32_t** generateOddMagicSquare(uint32_t n);
    uint32_t** generateDoublyEvenMagicSquare(uint32_t n);
    uint32_t** generateSinglyEvenMagicSquare(uint32_t n);

    // Вспомогательные функции
    uint32_t** createSquareMatrix(uint32_t n);
    void freeSquareMatrix(uint32_t** matrix, uint32_t n);
    int isMagicSquare(uint32_t** square, uint32_t n);


#ifdef __cplusplus
}
#endif


#endif //LR4_FUNC_H