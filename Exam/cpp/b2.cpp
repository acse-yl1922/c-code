#include <iostream>
#include <fstream>

using namespace std;

// Function to generate the first 100 Fibonacci numbers
void generateFibonacciSequence() {
    // Initialize the first two Fibonacci numbers
    unsigned long long fib1 = 0;
    unsigned long long fib2 = 1;
    //Note that we need to use unsigned long long to store the data
    
    // Open a file for output
    ofstream outfile("fibo.txt");

    // Write the first two Fibonacci numbers to the file
    outfile << fib1 << endl;
    outfile << fib2 << endl;

    // Compute the remaining Fibonacci numbers and write them to the file
    for (int i = 2; i < 100; i++) {
        unsigned long long fib = fib1 + fib2;
        outfile << fib << endl;
        fib1 = fib2;
        fib2 = fib;
    }

    // Close the file
    outfile.close();
}