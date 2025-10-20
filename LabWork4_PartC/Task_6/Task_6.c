#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

        int valid = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (!isdigit(line[i])) {
                valid = 0;
                break;
            }
        }

        if (valid && sscanf(line, "%d", k) == 1) {
            if (*n < 1) {
                printf("Input error\n");
            } else {
                break;
            }
        } else {
            printf("Incorrect input.\n");
        }
    }
}



void Task() {
    uint32_t n;
    printf("Enter the order of the magic square: ");
    checkInputInt(*n);
}

void Menu() {
    printf("\t Task 6\n");
    printf("\tVariant 9\n\n");
    printf("\n\n");
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