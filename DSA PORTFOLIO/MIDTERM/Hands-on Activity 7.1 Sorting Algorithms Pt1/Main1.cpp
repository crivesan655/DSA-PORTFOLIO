#include <iostream>
#include <cstdlib> // this is what we will be using for random values
#include <ctime> // this is for the function time()
#include <algorithm> // for the std::copy for it to be able to copy the rand values of elements within the array
#include "sorting_algorithms.h" // the header file

const int SIZE = 100;

// This is the function to print out the array
template <typename T>
void printArray(const T arr[], int size){
	for (int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
		if ((i+1) % 20 == 0) std::cout << std::endl; // this will print out 20 elements in each line
	}
	std::cout << std::endl;
}
 
int main(){
	// For seeding the random number generator
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	// This function creates and fill the array with random values which ranges from 0 to 999
	int org_Array[SIZE];
	for (int i = 0; i < SIZE; i++){
		org_Array[i] = std::rand() % 1000;
	}
	
	// This will print out the unsorted array for the comparison to the sorted one
	std::cout << "Unsorted Array:\n";
	printArray(org_Array, SIZE);

    // Create copies for each sorting algorithm
    int bubbleArray[SIZE];
    int selectionArray[SIZE];
    int insertionArray[SIZE];
	
	//this will copy the array generated randomly
    std::copy(org_Array, org_Array + SIZE, bubbleArray);
    std::copy(org_Array, org_Array + SIZE, selectionArray);
    std::copy(org_Array, org_Array + SIZE, insertionArray);

    // Sort using Bubble Sort
    bubbleSort(bubbleArray, SIZE);
    std::cout << "\nBubble Sorted Array:\n";
    printArray(bubbleArray, SIZE);

    // Sort using Selection Sort
    selectionSort(selectionArray, SIZE);
    std::cout << "\nSelection Sorted Array:\n";
    printArray(selectionArray, SIZE);

    // Sort using Insertion Sort
    insertionSort(insertionArray, SIZE);
    std::cout << "\nInsertion Sorted Array:\n";
    printArray(insertionArray, SIZE);

    return 0;
}

