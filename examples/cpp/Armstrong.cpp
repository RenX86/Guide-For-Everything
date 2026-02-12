#include <iostream>
using namespace std;

int main(){
    int n,orn,r,sum = 0;

    cout << "Enter the number: ";
    cin >> n;
    orn = n;

    while (n != 0)
    {
        r = n%10;
        sum += r*r*r;
        n /= 10;
    }
    
    if (orn == sum) cout << "The number is Armstrong";
    else cout<< "Number the is not armstrong";

return 0;
}
