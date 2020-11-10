/**
 * @file   task_06.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 6 from practice 4.
 */

#include <iostream>

int main() {

    const short BITS_CNT = 32;

    int n;
    std::cin >> n;

    unsigned cnt_ones = 0;
    unsigned cnt_zeros = 0;

    unsigned short i = 0;

    while(i < BITS_CNT) {
        if(n & (1 << i)) {
            cnt_ones++;
        } else {
            cnt_zeros++;
        }
        i++;
    }

    std::cout << "Ones ->  " << cnt_ones << std::endl
              << "Zeros -> " << cnt_zeros << std::endl;

    return 0;
}