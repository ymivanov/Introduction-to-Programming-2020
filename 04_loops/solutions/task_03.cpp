/**
 * @file   task_03.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 3 from practice 4.
 */

#include <iostream>

int main() {

    int n;
    std::cin >> n;

    while(n != 0) {
        //print last digit
        std::cout << n % 10;
        //remove last digit
        n /= 10;
    }

    std::cout << std::endl;

    return 0;
}