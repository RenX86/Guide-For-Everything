#include <iostream>
using namespace std;

// Function to determine the maximum value among three values
int findMax(int a, int b, int c) {
    // Compare the values and return the largest one
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    // Variables to hold the scores
    int diagonal, left, above;

    // Input scores
    cout << "Enter the diagonal score: ";
    cin >> diagonal;
    
    cout << "Enter the left score: ";
    cin >> left;
    
    cout << "Enter the above score: ";
    cin >> above;

    // Find the maximum value
    int maxScore = findMax(diagonal, left, above);

    // Output the maximum value
    cout << "The maximum score among diagonal, left, and above is: " << maxScore << endl;

    return 0;
}
