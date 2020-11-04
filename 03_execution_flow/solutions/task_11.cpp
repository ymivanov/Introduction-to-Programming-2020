/**
 * @file   task_11.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 11 from practice 3.
 */

#include <iostream>
#include <cmath> 

int main() {
    
    int x, y;

	std::cout << "Enter the coordinates of the point: ";
	std::cin >> x >> y;
    
	if (y > 0) {
        // we should check if we are in the semi-circle
        int r = 2 * 2; // circle's radius (powered by 2, to avoid floating point calculations)
        // the distance from the point to (0, 0) [where the center of the circle is]
        int dist_squared = (x * x) + (y * y);
        if (dist_squared <= r) {
            std::cout << "inside!" << std::endl;
        }

	} else {
        // we should check if we are in the rectangle
        if ((std::abs(x) <=  1) &&
            (std::abs(y) <=  4)) {
            std::cout << "outside!" << std::endl;
        }
	}

    return 0;
}