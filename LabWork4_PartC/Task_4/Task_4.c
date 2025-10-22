#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

void checkInputChoice(int* choice) {
    char line[1000];
    while (1) {
        printf("Start?\n1.YES\n2.EXIT\n3.Show menu\n");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        if (strchr(line, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Input too long.\n");
            continue;
        }

        line[strcspn(line, "\n")] = '\0';

        int valid = 1;
        for (size_t i = 0; line[i] != '\0'; i++) {
            if (!isdigit((unsigned char)line[i])) {
                valid = 0;
                break;
            }
        }

        if (valid && sscanf(line, "%d", choice) == 1) {
            if (*choice >= 1 && *choice <= 3) {
                break;
            } else {
                printf("Incorrect input. Enter 1, 2, or 3.\n");
            }
        } else {
            printf("Incorrect input. Enter a single number.\n");
        }
    }
}

void checkInputInt(uint32_t* n) {
    char line[1000];
    while (1) {
        printf("Enter array size n (1-100): ");

        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        if (strchr(line, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Input too long.\n");
            continue;
        }

        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0') {
            printf("Empty input.\n");
            continue;
        }

        int valid = 1;
        for (size_t i = 0; line[i] != '\0'; i++) {
            if (!isdigit((unsigned char)line[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Incorrect input. Please enter only digits.\n");
            continue;
        }

        errno = 0;
        char *endptr;
        unsigned long val = strtoul(line, &endptr, 10);

        if (*endptr != '\0') {
            printf("Incorrect input.\n");
            continue;
        }

        if (errno == ERANGE || val > UINT32_MAX) {
            printf("Number too large.\n");
            continue;
        }

        if (val < 1 || val > 100) {
            printf("Number must be between 1 and 100.\n");
            continue;
        }

        *n = (uint32_t)val;
        break;
    }
}

void Menu() {
    printf("\t Task 4\n");
    printf("Find max diagonal of 3D massive\n\n");
    printf("Creator: Kseniya Siamionava\n\n");
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

void Task() {
    uint32_t n;
    int ***arr = NULL;
    checkInputInt(&n);

    arr = (int***)malloc(n * sizeof(int**));
    if (arr == NULL) {
        printf("Memory error for array layers!\n");
        return;
    }

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = NULL;
    }

    for (uint32_t i = 0; i < n; i++) {
        arr[i] = (int**)malloc(n * sizeof(int*));
        if (arr[i] == NULL) {
            printf("Memory error for layer %u!\n", i);
            for (uint32_t j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return;
        }

        for (uint32_t j = 0; j < n; j++) {
            arr[i][j] = NULL;
        }

        for (uint32_t j = 0; j < n; j++) {
            arr[i][j] = (int*)malloc(n * sizeof(int));
            if (arr[i][j] == NULL) {
                printf("Memory error for row %u in layer %u!\n", j, i);
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
                return;
            }
        }
    }

    srand((unsigned int)time(NULL));
    int max_random;

    if (n < 10) max_random = 50;
    else if (n < 20) max_random = 30;
    else max_random = 20;

    printf("Filling with random numbers from 0 to %d\n", max_random - 1);

    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < n; j++) {
            for (uint32_t k = 0; k < n; k++) {
                arr[i][j][k] = rand() % max_random;
            }
        }
    }

    printFull3DArray(arr, n);

    long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    //диагонали
    for (uint32_t i = 0; i < n; i++) {
        sum1 += arr[i][i][i];                          // (i,i,i)
        sum2 += arr[i][i][n-1-i];                     // (i,i,n-1-i)
        sum3 += arr[i][n-1-i][i];                     // (i,n-1-i,i)
        sum4 += arr[i][n-1-i][n-1-i];                // (i,n-1-i,n-1-i)
    }

    printf("Diagonal 1 sum: %lld\n", sum1);
    printf("Diagonal 2 sum: %lld\n", sum2);
    printf("Diagonal 3 sum: %lld\n", sum3);
    printf("Diagonal 4 sum: %lld\n", sum4);

    long long max_sum = sum1;
    if (sum2 > max_sum) max_sum = sum2;
    if (sum3 > max_sum) max_sum = sum3;
    if (sum4 > max_sum) max_sum = sum4;

    printf("\nMaximum diagonal sum: %lld\n", max_sum);

    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < n; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int choice = 0;

    while (1) {
        checkInputChoice(&choice);

        if (choice == 1) {
            Task();
        }
        else if (choice == 2) {
            break;
        }
        else if (choice == 3) {
            Menu();
        }
    }
    return 0;
}