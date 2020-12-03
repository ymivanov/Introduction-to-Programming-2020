/**
 * @file   task_05.cpp
 * @author Yosif Ivanov
 * @date   11.2020
 * @brief  Solution for task 5 from practice 7.
 */

#include <iostream>

const int SIZE = 1024;

void printArr(float arr[], size_t size);
void deleteElement(float arr[], size_t& size, size_t deleteAtIndex);
float getAverage(float arr[], size_t size);
void updateArray(float arr[], size_t& size);

int main() {

    size_t size;
    std::cin >> size;

    float arr[SIZE];

    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    updateArray(arr, size);
    printArr(arr, size);
}

void printArr(float arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void deleteElement(float arr[], size_t& size, size_t deleteAtIndex) {

    for(int i = deleteAtIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    --size;
}

float getAverage(float arr[], size_t size) {

    float average = 0;

    for(int i = 0; i < size; i++) {
        average += arr[i];
    }

    return average/size;
}

void updateArray(float arr[], size_t& size) {

    float average = getAverage(arr, size);

    for(int i = 0; i < size; i++) {
        if(arr[i] < average) {
            deleteElement(arr, size, i);
            i--;
        }
    }
}
