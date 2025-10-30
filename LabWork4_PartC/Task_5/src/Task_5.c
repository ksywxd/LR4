#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"

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
        for (int i = 0; line[i] != '\0'; i++) {
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

void checkInputInt(int* k) {
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

        int valid = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i])) {
                valid = 0;
                break;
            }
        }

        if (valid && sscanf(line, "%d", k) == 1) {
            if (*k < 1) {
                printf("Input error\n");
            } else {
                break;
            }
        } else {
            printf("Incorrect input.\n");
        }
    }
}

void checkInputBomb(int* I, int* J, int M, int N) {
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

        //цифры и пробелы
        int valid = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i]) && line[i] != ' ' && line[i] != '-') {
                valid = 0;
                break;
            }
        }

        if (valid && sscanf(line, "%d %d", I, J) == 2) {
            if (*I < 0 || *J < 0 || *I >= M || *J >= N) {
                printf("Input error: coordinates out of range\n");
            } else {
                break;
            }
        } else {
            printf("Incorrect input. Enter two numbers separated by space.\n");
        }
    }
}

void printField(int** arr, int M, int N) {
    printf("Final field:\n  ");
    for (int j = 0; j < N; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < M; i++) {
        printf("%d ", i);
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 9) {
                printf(" * ");
            } else if (arr[i][j] == 0) {
                printf(" . ");
            } else {
                printf(" %d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void checkInputCountBomb(int* countBomb, int M, int N){
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

        int valid = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i])) {
                valid = 0;
                break;
            }
        }

        if (valid && sscanf(line, "%d", countBomb) == 1) {
            if (*countBomb < 1 || *countBomb > (M * N)) {
                printf("Input error\n");
            } else {
                break;
            }
        } else {
            printf("Incorrect input.\n");
        }
    }
}

/*void IfValid(int** arr, int i, int j, int M, int N) {
    if (i >= 0 && i < M && j >= 0 && j < N) {
        if (arr[i][j] != 9) {
            arr[i][j]++;
        }
    }
}*/

void Task() {
    int N = 0, M = 0, countBomb = 0;
    printf("Enter number of columns: ");
    checkInputInt(&N);
    printf("Enter number of lines: ");
    checkInputInt(&M);

    int** arr = (int**)malloc(M * sizeof(int*));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 0; i < M; i++) {
        arr[i] = (int*)malloc(N * sizeof(int));
        if (arr[i] == NULL) {
            printf("Ошибка выделения памяти для строки %u!\n", i);

            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return;
        }
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    printf("Enter number of bombs: ");
    checkInputCountBomb(&countBomb, M, N);

    printf("Input example for bomb at [1;0] - 1 0\n");
    printf("Input format (zero-based): line column\n");

    int I = 0, J = 0;
    for (int k = 1; k <= countBomb; k++) {
        printf("Bomb %d: ", k);
        checkInputBomb(&I, &J, M, N);

        //бомба 9
        if (arr[I][J] == 9) {
            printf("Bomb already exists at this position.\n");
            k--;
            continue;
        }

        arr[I][J] = 9;
        if (I == 0 && J == 0){ //слева сверху
            IfValid(arr, I, J+1, M, N);
            IfValid(arr, I+1, J, M, N);
            IfValid(arr, I+1, J+1, M, N);
        } else if (I == 0 && J == (N - 1)){ // справа сверху
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I+1, J, M, N);
            IfValid(arr, I+1, J-1, M, N);
        } else if (I == (M - 1) && J == 0){ // слева снизу
            IfValid(arr, I-1, J, M, N);
            IfValid(arr, I-1, J+1, M, N);
            IfValid(arr, I, J+1, M, N);
        } else if (I == (M - 1) && J == (N - 1)){ // справа снизу
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I-1, J-1, M, N);
            IfValid(arr, I-1, J, M, N);
        } else if (I == 0) { //сверху посередине
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I+1, J-1, M, N);
            IfValid(arr, I+1, J, M, N);
            IfValid(arr, I+1, J+1, M, N);
            IfValid(arr, I, J+1, M, N);
        } else if (I == (M - 1)){ // снизу посередине
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I-1, J-1, M, N);
            IfValid(arr, I-1, J, M, N);
            IfValid(arr, I-1, J+1, M, N);
            IfValid(arr, I, J+1, M, N);
        } else if (J == 0){ //слева посередине
            IfValid(arr, I-1, J, M, N);
            IfValid(arr, I-1, J+1, M, N);
            IfValid(arr, I, J+1, M, N);
            IfValid(arr, I+1, J+1, M, N);
            IfValid(arr, I+1, J, M, N);
        } else if (J == (N - 1)){ // справа посередине
            IfValid(arr, I-1, J, M, N);
            IfValid(arr, I-1, J-1, M, N);
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I+1, J-1, M, N);
            IfValid(arr, I+1, J, M, N);
        } else { //середина
            IfValid(arr, I-1, J, M, N);
            IfValid(arr, I-1, J-1, M, N);
            IfValid(arr, I, J-1, M, N);
            IfValid(arr, I+1, J-1, M, N);
            IfValid(arr, I+1, J, M, N);
            IfValid(arr, I+1, J+1, M, N);
            IfValid(arr, I, J+1, M, N);
            IfValid(arr, I-1, J+1, M, N);
        }
    }

    printField(arr, M, N);

    for (int i = 0; i < M; i++) {
        free(arr[i]);
    }
    free(arr);
}

void Menu() {
    printf("\t Task 5\n");
    printf("Given a field\nin which the user enters the coordinates of the bombs.\nThe program displays a field with the final values\n\n");
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