#include <iostream>
#include <thread>

/*
This function calculates the value of fibonacci series for given number n using recursive function.
*/
uint64_t fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

/*
This function inserts a random delay between 0 and 1 seconds then calcuates the fibonacci series for given number n.
*/
int random_delay_in_fibonacci(int n, char c) {
    uint64_t result = fibonacci(n);
    // add delay part later
    std::cout << "fibonacci(" << n << ") = " << result << " and execution is for character " << c << " \n";  
    return result;
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Enter a number greater than 1. " << std::endl;
    }

    //Define two threads for async calls
    std::thread thread1(random_delay_in_fibonacci, n, '*');
    std::thread thread2(random_delay_in_fibonacci, n, '$');

    // Wait for both threads to finish
    thread1.join();
    thread2.join();

    std::cout << "Fibonacci number for the given number " << n << " is: " << fibonacci(n) << std::endl;

    return 0;
}