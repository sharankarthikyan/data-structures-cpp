// Combination - Selection of items from a collection, such that the order of selection does not matter (unlike permutations). 
// Consider a collection - ABCDEFG
// Some combinations - ABC, BCD, CDE, etc,.  ---- But ---- ABC, BCA -> In this, changing the order or position of same items from a collection, this is not consider as a combination. This is consider as Permutation.


// Now, we can do this combination using Pascal's triangle. 
// Thier is an alternate approach, that is formula appraoch. But, That formula approach using factorial recurrsion only. So, I like use Pascal's.

#include <iostream>
using namespace std;

int pascalTriangleCombination(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    } else {
        return pascalTriangleCombination(n - 1, r - 1) + pascalTriangleCombination(n - 1, r);
    }
}

int main() {
    cout<<pascalTriangleCombination(2, 1);
    return 0;
}