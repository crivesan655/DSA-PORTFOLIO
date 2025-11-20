#ifndef INSERTION_SORTING_H
#define INSERTION_SORTING_H

// Insertion Sort
template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J, temp;

    // Repeat Steps 2 to 5 for K = 1 to N-1
    while (K < N) {
        temp = arr[K];   // Store current element
        J = K - 1;       // Start comparing with previous element
        
        // Shift elements that are greater than temp to the right
        while (J >= 0 && temp < arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        
        // Insert temp into the correct position
        arr[J + 1] = temp;
        K++;
    }
}

#endif

