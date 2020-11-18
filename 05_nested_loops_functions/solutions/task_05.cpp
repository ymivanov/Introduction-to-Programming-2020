/**
 * @file   task_05.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 5 from practice 5.
 */

#include <iostream>

long power (unsigned n, unsigned k);

int main() {

    unsigned n, k;
    std::cin >> n >> k;

    std::cout << power(n, k) << std::endl;

    return 0;
}

long power (unsigned n, unsigned k) {
    long result = 1; // starting from 1(not 0) because n*0 = 0.
    for(size_t i = 0; i < k; i++) { // https://en.cppreference.com/w/cpp/types/size_t
        result *= n;
    }
    return result;
}