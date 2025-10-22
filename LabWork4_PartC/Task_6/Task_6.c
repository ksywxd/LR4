#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>

void checkInputChoice(int* choice) {
    char line[1000];
    while (1) {
        printf("Start?\n1.YES\n2.EXIT\n3.Show menu\n");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }
        if (strchr(line, '\n') == NULL){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Input too long.\n");
            continue;
        }

        //замена \n - \0
        line[strcspn(line, "\n")] = 0;

        //только цифры
        int valid = 1;
        for (uint32_t i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i])) {
                valid = 0;
                break;
            }
        }
        //нашёл ли в лайне чойс
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
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input error.\n");
            continue;
        }

        if (strchr(line, '\n') == NULL){
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Input too long.\n");
            continue;
        }

        line[strcspn(line, "\n")] = 0;

        if (line[0] == '\0') {
            printf("Empty input.\n");
            continue;
        }

        int valid = 1;
        for (uint32_t i = 0; line[i] != '\0'; i++) {
            if (!isdigit((unsigned char)line[i])) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("Incorrect input.\n");
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
        if (val < 1) {
            printf("Number must be >= 1.\n");
            continue;
        }

        *n = (uint32_t)val;
        break;
    }
}

void printField(uint32_t** arr, uint32_t n) {
    uint32_t maxVal = n * n;
    uint32_t width = 0;
    do {
        width++;
        maxVal /= 10;
    } while (maxVal > 0);

    printf("Final field:\n");

    for (uint32_t i = 0; i < n; i++) {
        for (uint32_t j = 0; j < n; j++) {
            printf("%*u ", width, arr[i][j]);
        }
        printf("\n");
    }
}

void Task() {
    uint32_t n;
    printf("Enter the order of the magic square: ");
    checkInputInt(&n);
    if (n % 2 == 1) {
        uint32_t** arr = (uint32_t**)malloc(n * sizeof(uint32_t*));
        if (arr == NULL) {
            printf("Ошибка выделения памяти!\n");
            return;
        }
        for (uint32_t k = 0; k < n; k++) {
            arr[k] = (uint32_t*)calloc(n, sizeof(uint32_t));
            if (arr[k] == NULL) {
                printf("Ошибка выделения памяти для строки %u!\n", k);
                for (uint32_t j = 0; j < k; j++) {
                    free(arr[j]);
                }
                free(arr);
                return;
            }
        }
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

        printField(arr, n);
        printf("\n");

        for (uint32_t k = 0; k < n; k++) {
            free(arr[k]);
        }
        free(arr);
    } else {
        if ((n % 4) == 0) {
            uint32_t **arr = (uint32_t **)malloc(n * sizeof(uint32_t *));
            if (arr == NULL) {
                printf("Ошибка выделения памяти!\n");
                return;
            }

            for (uint32_t i = 0; i < n; i++) {
                arr[i] = (uint32_t *)malloc(n * sizeof(uint32_t));
                if (arr[i] == NULL) {
                    printf("Ошибка выделения памяти для строки %u!\n", i);

                    for (uint32_t j = 0; j < i; j++) {
                        free(arr[j]);
                    }
                    free(arr);
                    return;
                }
            }

            uint32_t count = 1;
            for (uint32_t i = 0; i < n; i++) {
                for (uint32_t j = 0; j < n; j++) {
                    arr[i][j] = count++;
                }
            }

            uint32_t k = n / 4;
            uint32_t m = n / 2;
            const uint32_t C = n * n + 1;

            for (uint32_t i = 0; i < k; i++) { //верхний
                for (uint32_t j = k; j < k + m; j++) {
                    arr[i][j] = C - arr[i][j];
                }
            }

            for (uint32_t i = k; i < k + m; i++) { //левый
                for (uint32_t j = 0; j < k; j++) {
                    arr[i][j] = C - arr[i][j];
                }
            }

            for (uint32_t i = k; i < k + m; i++) { //правый
                for (uint32_t j = k + m; j < n; j++) {
                    arr[i][j] = C - arr[i][j];
                }
            }

            for (uint32_t i = k + m; i < n; i++) { //нижний
                for (uint32_t j = k; j < k + m; j++) {
                    arr[i][j] = C - arr[i][j];
                }
            }

            printField(arr, n);
            printf("\n");

            for (uint32_t q = 0; q < n; q++) {
                free(arr[q]);
            }
            free(arr);
        }
    }
}

void Menu() {
    printf("\t Task 6\n");
    printf("Creat magic square\n\n");
    printf("Creator: Kseniya Siamionava\n\n");
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