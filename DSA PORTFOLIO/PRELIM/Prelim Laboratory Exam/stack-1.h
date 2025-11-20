#include <iostream>
#include <string>
#define MAX 100 

template <typename T>
class stack {
private:
    int top;
    T arr[MAX];

public:
    // Constructor
    stack() : top(-1) {}

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Check if stack is full
    bool isFull() {
        return top >= MAX - 1;
    }

    // Peek at the top element
    void peek() {
        if (isEmpty()) {
            std::cout << "The Stack is Empty\n";
        } else {
            std::cout << "The value of the top is: " << arr[top] << std::endl;
        }
    }

    // Push an element onto the stack
    void push(T value) {
        if (isFull()) {
            std::cout << "STACK OVERFLOW!!" << std::endl;
        } else {
            arr[++top] = value;
        }
    }

    // Pop the top element
    void pop() {
        if (isEmpty()) {
            std::cout << "The Stack is Empty\n";
        } else {
            top--;
        }
    }

    // Get the top element
    T topElement() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            std::cerr << "Stack is empty\n";
            return T(); // Return default value
        }
    }

    // Display stack contents
    void display() {
        if (isEmpty()) {
            std::cout << "The Stack is Empty\n";
        } else {
            std::cout << "=====STACKS======\n";
            for (int i = top; i >= 0; i--) {
                std::cout << arr[i] << std::endl;
            }
        }
    }

    // Palindrome check using stack
	bool Palindrome_check(const std::string& s) {
    	stack<char> tempStack;

    // Push all characters onto the stack
    	for (size_t i = 0; i < s.length(); ++i) {
        tempStack.push(s[i]);
    }

    // Compare characters with stack top
    	for (size_t i = 0; i < s.length(); ++i) {
        	if (s[i] != tempStack.topElement()) {
            	return false;
        }
        tempStack.pop();
    }

    return true;
}
};
