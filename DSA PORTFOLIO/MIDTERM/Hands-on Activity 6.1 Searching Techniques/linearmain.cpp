#include "searching.h"
#include <iostream>

int main() {
    int sortedData[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = sizeof(sortedData) / sizeof(sortedData[0]);
    int key = 8;

    std::cout << "Recursive Binary Search for key " << key << ":\n";
    int index = recursiveBinarySearch(sortedData, 0, size - 1, key);

    if (index != -1) {
        std::cout << "Search element is found at index " << index << std::endl;
    } else {
        std::cout << "Search element is not found" << std::endl;
    }

    return 0;
}

