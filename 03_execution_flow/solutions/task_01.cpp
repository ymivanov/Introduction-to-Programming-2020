/**
 * @file   task_01.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 1 from practice 3.
 */

#include <iostream>

int main() {
    int x, y;
    std::cout << "x -> ";
    std::cin >> x;

    std::cout << "y -> ";
    std::cin >> y;

    if(x > y) {
        std::cout << x << std::endl;
    } else if (y > x) {
        std::cout << y << std::endl;
    } else {
        std::cout << "they are equal!" << std::endl;
    }
    return 0;
}