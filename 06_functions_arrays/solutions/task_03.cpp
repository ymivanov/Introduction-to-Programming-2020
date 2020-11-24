/**
 * @file   task_03.cpp
 * @author Nikolay Mananski
 * @date   11.2020
 * @brief  Solution for task 3 from practice 6.
 */

#include <iostream>

int multiIndex(int array[], size_t size)
{
    int multi = 1;
    for(size_t i = 0; i <= size ; i++)
    {
        if (array[i] % 2 != 0)
        {
            multi *= i;
        }
    }

    return multi;
}

void readArray(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }
}

int main()
{
    const int SIZE = 1024;

    int n;
    std::cin >> n;

    int arr[SIZE];

    readArray(arr, n);
    std::cout << multiIndex(arr, n);

    return 0;
}