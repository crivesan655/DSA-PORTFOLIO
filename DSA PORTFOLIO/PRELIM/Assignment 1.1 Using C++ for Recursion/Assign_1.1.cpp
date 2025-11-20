#include <iostream>

int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n; 
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciNonRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, nextTerm;

    for (int i = 2; i <= n; ++i) {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    return b;
}

int main() {
    int n = 20; // this can be changed

    // this will output the fibonacci number
    std::cout << "Fibonacci number at position " << n << " (recursive): " << fibonacciRecursive(n) << std::endl;

    std::cout << "Fibonacci number at position " << n << " (non-recursive): " << fibonacciNonRecursive(n) << std::endl;

    return 0;
}