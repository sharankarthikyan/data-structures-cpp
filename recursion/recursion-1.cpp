// A function calling by itself is a recursion.
// Recursion has two pharse 1. Calling and 2. Returning.
// Calling pharse is statement gets executed before a function call by itself gets execute.
// Returning pharse is after all the function call by itself gets executed, If we have some statement after that call now that will execute.

// Diff btw loops and recursion: loops doesn't have two pharse. It just have one pharse - calling pharse.
// But, recursion has two pharse: calling and returing.


// Types of Recursion
/* 
    1. Tail Recursion: In this, function call by itself done after all statement gets executed. So, while returning pharse there must be no statement to execute.
    2. Head Recursion: In this, function call by itself done before all statement gets executed. So, while calling pharse there must be no statement to execute.
    3. Tree Recursion
    4. Indirect Recursion
    5. Nested Recursion.
*/

#include <iostream>
using namespace std;

// This function is example of Tail Recursion.
void fun1(int n) {
    if(n > 0) {
        printf("%d", n);
        fun1(n - 1); // In this line we make recursive call. There is no statement after this. So, there is no statement to execute in returning pharse.
    }
}

// This is an example of Head Recursion
void fun2(int n) {
    if(n > 0) {
        fun2(n - 1);// In this line we make recursive call. There is no statement above this. So, there is no statement to execute in calling pharse.
        printf("%d", n);
    }
}

int main() {
    fun1(3);
    cout<<endl;
    fun2(3);
    return 0;
}