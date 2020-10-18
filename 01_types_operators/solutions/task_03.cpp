
/**
 * @file   task_03.cpp
 * @author Yosif Ivanov
 * @date   10.2020
 * @brief  Solution for task 3 from practice 1.
 */

#include <iostream>

int main()
{       short int num;

    //Read input
	std::cout << "Enter a three-digit number: ";
	std::cin >> num;

    //Output results
	std::cout << num % 10        // Last digit
	          << (num / 10) % 10 // then the middle digit
	          << num / 100       // and the first digit
	          << std::endl;
    return 0;
}