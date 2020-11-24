/**
 * @file   task_01.cpp
 * @author Kristian Ekov
 * @date   11.2020
 * @brief  Solution for task 1 from practice 6.
 */

#include <iostream>
void ReadInput(int arr[], unsigned n);
void PrintArr(int arr[], unsigned n);

int main()
{
    const int MAX_SIZE = 1024;
	unsigned n;
	int arr[MAX_SIZE];

	ReadInput(arr, n);
	PrintArr(arr, n);
}

void ReadInput(int arr[], unsigned n) {
	std::cout << "Enter arr size : ";
	std::cin >> n;

	std::cout << "Enter arr elements" << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void PrintArr(int arr[], unsigned n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << arr[i];
	}
}