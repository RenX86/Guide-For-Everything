#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& sequence){
    int n = sequence.size();
    for (int i = 0; i < n/2; ++i)
    {
        if (sequence[i] != sequence[n - i - 1]) 
        {
            return false;
        }
    }
    return true;
}

int main(){
    string sequence;

    cout << "Enter the sequnce: ";
    cin >> sequence;

    transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);

    if (isPalindrome(sequence)) cout << "The given seq. is Palindrome";
    else cout << "The given seq. is not palindrome";

    return 0;
    
}