 /**
  * @file   task_04.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 4 from practice 2.
  */

#include <iostream>

int main() {
    
    int num, n;
    std::cin >> num >> n;

    // we use the ternary operator otherwise we will get 0 or a power of two
    std::cout << ((num & (1 << n)) ? 1 : 0) << std::endl;

    return 0;
}