#include <iostream>
using namespace std;

// Local variable n
int fun1(int n) {
    if(n > 0) {
        return fun1(n - 1) + n; // This '+ n' will be considered on returning time of recursion. So, '+ n' will not be added at the calling time.
    }
    return 0;
}

// Static variable x
int fun2(int n) {
    static int x = 0;
    if(n > 0) {
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}

// Global variable y
int y = 0;
int fun3(int n) {
    if(n > 0) {
        y++;
        return fun3(n - 1) + y;
    }
    return 0;
}

int main() {
    int r;
    r = fun1(5);
    cout<<r<<endl;

    r = fun2(5);
    cout<<r<<endl;

    r = fun3(5);
    cout<<r<<endl;

    return 0;
}