#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
#include <iostream>

//Bubble Sorting
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    // Step 1: For i = 0 to N-1 repeat Step 2
    for (int i = 0; i < arrSize - 1; i++) {
        // Step 2: For j = i + 1 to N – 1 repeat
        for (int j = i + 1; j < arrSize; j++) {
            // Step 3: if arr[j] > arr[i], swap arr[j] and arr[i]
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
        // [End of Inner for loop]
    }
    // [End of Outer for loop]
    // Step 4: Exit
}

// Selection Sort
template <typename T> int Routine_Smallest(T A[], int K, const int arrSize);

template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, temp, pass = 0;
    
    // Step 1: Repeat Steps 2 and 3 for i = 0 to N-1
    for (int i = 0; i < N - 1; i++) {
        // Step 2: Call routine smallest(arr, i, N, POS)
        POS = Routine_Smallest(arr, i, N);
        // Step 3: Swap arr[i] with arr[POS]
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        // Count pass
        pass++;
    }
    // [End of loop]
    // Step 4: EXIT
}

// Routine smallest (Array, Current Position, Size of Array)
template <typename T>
int Routine_Smallest(T arr[], int K, const int arrSize) {
    int position, j;
    // Step 1: Initialize smallestElem = arr[K]
    T smallestElem = arr[K];
    // Step 2: Initialize position = K
    position = K;
    // Step 3: For j = K+1 to N-1, repeat
    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    // Step 4: Return position
    return position;
}

// Insertion Sort

template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J, temp;
    
    // Step 1: Repeat Steps 2 to 5 for K = 1 to N-1
    while (K < N) {
        // Step 2: Set temp = arr[K]
        temp = arr[K];
        // Step 3: Set J = K - 1
        J = K - 1;
        // Step 4: Repeat while temp < arr[J], shifting elements to the right
        while (J >= 0 && temp < arr[J]) {
            // Set arr[J + 1] = arr[J]
            arr[J + 1] = arr[J];  
            // Set J = J - 1
            J--;
        }
        // Step 5: Set arr[J + 1] = temp
        arr[J + 1] = temp;
        // [End of inner loop]
        // [End of loop]
        K++;
    }
    
    // Step 6: Exit
}


#endif
