/**
 * @file   task_02.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 2 from practice 3.
 */

#include <iostream>

int main() {
    unsigned x, y, z;
    std::cout << "x -> ";
    std::cin >> x;

    std::cout << "y -> ";
    std::cin >> y;

    std::cout << "z -> ";
    std::cin >> z;

    if(x >= y && x >= z) {
        std::cout << x << std::endl;
    } else if (y >= x && y >= z) {
        std::cout << y << std::endl;
    } else {
        std::cout << z << std::endl;
    }

    return 0;
}