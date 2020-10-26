 /**
  * @file   task_02.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 2 from practice 2.
  */

#include <iostream>

int main() {

    unsigned A;
    std::cin >> A;

    unsigned mask = 0xFFFF; // 0b11111111 11111111
    unsigned A_prim = A ^ mask;

    std::cout << "A': " << A_prim << std::endl; 
    return 0;
}