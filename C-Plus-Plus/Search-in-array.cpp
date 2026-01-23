#include <iostream>
using namespace std;

int searchElement(const int arr[], int size, int target){
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main(){
    int n, target;

    cout <<"Enter the number of elements of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" <<endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    
    cout << "Enter the element you want to search array: ";
    cin >> target;

    int index = searchElement(arr,n,target);

    if (index != -1) cout << "Element found at index: " << index << endl;
    else cout << "Element not found in the array." << endl;

    return 0;
}