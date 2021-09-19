// This is HORNER's RULE based Taylor series.

#include <iostream>
using namespace std;


double eOfX(int x, int n) {
    static double s;
    if(n == 0) {
        return s;
    }
    s = 1 + x * s / n;
    return eOfX(x, n - 1);
}


int main() {
    printf("%lf", eOfX(1,10));
    return 0;
}