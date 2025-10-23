#include <func.h>
#include <iostream>
#include <sstream>

void checkInputChoice(int& choice) {
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
}