/**
 * @file   task_06.cpp
 * @author Dimitar Kolev
 * @date   11.2020
 * @brief  Solution for task 6 from practice 6.
 */

#include <iostream>

using namespace std;

void readArray(int arr[], size_t size);
int sum(int arr[], size_t size);
int product(int arr[], size_t size);

int main() 
{
    const int MAX_SIZE = 1024;
    int arr[MAX_SIZE];
    int size;
    readArray(arr, size);
    cout << sum(arr, size) << endl;
    cout << product(arr, size);

    return 0;
}

void readArray(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int sum(int arr[], size_t size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int product(int arr[], size_t size)
{
    int product = 1;
    for (int i = 0; i < size; i++)
    {
        product *= arr[i];
    }

    return product;
}