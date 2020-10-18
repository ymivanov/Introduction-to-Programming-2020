
/**
 * @file   task_01.cpp
 * @author Yosif Ivanov
 * @date   10.2020
 * @brief  Solution for task 1 from practice 1.
 */

#include <iostream>

int main()
{   
    //Declare two int variables
    int x, y;

    //Read input
    std::cout << "Enter the first number: ";
    std::cin >> x;
    std::cout << "Enter the second number: ";
    std::cin >> y;

    //Initialize helping variable
    int help;

    //Swap values
    help = x;
    x = y;
    y = help;

    //Output results
    std::cout << "x: " << x << std::endl
              << "y: " << y << std::endl;

    return 0;
}