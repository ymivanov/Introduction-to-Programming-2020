/**
 * @file   task_05.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 5 from practice 4.
 */

#include <iostream>

int main() {

    unsigned n;
    std::cin >> n;

    short i = 31; // starting from the last bit position

    while(i >= 0) {
        if(n & (1 << i)) {
            std::cout << 1;
        } else {
            std::cout << 0;
        }
        // print a whitespace after every byte
        if(i % 8 == 0) {
            std::cout << ' ';
        }
        i--;
    }
    std::cout << std::endl;
    return 0;
}