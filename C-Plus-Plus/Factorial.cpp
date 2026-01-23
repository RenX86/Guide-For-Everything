#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    int n,f,i;

    cout << "Enter the number for: ";
    cin >> n;

    for ( i = 1, f=1; i <= n ; i++)
    {
        f*=i;
    }
    cout << "Factorials are: "<<f;

    return 0;
}

