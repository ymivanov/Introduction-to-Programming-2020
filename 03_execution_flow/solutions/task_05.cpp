/**
 * @file   task_05.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 5 from practice 3.
 */

#include <iostream>

int main() {
    int a, b, c;
    std::cout << "a -> ";
    std::cin >> a;

    std::cout << "b -> ";
    std::cin >> b;

    std::cout << "c -> ";
    std::cin >> c;

    if(a < 0 || b < 0 || c < 0) {
        std::cout << "Invalid input!" << std::endl;
        return 1; // eait the program
    }

    // three sides form a triangle if the sum of any 
    // two sides is greater than the third
    if(a + b > c && a + c > b && b + c > a) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    return 0;
}