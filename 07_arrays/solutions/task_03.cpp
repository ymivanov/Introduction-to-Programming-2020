/**
 * @file   task_03.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 3 from practice 7.
 */
#include <iostream>

const int MAX_SIZE = 1024;

void readArr(int arr[], size_t size);
void printArr(int arr[], size_t size);
void removeElem(int arr[], size_t& size, size_t index);

int main() {

    int arr[MAX_SIZE];
    size_t n;

    std::cin >> n;

    readArr(arr, n);
    size_t index;
    std::cin >> index;

    removeElem(arr, n, index);
    printArr(arr, n);

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

void removeElem(int arr[], size_t& size, size_t index) {
    if(index < 0 || index >= size) {
        return;
    }

    for(size_t i = index; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    --size;
}