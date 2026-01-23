#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a,t,g,c;
    int purines,pyrimidines;

    cout<<"Enter the A,T,G,C count: "<<endl;
    cin>>a>>t>>g>>c;

    if (a - t == 0) {
        purines = a + g;
        pyrimidines = t + c;
        cout<< "Purines: "<<purines<<endl;
        cout<< "Pyrimidinies: "<<pyrimidines<<endl;
    }
    else cout<<"Enter valid input";
return 0;
}
