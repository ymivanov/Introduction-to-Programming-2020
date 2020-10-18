/**
 * @file   task_04.cpp
 * @author Yosif Ivanov
 * @date   10.2020
 * @brief  Solution for task 4 from practice 1.
 */

#include <iostream>

int main()
{       
    int p, q;

    std::cin >> p >> q;

    std::cout << "quotient = " << p / q << std::endl;
    std::cout << "remainder = " << p % q << std::endl;

    return 0;
}