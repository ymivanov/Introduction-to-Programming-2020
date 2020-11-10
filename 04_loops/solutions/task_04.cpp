/**
 * @file   task_04.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 4 from practice 4.
 */

#include <iostream>

int main() {

    unsigned n;
    std::cin >> n;

    int i = 0;
    unsigned sum = 0;
    int current_num;

    while(i < n) {
        std::cin >> current_num;
        sum += current_num;
        i++;
    }
    
    double avg = (float)sum / n; // cast sum to float. why?
    std::cout <<  avg << std::endl;

    return 0;
}