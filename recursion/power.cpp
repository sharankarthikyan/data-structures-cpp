#include <iostream>
using namespace std;

// Approach 1:
int power1(int m, int n) {
    if(n == 0) {
        return 1;
    } else {
        return power1(m, n - 1) * m;
    }
}


// Approach 2: This is faster than above
int power2(int m, int n) {
    if(n == 0) {
        return 1;
    }

    if(n % 2 == 0) {
        return power2(m * m, n / 2);
    } else {
        return m * power2(m * m, (n - 1) / 2);
    }
}

int main() {
    cout<<power1(5, 3);
    return 0;
}