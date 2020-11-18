/**
 * @file   task_08.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 8 from practice 5.
 */

#include <iostream>

bool isPrime(unsigned num);
int sumOfDigits (int num);
unsigned primesSumInRange(unsigned a, unsigned b);

int main() {

    unsigned a, b;
    std::cin >> a >> b;

    std::cout << primesSumInRange(a, b) << std::endl;

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

int sumOfDigits (int num) {
    int sum = 0;

    while(num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

unsigned primesSumInRange(unsigned a, unsigned b) {
    unsigned result = 0;
    for (size_t i = a; i <= b; i++) {
        // check each num in [a;b] if it's prime
        if(isPrime(i)) {
            // if it's prime -> add the sum of its digits to the result
            result += sumOfDigits(i);
        }
    }
    return result;
}