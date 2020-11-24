/**
 * @file   task_02.cpp
 * @author Kristian Ekov
 * @date   11.2020
 * @brief  Solution for task 2 from practice 6.
 */

#include <iostream>
void ReadArrReturnSumOfEvenElemnts(int arr[], size_t n);
void ReadArr(int arr[], size_t n);

int main()
{
    const int MAX_SIZE = 1024;
	int arr[MAX_SIZE];
	size_t n;
    
    std::cout << "Enter arr size : ";
	std::cin >> n;
	std::cout << "Enter arr elements" << std::endl;

    ReadArr(arr, n);
	std::cout << SumOfEvenElemnts(arr, n);
}
void ReadArr(int arr[], size_t n) {
    for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}
int SumOfEvenElemnts(int arr[], size_t n) {
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			sum += arr[i];
		}
	}

	return sum;
}
