/**
 * @file   task_02.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 2 from practice 4.
 */

#include <iostream>

int main() {

    unsigned n;
    std::cin >> n;

    unsigned sum = 0;

    while(n >= 1) {
        sum += n; // sum += n--; will have the same result. why?
        n--;      
    }
    std::cout << sum << std::endl; // (n*(n+1)) / 2
    return 0;
}