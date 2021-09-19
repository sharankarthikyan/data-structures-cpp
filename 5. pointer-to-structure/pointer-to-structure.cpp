#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle {
    int length; // int - 4 bytes
    int breadth;
};

int main() {

    struct Rectangle r = {10, 5};
    // Rectangle r = {10, 5} // This is another way of declaring a struct variable.
    cout<<r.length<<" "<<r.breadth<<endl;
    r.length = 15;
    cout<<r.length<<endl;

    struct Rectangle *rptr = &r;
    // rptr just holds the address of r. So, we are not able to access r's values by rptr.length.
    // We can access the r's value by using '*'. 
    // This is not correct: *rptr.length = 100; ------ The reason is '.' has high precedance than '*'.
    // So, we need enclose with paranthesis.
    // This is correct: (*ptr).length = 100; // This is so hard syntax.
    // So, C lang gives a convinient way to access data. The arrow '->' 
    rptr -> length = 100;
    cout<<r.length<<endl;
    cout<<rptr -> length<<" "<< rptr -> breadth<<endl;
   
    cout<<sizeof(struct Rectangle)<<endl;
    
    Rectangle *ptr1;
    ptr1 = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // If you ignore struct keyword, then also it works fine.
    ptr1->length = 1;
    ptr1->breadth = 2;
    cout<<ptr1->length<<" "<<ptr1->breadth<<endl;

    // In C++, we can also declare like below
    Rectangle *ptr2;
    ptr2 = new Rectangle;
    ptr2->length = 5;
    ptr2->breadth = 10;
    cout<<ptr2->length<<" "<<ptr2->breadth<<endl;

    return 0;
}