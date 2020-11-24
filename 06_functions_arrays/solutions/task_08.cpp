/**
 * @file   task_08.cpp
 * @author Kristian Ekov
 * @date   11.2020
 * @brief  Solution for task 8 from practice 6.
 */

#include <iostream>

void ReadInput(int arr[], unsigned n);
void ReadInputAdCalculate(int arr[], unsigned& n, int& sum, int& product);

int main()
{
    const int MAX_SIZE = 1024;

	unsigned n;
	int arr[MAX_SIZE];
	int sum = 0, product = 1;

	std::cout << "Enter arr size : ";
	std::cin >> n;
	std::cout << "Enter arr elements" << std::endl;

	Calculate(arr, n, sum, product);

	std::cout << "(P - S) =" << (product - sum);
}

void ReadInput(int arr[], unsigned n) {

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void Calculate(int arr[], size_t n, int& sum, int& product) {
	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 == 0) {
			product *= arr[i];
		}
		else {
			sum += arr[i];
		}
	}
}