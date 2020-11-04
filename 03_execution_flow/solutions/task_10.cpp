/**
 * @file   task_10.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 10 from practice 3.
 */

#include <iostream>
#include <cmath> 

const float EPS = 1E-3; // 1 * 10^(-3);     0.001

int main() {
    float x1, y1, r1, x2, y2, r2;
    
    std::cout << "X1 -> ";
    std::cin >> x1;

    std::cout << "Y1 -> ";
    std::cin >> y1;

    std::cout << "R1 -> ";
    std::cin >> r1;

    std::cout << "X2 -> ";
    std::cin >> x2;

    std::cout << "Y2 -> ";
    std::cin >> y2;

    std::cout << "R2 -> ";
    std::cin >> r2;

    int distX = x2 - x1;
    int distY = y2 - y1;

    double dist = sqrt(distX*distX + distY*distY);
 
    if (abs(dist - (r1 + r2)) < EPS) { // first check if they touch to avoid the 
                                       // error of working with floating point numbers
        std::cout << "Допират се" << std::endl;
    } else if (dist < (r1+r2)) {
        std::cout << "Пресичат се" << std::endl;
    } else {
         std::cout << "Нямат общи точки" << std::endl;
    }
    return 0;
}