/**
 * @file   task_06.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 6 from practice 5.
 */

#include <iostream>

unsigned gcd(unsigned first_num, unsigned second_num);

int main() {

    unsigned n, k;
    std::cin >> n >> k;

    std::cout << gcd(n, k) << std::endl;

    return 0;
}

// using Euclidean algorithm
unsigned gcd(unsigned first_num, unsigned second_num) {
	unsigned int temp;

	while (second_num != 0) {
		temp = first_num % second_num;
		first_num = second_num;
		second_num = temp;
	}

	return first_num;
}