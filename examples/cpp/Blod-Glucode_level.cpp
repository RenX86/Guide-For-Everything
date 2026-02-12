#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int glucose_level;

    cout<<"Enter the glucose level: ";
    cin>>glucose_level;

    if (glucose_level <70) cout<<"You have Hypoglycemia";
    else if (glucose_level <=180) cout<<"You have Hyperghlycemia";
    else cout<<"You have diabetes"; 
return 0;
}
