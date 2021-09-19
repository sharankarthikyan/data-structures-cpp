#include<iostream>
using namespace std;

struct Rectangle {
    int length; 
    int breadth;
} r1, r2;

// struct Rectangle r3, r4;

int main() {
    // struct Rectangle r5, r6;
    
    r1 = {10, 5};
    printf("%lu\n", sizeof(r1));
    printf("%d\n", r1.length);
    cout<<r1.breadth<<endl;

    // We didn't initialize r2, so, lets check what that holds before initialization.
    cout<<r2.length<<" "<<r2.breadth<<endl; // 0 0
    
    return 0;
}


// The commented parts were different ways of declaring variable for structure.