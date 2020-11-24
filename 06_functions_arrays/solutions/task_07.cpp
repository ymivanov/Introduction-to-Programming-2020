/**
 * @file   task_07.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 7 from practice 6.
 */

#include <iostream>

void read(int arr[], size_t size);
void print(int arr[], size_t size);
unsigned short indexMaxLen(int arr[], size_t size);

int main()
{
	const int SIZE = 1024;
	int arr[SIZE];

	size_t n;
	std::cin >> n;

	read(arr, n);
	std::cout << indexMaxLen(arr, n) << std::endl;

	return 0;
}

void read(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

unsigned short indexMaxLen(int arr[], size_t size) {
	int index = 0;
	int maxLen = 1;
	int currentLen = 1;

	for (size_t i = 0; i < size - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			currentLen++;
		}
		else {
			if (currentLen >= maxLen) {
				maxLen = currentLen;
				index = i - currentLen + 1;
			}
				currentLen = 1;
		}
	}

	if (currentLen >= maxLen) {
		maxLen = currentLen;
		index = size - currentLen;
	}

	return index;
}