/**
 * @file   task_05.cpp
 * @author Dimitar Kolev
 * @date   11.2020
 * @brief  Solution for task 5 from practice 6.
 */

#include <iostream>

using namespace std;

void readArray(int arr[], size_t size);
bool isPrime(int num);
void printPrimeNums(int arr[], size_t size);

int main() 
{
    const int MAX_SIZE = 1024;
    int arr[MAX_SIZE];
    int size;
    cin >> size;
    readArray(arr, size);
    printPrimeNums(arr, size);
    return 0;
}

void readArray(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}


bool isPrime(unsigned num) 
{
    // smallest prime is 2
    if(num < 2) 
    {
        return false;
    }

    // all even numbers are not prime except 2
    if(num % 2 == 0) 
    {
        return num == 2;
    }
 
    for(size_t i = 3; i*i <= num; i += 2) 
    {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeNums(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        if (isPrime(arr[i]))
            cout << arr[i] << " ";
    }
}
