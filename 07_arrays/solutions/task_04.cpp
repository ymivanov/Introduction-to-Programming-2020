/**
 * @file   task_04.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 4 from practice 7.
 */

#include <iostream>

const int MAX_SIZE = 1024;

void readArr(int arr[], size_t size);
void printArr(int arr[], size_t size);
void insertElem(int arr[], size_t& size, int elem);
void sortEven(int src[], size_t srcSize, int dest[], size_t& destSize);

int main() {

    int arr[MAX_SIZE];
    size_t n;

    std::cin >> n;

    readArr(arr, n);

    int evenArr[MAX_SIZE];
    size_t destSize = 0;

    sortEven(arr, n, evenArr, destSize);

    printArr(evenArr, destSize);

    return 0;
}

void readArr(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArr(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void insertElem(int arr[], size_t& size, int elem) {
    if (size >= MAX_SIZE) {
        return;
    }

    size_t i; 
    for (i = size - 1;(i >= 0 && arr[i] > elem); i--) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = elem;
    ++size;
}    

void sortEven(int src[], size_t srcSize, int dest[], size_t& destSize) {
    if (destSize != 0) {
        std::cout << "destSize must be 0!";
        return;
    }
    
    for (size_t i = 0; i < srcSize; i++) {
        if (src[i] % 2 == 0) {
            insertElem(dest, destSize, src[i]);
        }
    }
}