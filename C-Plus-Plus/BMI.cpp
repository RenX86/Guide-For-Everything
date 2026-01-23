#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double w,h,bmi;
    cout<<"Enter weight in kg: ";
    cin>> w;
    cout<<"Enter Height in M: ";
    cin>> h;
    if (h>0 && w>0)
    {
        bmi = w/(h*h);
        cout<<"Your BMI is: "<<bmi;
    }
    else cout<< "Enter Valid weight and height.";
return 0;
}
