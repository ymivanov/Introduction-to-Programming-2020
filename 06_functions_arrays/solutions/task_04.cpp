/**
 * @file   task_04.cpp
 * @author Nikolay Mananski
 * @date   11.2020
 * @brief  Solution for task 4 from practice 6.
 */

#include <iostream>

void readArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

void maxAndMin(int array[], size_t size, int& minIndex,
    int& minValue, int& maxIndex, int& maxValue)
{
    minValue = array[0];
    maxValue = array[0];
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < minValue)
        {
            minIndex = i;
            minValue = array[i];
        }

        if (array[i] > maxValue)
        {
            maxIndex = i;
            maxValue = array[i];
        }
    }
}

int main()
{
    int const SIZE = 1024;

    int n;
    std::cin >> n;

    int minIndex = 0, minValue = 0;
    int maxIndex = 0, maxValue = 0;

    int array[SIZE];

    readArray(array, n);
    maxAndMin(array, n, minIndex, minValue, maxIndex, maxValue);
    std::cout << "min_index = " << minIndex << " min_value = " << minValue;
    std::cout << " max_index = " << maxIndex << " max_value = " << maxValue;
}