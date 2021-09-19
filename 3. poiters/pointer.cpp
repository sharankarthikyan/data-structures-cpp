#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {

    int a = 10;
    int *ptr = &a; // We have to use '*' infront of the variable which holds address of another variable. This is also a definition for POINTER.

    // If we put '&' infront of a variable that gives the address of that variable.

    // address of ptr(&ptr) ---- value at ptr(ptr) ---- value at ptr's address(*ptr)
    cout<<&ptr<<" "<<ptr<<" "<<*ptr<<endl;


    // An another way of declaring and initializing a pointer variable.
    int *ptr2;
    ptr2 = &a;


    int arr1[5] = {1,2,3,4,5};
    int *ptr3 = arr1; // We don't need to give '&' infront of array variable, The reason is an 'array itself holding an address of first element in an array'. 
    // If you want use '&', you can give LIKE THIS: int *ptr3 = &arr1[0];
    // int *ptr3 = &arr1; <-- This is an invalid syntax.

    for(int i=0; i<5; i++) { // *ptr[i] <-- This is invalid syntax.
        cout<<arr1[i]<<" "<<ptr3[i]<<endl;
    }

    cout<<endl;
    
    // Another way to create a array like above.
    int *ptr4;
    ptr4 = (int *)malloc(5 * sizeof(int)); 
    ptr4[0] = 20; ptr4[1] = 40; ptr4[2] = 60; ptr4[3] = 80; ptr4[4] = 100; 
    
    // We can also get user input like below.
    // for(int i=0; i<5; i++) { // *ptr[i] <-- This is invalid syntax.
    //     cin>>ptr4[i];
    // }
    for(int i=0; i<5; i++) { // *ptr[i] <-- This is invalid syntax.
        cout<<ptr4[i]<<endl;
    }

    cout<<endl;

    int *ptr5 = new int[5]; // cpp way of creating an array. This may cause memory leak. So, after using delete like this --> delete [] ptr5; In C lang, --> free(ptr);
    ptr5[0] = 100; ptr5[1] = 200; ptr5[2] = 300; ptr5[3] = 400; ptr5[4] = 500; 
    for(int i=0; i<5; i++) { // *ptr[i] <-- This is invalid syntax.
        cout<<ptr5[i]<<endl;
    }

    cout<<endl;

    /* ------ Intersting thing about POINTER ------ */

    /* ------ SIZE OF POINTER IS ALWAYS THE SAME ------ */

    // SIZE of the POINTER is INDEPENDENT of DATATYPE of the POINTER. Old x64 machine compiler takes 4 byte for pointer, But new x64 machine compiler takes 8 bytes. 

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;

    return 0;
}