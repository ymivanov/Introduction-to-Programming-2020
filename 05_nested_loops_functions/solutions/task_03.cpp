/**
 * @file   task_03.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 3 from practice 5.
 */

#include <iostream>

int max (int first_num, int second_num);

int main() {

    unsigned num1, num2;
    std::cin >> num1 >> num2;

    std::cout << max(num1, num2) << std::endl;

    return 0;
}

int max (int first_num, int second_num) {
    return (first_num >= second_num) ? first_num : second_num;
}