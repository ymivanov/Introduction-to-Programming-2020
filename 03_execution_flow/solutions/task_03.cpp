/**
 * @file   task_03.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 3 from practice 3.
 */

#include <iostream>

int main() {
    unsigned x, y, z;
    std::cout << "x -> ";
    std::cin >> x;

    std::cout << "y -> ";
    std::cin >> y;

    std::cout << "z -> ";
    std::cin >> z;

    if (x < y) {
        if (x < z) { // here we know that 'x' is the least one
            // it only remains to check which is less between 'y' and 'z'
            if (y < z) {
                std::cout << x << " < " << y << " < " << z << std::endl;
            } else {
                std::cout << x << " < " << z << " <= " << y << std::endl;
            }
        } else {
            std::cout << z << " <= " << x << " < " << y << std::endl;
        }
    } else { 
		if (y < z) { // here we know that 'y' is the least one
			if (x < z) {
				std::cout << y << " <= " << x << " < " << z << std::endl;
			} else {
				std::cout << y << " < " << z << " <= " << x << std::endl;
			}
		} else { 
			std::cout << z << " <= " << y << " <= " << x << std::endl;
		}
	}
    
    return 0;
}