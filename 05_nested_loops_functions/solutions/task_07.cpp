/**
 * @file   task_07.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 7 from practice 5.
 */

#include <iostream>

unsigned fibonacci(unsigned num);

int main() {

    unsigned n;
    std::cin >> n;

    std::cout << fibonacci(n) << std::endl;

    return 0;
}

// https://en.wikipedia.org/wiki/Fibonacci_number
unsigned fibonacci(unsigned num) {
	// by definition: fib(0) = 0
	if (num == 0) {
		return 0;
    }

	// fib(1) = fib(2) = 1
	if (num == 1 || num == 2) {
		return 1;
    }

	unsigned int fib1 = 1;
	unsigned int fib2 = fib1;

	num -= 2;
	while (num--) {
		fib2 = fib1 + fib2;
		fib1 = fib2 - fib1;
	}

	return fib2;
}