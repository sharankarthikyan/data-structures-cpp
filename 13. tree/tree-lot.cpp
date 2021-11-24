// Tree using Level Order Traversal (LOT).
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} *root = NULL;

struct Queue {
    int size;
    int front;
    int rear;
    struct TreeNode **Q;
};

void createQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct TreeNode **)malloc(size * sizeof(struct TreeNode));
}

bool isEmpty(struct Queue *q) {
    if (q->front == q->rear) {
        return true;
    } else {
        return false;
    }
}

void enqueue(struct Queue *q, struct TreeNode *x) {
    if((q->rear+1) % q->size == q->front) {
        cout<<"Queue is Overflow."<<endl;
    } else {
        q->rear = (q->rear+1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct TreeNode* dequeue(struct Queue *q) {
    struct TreeNode *x = NULL;
    if(q->front == q->rear) {
        cout<<"Queue is Empty."<<endl;
    } else {
        q->front = (q->front+1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void create() {
    struct Queue q;
    createQueue(&q, 100);
    struct TreeNode *p, *t;
    int x;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    cout<<"Enter root data: ";
    cin>>x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(&q)) {
        p = dequeue(&q);

        cout<<"Enter the left child: ";
        cin>>x;
        if(x != -1) {
            t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout<<"Enter the right child: ";
        cin>>x;
        if(x != -1) {
            t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void LOT() {
    if(root == NULL) {
        cout<<"Tree is empty."<<endl;
        return;
    }

    struct Queue q2;
    createQueue(&q2, 100);

    cout<<root->data<<" ";
    enqueue(&q2, root);
    struct TreeNode *p, *t;

    while(!isEmpty(&q2)) {
        p = dequeue(&q2);

        if(p->lchild != NULL) {
            cout<<p->lchild->data<<" ";
            enqueue(&q2, p->lchild);
        }

        if(p->rchild != NULL) {
            cout<<p->rchild->data<<" ";
            enqueue(&q2, p->rchild);
        }
    }
}

int main() {

    create();
    LOT();
    return 0;
}