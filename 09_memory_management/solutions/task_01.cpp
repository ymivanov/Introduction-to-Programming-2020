/**
 * @file   task_01.cpp
 * @author Victor Nolev
 * @date   04.01.2021
 * @brief  Solution for Task 1 from Practice 9
 * Requirements: Use dynamic memory wisely
 */

#include <iostream>

void input(int *&arr, int &size);

bool pushBack(int *&arr, int &size, int &capacity, int element);

bool popBack(int *&arr, int &size, int element);

bool resize(int *&arr, int oldSize, int newSize);

void print(int *&arr, int size);

int main() {
    // Initial size of the array (hardcoded :D)
    int elementsCount = 5;
    // Maximum count of elements that allocated array can store
    int capacity = elementsCount;
    int *elements = new(std::nothrow) int[capacity];

    if (!elements) {
        std::cerr << "Memory is not correctly allocated!\n";
        return 1;
    }

    input(elements, elementsCount);

    int element;
    std::cout << "Enter a number to add to the back of the array:\n";
    std::cin >> element;

    // Hardcoded "tests" for pushBack and popBack operations
    if (pushBack(elements, elementsCount, capacity, element)) {
        std::cout << "The element was added!\n";
        print(elements, elementsCount);
    } else {
        std::cout << "The element could not be added! Not enough memory?\n";
    }

    if (popBack(elements, elementsCount, element)) {
        std::cout << "The element was removed!\n";
        print(elements, elementsCount);
    } else {
        std::cout << "The element could not be removed!\n";
    }

    // Delete allocated memory before terminating the program
    delete[] elements;
    return 0;
}

bool pushBack(int *&arr, int &size, int &capacity, int element) {
    // If elements in array are more than its capacity - increase capacity
    if (size + 1 > capacity) {
        // Before adding new element we have to allocate enough capacity
        // It is better idea to increase capacity by *2
        // to avoid expensive operation like resizing if we pushBack more than once
        capacity *= 2;
        if (!resize(arr, size, capacity)) {
            std::cout << "Can not push back this element to the end or array!\n";
            return false;
        }
        // Push back given element at the end of the array
        arr[size] = element;

        // Update the actual size, given by reference
        ++size;
        return true;
    }
    // If there is enough capacity - just add the new element
    // and increase size
    arr[size++] = element;
    return true;
}

bool popBack(int *&arr, int &size, int element) {
    int newSize = size - 1;
    if (!resize(arr, size, newSize)) {
        std::cout << "Can not pop back this element!\n";
        return false;
    }

    // Update the actual size, given by reference
    size = newSize;
}

bool resize(int *&arr, int oldSize, int newSize) {

    int *tempArray = new(std::nothrow) int[newSize];

    // Make sure that memory is allocated properly
    if (!tempArray) {
        std::cout << "Can not allocate new array!\n";
        return false;
    }

    // Copy elements from array with less allocated size
    int lessSize = oldSize < newSize ? oldSize : newSize;
    for (int i = 0; i < lessSize; ++i) {
        tempArray[i] = arr[i];
    }

    // Delete allocated memory with elements from the old array
    delete[] arr;

    // Reallocate new array to the old pointer
    arr = tempArray;
    return true;
}

void print(int *&arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << '\n';
}
