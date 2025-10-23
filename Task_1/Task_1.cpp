#include <iostream>
#include <string>
#include <sstream> //для 'сканера' текста (string stream)

/*void checkInputChoice(int& choice) {
    while (true) {
        std::cout << "Start?\n1.YES\n2.EXIT\n3.Show menu\n";
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
}*/

/*void checkInputIntK(int& k){
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
                continue;
            } else {
                break;
            }
        } else {
            std::cout << "Incorrect input.\n";
        }
    }
}*/

void checkInputArray(double& x){
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
    //int k;
    std::cout << "You need to enter 5 elements of massive" << std::endl;
    //checkInputIntK(k);
    double arr[5];
    int negCount = 0, otherCount = 0;

    for (int i = 0; i < 5; i++){
        std::cout << "Enter " << i+1 << " number: " << std::endl;
        checkInputArray(arr[i]);
        if (arr[i] < 0){
            negCount++;
        } else {
            otherCount++;
        }
    }

    std::cout << "Initial array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    double* arrNegative = new double[negCount];
    double* arrOther = new double[otherCount];
    int indexNeg = 0, indexOther = 0;

    for (int i = 0; i < 5; i++){
        if (arr[i] < 0){
            arrNegative[indexNeg++] = arr[i];
        } else {
            arrOther[indexOther++] = arr[i];
        }
    }

    if (negCount > 0){
        std::cout << "Negative numbers: ";
        for (int i = 0; i < negCount; i++) {
            std::cout << arrNegative[i] << " ";
        }
        std::cout << std::endl;
    }
    if (otherCount > 0){
        std::cout << "Other numbers: ";
        for (int i = 0; i < otherCount; i++) {
            std::cout << arrOther[i] << " ";
        }
        std::cout << std::endl;
    }

    delete[] arrNegative;
    delete[] arrOther;
}

void Menu() {
    std::cout << "\tTask 1\n";
    std::cout << "\tVariant 9\n" << std::endl;
    std::cout << "Split an array into negative and other elements\n" << std::endl;
    std::cout << "Creator: Kseniya Siamionava\n" << std::endl;
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