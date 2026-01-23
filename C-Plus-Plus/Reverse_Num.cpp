#include <iostream>
using namespace std;

int main(){
    
    int num, rev ,remainder;

    cout << "Enter a number to reverse: ";
    cin >> num;

    while (num !=0)
    {
        remainder = num%10;
        rev *= 10;
        rev += remainder;
        num /= 10;

    }

    cout << "Reverse number: " << rev << endl;
}
