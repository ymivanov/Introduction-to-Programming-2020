/**
 * @file   task_08.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 8 from practice 4.
 */

#include <iostream>

int main() {
   

    unsigned n;
    std::cin >> n;

    short i = 31; // starting from the last bit position

    while(i >= 0) {
        if(n & (1 << i)) {
            break;
        }
        i--;
    }

    if(i == 0) {
        std::cout << "Аll bits of the number are zero" << std::endl;
    } else {
        std::cout << i << std::endl;
    }

    return 0;
}