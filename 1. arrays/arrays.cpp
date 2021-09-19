#include <iostream>
using namespace std;

int main() {
   
    int arr1[5];
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;

    cout<<sizeof(arr1)<<endl;
    cout<<arr1[0]<<endl;

    printf("%d\n", arr1[1]);

    int arr2[5] = {2, 4, 6, 8, 10}; // This is correct syntax
    int arr3[] = {5, 10, 15, 20, 25}; // This is correct syntax

    int arr4[5] = {1, 2}; // We initialized to two indices in an array and the rest three will have a value of zero.

    cout<<arr4[3]<<endl;
    cout<<arr4[4]<<endl;

    cout<<"For loop 1\n";

    for(int i = 0; i < 5; i++) {
        cout<<arr2[i]<<" ";
    }

    cout<<endl<<"For loop 2\n";

    for(int x:arr2) {
        cout<<x<<" ";
    }

   return 0;
}