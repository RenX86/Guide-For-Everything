#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int diagonal,left,above;

    cout<<"Enter the Diagonal,Left,Above value: "<<endl;
    cin>> diagonal>>left>>above;

    if (diagonal>left)
    {
        if (diagonal>above) cout << diagonal <<" is the max value";
        else cout << diagonal << " is the max value";
    }
    else
    {
        if (left>above) cout<<left<<"is the max value";
        else cout<<above<<" is the max value";
    }
return 0;
}
