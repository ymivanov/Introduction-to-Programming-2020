 /**
  * @file   task_06.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 6 from practice 2.
  */

#include <iostream>


int main() {
    int num;
    std::cin >> num;

    //we need to know only the least significant bit - 
    //if it is raised then the number is odd otherwise it is even
    std::cout << ((num & 1) ? "YES": "NO") << std::endl;
    
    return 0;
}