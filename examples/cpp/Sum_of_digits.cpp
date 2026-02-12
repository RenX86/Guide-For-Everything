#include <iostream>
using namespace std;

int main(){
    int n, son = 0, remainder;

    cout << "Enter the number: ";
    cin >> n;

    while (n !=0)
    {
        remainder = n % 10;
        son += remainder;
        n /= 10;
    }

    cout << "sum of digits: " << son << endl;

    return 0;
}