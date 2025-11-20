#include <iostream>
#include <random>
#include <algorithm>
#include "sorting_algorithms.h"

const int SIZE = 100;

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ((i + 1) % 10 == 0 ? "\n" : "\t");
    }
    std::cout << "\n";
}

int main() {
    int originalArray[SIZE];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 999);

    for (int i = 0; i < SIZE; ++i) {
        originalArray[i] = dist(gen);
    }

    std::cout << "Original Unsorted Array (Table 8-1):\n";
    printArray(originalArray, SIZE);

    int quickSorted[SIZE];
    std::copy(originalArray, originalArray + SIZE, quickSorted);
    quickSort(quickSorted, SIZE);
    std::cout << "\nQuick Sorted Array:\n";
    printArray(quickSorted, SIZE);

    return 0;
}

