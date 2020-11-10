/**
 * @file   task_01.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 1 from practice 4.
 */

#include <iostream>

int main() {

    unsigned n;
    std::cin >> n;

    unsigned i = 1;

    while(i <= n) {
        std::cout << '[';
        std::cout << i;
        std::cout << ']';
        i++;
    }
    std::cout << std::endl;

    return 0;
}