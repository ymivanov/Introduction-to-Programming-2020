/**
 * @file   task_04.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 4 from practice 3.
 */

#include <iostream>

int main() {
   
    int n;
    std::cout << "n -> ";
    std::cin >> n;

    // a number is even if it is divisible by 2 without remainder
    if (n % 2 == 0) {
        std::cout << "even" << std::endl;
    } else {
        std::cout << "odd" << std::endl;
    }
    return 0;
}