#include <chrono>
#include <iostream>
#include <random>
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
This function generates a random delay in between 0 to 1000 milliseconds.
*/
int generate_delay() {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);  // Random delay up to 1000 milliseconds
    return dis(gen);
}

/*
This function inserts a random delay between 0 and 1 seconds then calcuates the fibonacci series for given number n.
*/
int random_delay_in_fibonacci(int n, char c) {
    int sleep_time = generate_delay();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
    uint64_t result = fibonacci(n);
    std::cout << "The sleep time is " << sleep_time << ", the result is " << result << " and for thread with character " << c << " \n";  
    return result;
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    // Check to input number greater than 1
    if (n <= 1) {
        std::cout << "Enter a number greater than 1. " << std::endl;
    }

    // Define two threads for async calls
    std::thread thread1(random_delay_in_fibonacci, n, '*');
    std::thread thread2(random_delay_in_fibonacci, n, '$');

    // Wait for both threads to finish
    thread1.join();
    thread2.join();
    
    std::cout << "Fibonacci number " << n << " value is " << fibonacci(n) << std::endl;
    
    // Check which thread was finished first
    if (!thread1.joinable() && thread2.joinable())
        std::cout << "Thread 1 is finished first.\n";
    else if (thread1.joinable() && !thread2.joinable())
        std::cout << "Thread 2 is finished first.\n";
    else if (!thread1.joinable() && !thread2.joinable())
        std::cout << "Both threads are finished simultaneously.\n";
    else
        std::cout << "Both threads not finished.\n";
    system("pause");
    return 0;
}