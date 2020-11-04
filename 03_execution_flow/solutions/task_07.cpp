/**
 * @file   task_07.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 7 from practice 3.
 */

#include <iostream>

int main() {

    int x;
    
    std::cout << "x -> ";
    std::cin >> x;

    if(x >= 0) {
        std::cout << x << std::endl;
    } else {
        std::cout << -x << std::endl;
    }

    return 0;
}