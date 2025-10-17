#include <iostream>
#include <string>
#include <sstream> //для 'сканера' текста (string stream)

void checkInputChoice(int& choice) {
    while (true) {
        std::cout << "Start?\n1. YES\n2. EXIT\n3. Show menu\n";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> choice && ss.eof()) {
            if (choice >= 1 && choice <= 3) {
                break; // одно число в диапазоне и ничего больше
            }
            else {
                std::cout << "Incorrect input. Enter 1, 2, or 3.\n";
            }
        }
        else {
            std::cout << "Incorrect input. Enter a single number.\n";
        }
    }
}

void checkInputIntK(int& k){
    while (true) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> k && ss.eof()) {
            if (k < 1) {
                std::cout << "Input error" << std::endl;
            }else {
                break;
            }
        } else {
            std::cout << "Incorrect input.\n";
        }
    }
}

void checkInputArray(int& x){
    while (true) {
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> x && ss.eof()) {
            break;
        } else {
            std::cout << "Incorrect input.\n";
        }
    }
}

void InputArray(int N, int** arr){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cout << "Enter element a" << i << j << ": ";
            checkInputArray(arr[i][j]);
        }
    }
}

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

void ShowMatrix(int N, int** arr){
    std::cout << "Initial massive:\n";
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Task() {
    int N = 0;
    std::cout << "Enter Matrix Order(N):" << std::endl;
    checkInputIntK(N);
    int** arr = new int*[N];

    //память для этажей
    for (int i = 0; i < N; i++){
        arr[i] = new int[N];//+ хатка на этаже
    }
    InputArray(N, arr); //заполнение матрицы
    ShowMatrix(N, arr);

    if (checkIsMatrix(N, arr) == true){
        std::cout << "Magic square." << std::endl;
    } else {
        std::cout << "Not a magic square." << std::endl;
    }

    for (int i = 0; i < N; i++){
        delete[] arr[i];
    }
    delete[] arr;
}

void Menu() {
    std::cout << "\t Task 2\n";
    std::cout << "\tVariant 9\n" << std::endl;
    std::cout << "Find the maximum element of a two-dimensional array above the secondary axis.\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std:: endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice = 0;

    while (true) {
        checkInputChoice(choice);

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