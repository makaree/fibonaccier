# Fibonaccier
Read positive (>0) number n (from stdin or cmdline). Make 2 asynchronous/concurrent calls to a function fib(...) which <br>
 a) includes a random delay of up to 1 second <br>
 b) calculates and returns the fibonacci number calculate using the following recursive formula: <br>
    Fib(0) = 0 <br>
    Fib(1) = 1 <br>
    Fib(n) = Fib(n-1) + Fib(n-2) <br>
 Waits until both of the asynchronous calls finish. <br>

**Proposed solution prints out the resulting Fibonacci number Fib(n), its sleep time in ms and the order in which the thread was executed.**<br>

## How to use
Open the **fibonaccier/x64/Debug/fibonaccier.exe** file and run the executable. Follow the instruction from the executable to see the output.

## Source Code
All the source code is in single file in **fibonaccier/fibonaccier/main.cpp**.
