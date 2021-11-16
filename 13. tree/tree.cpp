#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *lchild, *rchild;
} *root = NULL;

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q; // If 'Q' is array -> '*Q'. So, that array hold address of tree nodes -> '**Q'.
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(size * sizeof(struct Node));
}

void enqueue(struct Queue *q, int x) {

}

int main() {
    return 0;
}