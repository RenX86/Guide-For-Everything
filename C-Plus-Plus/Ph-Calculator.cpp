#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float H,pH;
    cout<<"Enter H value: ";
    cin>>H;
    pH = -log10(H);
    if (H<=0) cout<<"Enter valid hydrogen concentration.";
    else cout<<"The pH of the solution is: "<<pH<<endl;

return 0;
}
