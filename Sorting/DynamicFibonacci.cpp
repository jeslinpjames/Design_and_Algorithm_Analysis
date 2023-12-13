#include<iostream>

using namespace std;

long  dynamicFibonacci(int n) {
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    long prev = 0;
    long  current = 1;

    for (int i = 2; i <= n; ++i) {
        long next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative integer." << endl;
        return 1; // Exit with an error code
    }

    cout << "The Fibonacci series up to n is: ";
    for (int i = 0; i <= n; ++i) {
        cout << dynamicFibonacci(i) << " ";
    }

    cout << endl;

    return 0;
}
