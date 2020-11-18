/**
 * @file   task_04.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 4 from practice 5.
 */

#include <iostream>

int abs_val(int num);

int main() {

    unsigned num;
    std::cin >> num;

    std::cout << abs_val(num) << std::endl;

    return 0;
}

int abs_val (int num) {
    return (num >= 0) ? num : (-num);
}