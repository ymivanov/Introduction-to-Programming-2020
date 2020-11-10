/**
 * @file   task_07.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 7 from practice 4.
 */

#include <iostream>

int main() {
    // we need two variables to be able to check each time that each 
    // subsequent number is greater than the previous one
    int current, prev;
    int counter = 1;
    std::cin >> prev;

    while(true) {
        std::cin >> current;
        
        if(current < prev) {
            break;
        }
        
        prev = current;
        counter++;
    }

    std::cout << counter << std::endl;

    return 0;
}