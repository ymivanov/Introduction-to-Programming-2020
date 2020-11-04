/**
 * @file   task_09.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 9 from practice 3.
 */

#include <iostream>

int main() {

    unsigned short day;
    std::cout << "Enter a number between 1 and 7: ";
    std::cin >> day;

    switch(day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "This is not a number between 1 and 7!" << std::endl;
            break;
    }

    return 0;
}