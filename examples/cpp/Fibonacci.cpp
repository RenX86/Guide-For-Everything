#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Input the number of terms to generate in the Fibonacci series
    cout << "Enter the number of terms: ";
    cin >> n;

    // Initializing the first two terms of the Fibonacci series
    int first = 0, second = 1, next;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Print the current term
        cout << first << " ";

        // Calculate the next term
        next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
    return 0;
}
