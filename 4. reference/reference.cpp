// Reference in available only on C++
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int &r = a; // '&' before the variable name is a reference variable for the variable to be initialised. 
    // Now, Both 'a = r = 10'.
    // Reference variable must be initialised. If just declared but not initialised, then that will throw an error.
    // If we change the value of 'r' then, value 'a' is also gets affected and vice versa.
    cout<<a<<" "<<r<<" "<<&a<<" "<<&r<<endl; // a and r were pointing to same address but variable name was different.
}