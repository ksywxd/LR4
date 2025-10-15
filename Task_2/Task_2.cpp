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

void Task() {
    int M = 0, N = 0;
    std::cout << "Введите количество элементов в столбце:" << std::endl;
    checkInputIntK(M);
    std::cout << "Введите количество элементов в строке:" << std::endl;
    checkInputIntK(N);

    int arr[M][N];
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            std::cout << "Введите элемент a" << i << j  << ": "<< std::endl;
            checkInputArray(arr[i][j]);
        }
    }

    std::cout << "Initial massive:\n";
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int count = 0;
    if (M <= N){
        count = (M * (2 * N - M - 1)) / 2;
    }
    else {
        if (M > N){
            count = (N * (N - 1)) / 2;
        }
        else {
        std::cout << "Нет элементов выше побочной оси." << std::endl;
        }
    }
    int *arrHigher = new int[count];

    int count2 = 0;
    int max = arr[0][0];
    for (int j = 0; j < N; j++){
        for (int i = 0; i < M; i++){
            if (i + j < N - 1){
                arrHigher[count2++] = arr[i][j];
                max = std::max(max, arr[i][j]);
            }
        }
    }
    std::cout << "Максимальный элемент выше побочной оси: " << max << std::endl;

    delete[] arrHigher;
}

void Menu() {
    std::cout << "\t Task 2\n";
    std::cout << "\tVariant 9\n" << std::endl;
    std::wcout << "Найти максимальный элемент двумерного массива выше побочной оси.\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std:: endl;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
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