/**
 * @file   task_02.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 2 from practice 5.
 */

#include <iostream>


int sumOfDigits (int num);

int main() {

    unsigned n;
    std::cin >> n;

    int current_num;
    int sum = 0;

    while(n > 0) {
        std::cin >> current_num;
        sum += sumOfDigits(current_num); 
        n--;
    }

    std::cout << sum << std::endl;

    return 0;
}

int sumOfDigits (int num) {
    int sum = 0;

    while(num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}