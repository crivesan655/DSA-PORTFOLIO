#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <iostream>

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]); 
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

void quickSort(int arr[], int size) {
    quick_sort(arr, 0, size - 1);
}


#endif
