 /**
  * @file   task_03.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 3 from practice 2.
  */

#include <iostream>

const short TIMES_TO_SHIFT = 8;

int main() {

    short num;
    std::cin >> num;

    // get the first byte using & with mask 0b1111 1111
    short first_byte = (num & 0xFF); 
    // we will lose the first 8 bits after shifting the number
    short second_byte = (num >> TIMES_TO_SHIFT);

    short swapped_bytes = ((first_byte << TIMES_TO_SHIFT) | second_byte);
    std::cout << "New num: " << swapped_bytes << std::endl;

    return 0;
}