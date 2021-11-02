#include <iostream>
using namespace std;

struct Matrix
{
    int A[10]; // For demo purpose, I'm taking fixed array. If n X n, then we need array of n space. 
    int n; // n X n matrix.
};

void set(struct Matrix *m, int i, int j, int x) {
    if(i == j) {
        m->A[i - 1] = x;
    }
}

int get(struct Matrix *m, int i, int j) {
    if(i == j) {
        return m->A[i - 1];
    } else {
        return 0;
    }
}

void display(struct Matrix *m) {
    int i, j;
    for (i=0; i<m->n; i++) {
        for(j=0; j<m->n; j++) {
            if(i == j) {
                cout<<m->A[i]<<" ";
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
    set(&m,1,1,5);
    set(&m,2,2,10);
    set(&m,3,3,15);
    set(&m,4,4,20);
    set(&m,5,5,25);
    display(&m);
    return 0;
}