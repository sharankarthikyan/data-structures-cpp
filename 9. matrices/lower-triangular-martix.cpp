// Lower triangular matrix row major mapping.

//     | x 0 0 0 0 |
//     | x x 0 0 0 |
//     | x x x 0 0 |
//     | x x x x 0 |
//     | x x x x x |

#include <iostream>
using namespace std;

struct Matrix {
    int *A; // Taking pointer for an array.
    int n; // n X n Martix.
};

void set(struct Matrix *m, int i, int j, int x) {
    if((i >= j) && (i <= m->n)) {
        int index = ((i * (i - 1)) / 2) + j - 1; // Row major. ## IMPORTANT.
        m->A[index] = x;
    }
}

int get(struct Matrix *m, int i, int j) {
    if((i >= j) && (i <= m->n)) {
        int index = ((i * (i - 1)) / 2) + j - 1;
        return m->A[index];
    } else {
        return 0;
    }
}

void display(struct Matrix *m) {
    for(int i=1; i<=m->n; i++) {
        for(int j=1; j<=m->n; j++) {
            if((i >= j) && (i <= m->n)) {
                int index = ((i * (i - 1)) / 2) + j - 1;
                cout<<m->A[index]<<" ";
            } else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main() {

    struct Matrix m;
    cin>>m.n;

    int linearSpace = (m.n * (m.n+1)) / 2;
    m.A = (int *)malloc(linearSpace * sizeof(int));

    for(int i=1; i<=m.n; i++) {
        for(int j=1; j<=m.n; j++) {
            int x;
            cin>>x;
            set(&m, i, j, x);
        }
    }

    display(&m);

    cout<<endl<<get(&m, 1, 1);
    return 0;
}