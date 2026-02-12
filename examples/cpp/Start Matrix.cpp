#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of cols: ";
    cin>>n;
    for ( int i = 1; i < m; i++)
    {
        for (int  j = 1; j < n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
  
}
