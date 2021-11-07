// Upper triangular matrix column major mapping.

// | x x x x x
// | 0 x x x x
// | 0 0 x x x
// | 0 0 0 x x
// | 0 0 0 0 x

#include <iostream>
using namespace std;

struct Matrix {
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x) {
    if(i <= j && j <= m->n) {
        int index = j*(j-1)/2+i-1;
        // cout<<index<<endl;
        m->A[index] = x;
    }
}

void display(struct Matrix *m) {
    for(int i=1; i<=m->n; i++) {
        for(int j=1; j<=m->n; j++) {
            if(i <= j) {
                cout<<m->A[j*(j-1)/2+i-1]<<" ";
            } else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main() {

    struct Matrix m;
    m.n = 5;

    int linearSpace = m.n*(m.n+1)/2;
    m.A = (int *)malloc(linearSpace * sizeof(int));

    set(&m, 1, 1, 1);
    set(&m, 1, 2, 2);
    set(&m, 1, 3, 3);
    set(&m, 1, 4, 4);
    set(&m, 1, 5, 5);
    set(&m, 2, 2, 6);
    set(&m, 2, 3, 7);
    set(&m, 2, 4, 8);
    set(&m, 2, 5, 9);
    set(&m, 3, 3, 10);
    set(&m, 3, 4, 11);  
    set(&m, 3, 5, 12);
    set(&m, 4, 4, 13);
    set(&m, 4, 5, 14);
    set(&m, 5, 5, 15);

    display(&m);
    cout<<endl;
    // cout<<get(&m, 3, 3);

    return 0;
}