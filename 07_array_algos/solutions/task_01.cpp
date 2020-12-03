/**
 * @file   task_01.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 1 from practice 7.
 */
#include <iostream>

void readArr(int arr[], size_t size);
bool isSorted(int arr[], size_t size);

int main() {
    const int MAX_SIZE = 1024;

    int arr[MAX_SIZE];
    size_t n;

    std::cin >> n;

    readArr(arr, n);

    if(isSorted(arr, n)) {
        std::cout << "The array is sorted in descending order" << std::endl;
    } else {
        std::cout << "The array is not sorted!" << std::endl;
    }

    return 0;
}

void readArr(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

bool isSorted(int arr[], size_t size) {
    for(size_t i = 0; i < size - 1; i++) {
        if(arr[i] < arr[i+1]) {
            return false;
        }
    }   
    return true;
}