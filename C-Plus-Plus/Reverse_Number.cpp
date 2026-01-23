#include <iostream>
using namespace std;

int main() {
    int num, reversedNumber = 0, remainder;

    // Ask the user for input
    cout << "Enter a number: ";
    cin >> num;

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;          // Extract the last digit
        reversedNumber = reversedNumber * 10 + remainder; // Build the reversed number
        num /= 10;                      // Remove the last digit from the number
    }

    // Output the reversed number
    cout << "Reversed Number: " << reversedNumber << endl;

    return 0;
}
