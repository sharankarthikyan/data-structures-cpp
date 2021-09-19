#include <iostream>
using namespace std;

// Approach 1: Here we use 2 variables.
int sum = 0;
int sumOfnNaturalNumbers1(int n) {
    if(n <= 0) {
        return sum;
    } else {
        sum += n;
        sumOfnNaturalNumbers1(n - 1);
    }
}


// Approach 2: Here we actualy don't need sum variable. This is space efficient.
int sumOfnNaturalNumbers2(int n) {
    if(n == 0) {
        return 0;
    } else {
        return sumOfnNaturalNumbers2(n - 1) + n;
    }
}

int main() {
    cout<<sumOfnNaturalNumbers1(10)<<endl;
    cout<<sumOfnNaturalNumbers2(10);
    return 0;
}