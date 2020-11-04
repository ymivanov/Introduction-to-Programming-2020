/**
 * @file   task_08.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 8 from practice 3.
 */

#include <iostream>

int main() {

    char sym;
    std::cout << "Please enter a letter: ";
    std::cin >> sym;

    // It is not necessary to compare the ASCII code. This happens implicitly.
    if(sym >= 'a' && sym <= 'z') {
        std::cout << "Small letter" << std::endl;
    } else if (sym >= 'A' && sym <= 'Z') {
        std::cout << "Capital letter" << std::endl;
    } else {
        std::cout << "It is not a letter at all" << std::endl;
    }

    return 0;
}