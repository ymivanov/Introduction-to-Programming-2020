 /**
  * @file   task_01.cpp
  * @author Yosif Ivanov
  * @date   11.2020
  * @brief  Solution for task 1 from practice 2.
  */

#include <iostream>

int main() {

	unsigned A; // unsigned == unsigned int

    std::cout << "Enter a number:"; 
	std::cin >> A;

    unsigned a1, a2, a3;
    std::cout << "Enter 3 bit positions:";
	std::cin >> a1 >> a2 >> a3;

	unsigned A_prim = A;
    unsigned mask = 1;

    A_prim |= (mask << a1); 
    mask = 1;
    A_prim |= (mask << a2);
    mask = 1;
    A_prim |= (mask << a3);

    // We can do it in one line:
    // A_prim = ((A | (1 << a1)) | (1 << a2)) | (1 << a3);

	std::cout << "The value of A' is " << A_prim << std::endl;
	std::cout << "A' - A = " << A_prim - A << std::endl;

    return 0;
}