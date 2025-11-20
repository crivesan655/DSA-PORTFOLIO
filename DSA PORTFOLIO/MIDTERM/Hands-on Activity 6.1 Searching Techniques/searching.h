#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

// --- Linear search for arrays ---
void linearSearch(int data[], int n, int item) {
    int i = 0;
    while (i <= n) {
        if (data[i] == item) {
            std::cout << "Searching is successful" << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful" << std::endl;
}

// --- Linear search with comparison count (for Problem 1) ---
int linearSearchWithCount(int data[], int n, int item) {
    int comparisons = 0;
    for (int i = 0; i <= n; ++i) {
        comparisons++;
        if (data[i] == item) {
            std::cout << "Searching is successful\n";
            return comparisons;
        }
    }
    std::cout << "Searching is unsuccessful\n";
    return comparisons;
}

// --- Count repeating instances in array (for Problem 2) ---
int countRepeatsArray(int data[], int n, int item) {
    int count = 0;
    for (int i = 0; i <= n; ++i) {
        if (data[i] == item) {
            count++;
        }
    }
    return count;
}

// --- Linear search for linked list ---
template <typename T>
void linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == dataFind) {
            std::cout << "Searching is successful" << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Searching is unsuccessful" << std::endl;
}

// --- Linked list linear search with comparison count (for Problem 1) ---
template <typename T>
int linearLSWithCount(Node<T>* head, T dataFind) {
    int comparisons = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        comparisons++;
        if (current->data == dataFind) {
            std::cout << "Searching is successful\n";
            return comparisons;
        }
        current = current->next;
    }
    std::cout << "Searching is unsuccessful\n";
    return comparisons;
}

// --- Count repeating instances in linked list (for Problem 2) ---
template <typename T>
int countRepeatsList(Node<T>* head, T item) {
    int count = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// --- Binary search for arrays ---
void binarySearch(int arr[], int n, int no) {
    int low = 0;
    int up = n - 1;

    while (low <= up) {
        int mid = (low + up) / 2;
        if (arr[mid] == no) {
            std::cout << "Search element is found!" << std::endl;
            return;
        } else if (no < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found" << std::endl;
}

// --- Binary search with verbose iteration output (Problem 3) ---
void binarySearchVerbose(int arr[], int n, int no) {
    int low = 0;
    int up = n - 1;
    int iteration = 1;

    while (low <= up) {
        int mid = (low + up) / 2;
        std::cout << "Iteration " << iteration++
                  << ": low=" << low
                  << ", up=" << up
                  << ", mid=" << mid
                  << ", arr[mid]=" << arr[mid] << std::endl;

        if (arr[mid] == no) {
            std::cout << "Search element is found!" << std::endl;
            return;
        } else if (no < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    std::cout << "Search element is not found" << std::endl;
}

// --- Get middle node for linked list binary search ---
Node<int>* getMiddle(Node<int>* start, Node<int>* last) {
    if (start == nullptr)
        return nullptr;

    Node<int>* slow = start;
    Node<int>* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// --- Binary search on sorted linked list ---
Node<int>* binarySearchLinkedList(Node<int>* head, int key) {
    Node<int>* start = head;
    Node<int>* last = nullptr;

    while (start != last) {
        Node<int>* mid = getMiddle(start, last);

        if (mid == nullptr)
            return nullptr;

        if (mid->data == key)
            return mid;
        else if (mid->data < key)
            start = mid->next;
        else
            last = mid;
    }
    return nullptr;
}

// --- Recursive binary search (Problem 4) ---
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;  // Not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid;  // Found key
    } else if (key < arr[mid]) {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    } else {
        return recursiveBinarySearch(arr, mid + 1, high, key);
    }
}

#endif

