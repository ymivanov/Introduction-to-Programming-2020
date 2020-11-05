/*
    As this is a more interesting task that requires more than one case to be covered,
    I would like some of the students attending the 3rd group exercises to provide a 
    solution to discuss and upload here. :)
*/

       // <------------------->

/**
 * @file   yin-yang.cpp
 * @author Victor Nolev
 * @date   05.11.2020
 * @brief  Solution for task 12 from practice 3. Program was written on the phone in the bus on the way home (it is not fully tested)
 */

#include<iostream>

/*
 * NB! Radius in the given task is 4
    but I change it to 6
    just to follow the proportions of Yin-Yang symbol
    and not to calculate with floating point numbers :)
	
*/
const int bigR = 6; // Radius in Yin-Yang
const int middleR = bigR / 2;  // Radius of the middle circle in Yin-Yang
const int smallR = bigR / 6; // Radius of the small circle in Yin-Yang

int main() {

    // Coordinates of our point (assigned to 0 - just in case)
    int x = 0;
    int y = 0;

    std::cout << "Enter coordinates for X and Y (integers): ";
    std::cin >> x >> y; // No validation for the time being

    bool isPointBelowAbscissa = x <= 0;

    // Powered by 2 to avoid floating point calculations
    const int bigRSquared = bigR * bigR;
    const int middleRSquared = middleR * middleR;
    const int smallRSquared = smallR * smallR;

    // Distance from the center of Yin-Yang circle (0, 0) to the given point
    const int distanceFromCenterSquared = (x * x) + (y * y);

    const int coordXCenterSmallCircle = 0;
    // Determine the sign of Y coordinate (Y equals the middleR value)
    const int coordYCenterSmallCircle = isPointBelowAbscissa ? -middleR : middleR;

    // Distance from the center of determined small circle's center to the given point
    // Long but explicit name :D
    const int distanceFromSmallCircleCenterSquared = (coordXCenterSmallCircle - x) * (coordXCenterSmallCircle - x) +
                                                     (coordYCenterSmallCircle - y) * (coordYCenterSmallCircle - y);

    // Cases when point is outside of and on outer contour of Yin-Yang
    if (distanceFromCenterSquared > bigRSquared) {
        std::cout << "The given point is outside from Yin-Yang!" << std::endl;
        return 1; // Terminate the execution of the program
    }
    if (distanceFromCenterSquared == bigRSquared) {
        std::cout << "The given point is on the outer contour of Yin-Yang!" << std::endl;
        return 1; // Terminate the execution of the program
    }

    if (isPointBelowAbscissa) {
        if (distanceFromSmallCircleCenterSquared <= smallRSquared) {
            std::cout << "The given point is on the white part of small circle in Yin-Yang!" << std::endl;
        } else if (distanceFromSmallCircleCenterSquared > smallRSquared
                   && distanceFromSmallCircleCenterSquared <= middleRSquared) {
            std::cout << "The given point is on the black part of middle circle in Yin-Yang!" << std::endl;
        } else if (distanceFromSmallCircleCenterSquared > middleRSquared) {
            if (x >= 0) {
                std::cout << "The given point is on the black part of big circle in Yin-Yang!" << std::endl;
            } else {
                std::cout << "The given point is on the white part of big circle in Yin-Yang!" << std::endl;
            }
            // The plain else statement can print some error message
            // It is omitted here
        } else {
            // Symmetrically repeatable code here :V
            // We can reduce lines of code
            if (distanceFromSmallCircleCenterSquared <= smallRSquared) {
                std::cout << "The given point is on the black part of the smallest circle in Yin-Yang!" << std::endl;
            } else if (distanceFromSmallCircleCenterSquared > smallRSquared
                       && distanceFromSmallCircleCenterSquared <= middleRSquared) {
                std::cout << "The given point is on the white part of the middl circle in Yin-Yang!" << std::endl;
            } else if (distanceFromSmallCircleCenterSquared > middleRSquared) {
                // Repeatable code here :V (lines from 69 to 74)
                if (x >= 0) {
                    std::cout << "The given point is on the black part of big circle in Yin-Yang!" << std::endl;
                } else {
                    std::cout << "The given point is on the white part of big circle in Yin-Yang!" << std::endl;
                }
            }
            return 0;
        }
    }
}
