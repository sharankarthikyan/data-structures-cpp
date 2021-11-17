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

bool isEmpty(struct Queue q) {
    if(q.front == q.rear) {
        return true;
    } else {
        return false;
    }
}

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(size * sizeof(struct Node));
}

void enqueue(struct Queue *q, struct Node *x) {
    if((q->rear + 1) % q->size == q->front) {
        cout<<"Queue is overflow"<<endl;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* dequeue(struct Queue *q) {
    struct Node *x = NULL;
    if(q->front == q->rear) {
        cout<<"Queue is Empty."<<endl;
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q) {
    for(int i=q->front+1; i<=q->rear; i++) {
        cout<<q->Q[i]<<endl;
    }
}

void create() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    cout<<"Enter root value: ";
    cin>>x;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)) {
        p = dequeue(&q);
        cout<<"Enter Left Child: ";
        cin>>x;
        if(x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout<<"Enter Right Child: ";
        cin>>x;
        if(x != -1) {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p) {
    if(p) {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {

    create();
    preorder(root);
    return 0;
}