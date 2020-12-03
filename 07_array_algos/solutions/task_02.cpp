/**
 * @file   task_02.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 2 from practice 7.
 */
#include <iostream>

const int MAX_SIZE = 1024;

void readArr(int arr[], size_t size);
void printArr(int arr[], size_t size);
void insertElem(int arr[], size_t& size, int elem);

int main() {

    int arr[MAX_SIZE];
    size_t n;

    std::cin >> n;

    readArr(arr, n);

    int newElem;
    std::cin >> newElem;

    insertElem(arr, n, newElem);
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