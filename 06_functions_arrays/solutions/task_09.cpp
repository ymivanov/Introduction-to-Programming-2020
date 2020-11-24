/**
 * @file   task_09.cpp
 * @author Dragomir Binev
 * @date   11.2020
 * @brief  Solution for task 9 from practice 6.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 1024;

void read_arr(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		cin >> arr[i];
}

bool moreRaisedBits(int elem)
{
	unsigned cnt_ones = 0;
	unsigned cnt_zeros = 0;
	unsigned mask = 1;
	while (elem)
	{
		if (elem & (mask))
			cnt_ones++;
		else
			cnt_zeros++;

		//we cut the element from the right
		elem >>= 1;
	}
	return cnt_ones > cnt_zeros;
}

int sumElemsWithMoreRaisedBits(int arr[], size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (moreRaisedBits(arr[i]))
			sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[MAX_SIZE];

	size_t size;
	cin >> size;

	read_arr(arr, size);
	cout << sumElemsWithMoreRaisedBits(arr, size);

	return 0;
}