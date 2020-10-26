 /**
  * @file   task_05.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 5 from practice 2.
  */

#include <iostream>


int main() {
    
    int num, n;
    std::cin >> num >> n;

    int mask = 1;
    mask <<= n;

    // instead of a mask of type 0...010...0 we need a mask of type 1...101...1.
    // we shift the 1 to where the 0 should be and invert the bits.
    std::cout << (num & (~mask)) << std::endl;

    return 0;
}