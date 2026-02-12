#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m,n;

    cout <<"Enter the rows(m): ";
    cin >>m;
    cout << "Enter the columns: ";
    cin >>n;

    int matrix[m][n];

    cout <<"Enter the elements of matrix: "<<endl;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];        
        }
        
    }
    cout << "Original Matrix: "<<endl;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j]<<" ";
        }
        cout <<" "<<endl;
    }
    cout <<"Transpose matrix: "<<endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[j][i]<<" ";
        }
        cout <<" "<< endl;
    }
    
    return 0;
}
