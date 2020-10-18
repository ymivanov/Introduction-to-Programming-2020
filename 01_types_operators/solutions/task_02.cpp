
/**
 * @file   task_02.cpp
 * @author Yosif Ivanov
 * @date   10.2020
 * @brief  Solution for task 2 from practice 1.
 */

#include <iostream>

int main()
{   
    //Declare the number
    int num;

    // read input
	std::cout << "Enter a three-digit number: ";
	std::cin >> num;

    int first_digit = num % 10;
    num /= 10;

    int second_digit = num % 10;
    num /= 10;

    int third_digit = num;

    std::cout << "Sum = " << first_digit + second_digit + third_digit << std::endl
              << "Product = " << first_digit * second_digit * third_digit << std::endl
              << "Avg = " << (first_digit + second_digit + third_digit) / 3.0 << std::endl; // operator / should have at least
                                                                                            //  one float as an argument => 3.0 

    return 0;
}