#include <iostream>
using namespace std;

void TOH(int n, int source, int aux, int destination) {
    if(n > 0) {
        TOH(n - 1, source, destination, aux);
        printf("from %d to %d\n", source, destination);
        TOH(n - 1, aux, source, destination);
    }
}

int main() {
    TOH(3, 1, 2, 3);
    return 0;
}