/**
 * @file   task_08.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 8 from practice 5.
 */

#include <iostream>

bool isPrime(unsigned num);

int main() {

    unsigned n;
    std::cin >> n;

    std::cout << (isPrime(n) ? "yes": "no") << std::endl;

    return 0;
}

bool isPrime(unsigned num) {
    // smallest prime is 2
    if(num < 2) {
        return false;
    }

    // all even numbers are not prime except 2
    if(num % 2 == 0) {
        return num == 2;
    }
 
    for(size_t i = 3; i*i <= num; i+=2) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}