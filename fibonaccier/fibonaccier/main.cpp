#include <iostream>

uint64_t fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Enter a number greater than 1. " << std::endl;
    }

    std::cout << "Fibonacci number for the given number " << n << " is: " << fibonacci(n) << std::endl;

    return 0;
}