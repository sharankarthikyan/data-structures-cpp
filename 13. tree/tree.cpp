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
        q->front = (q->front+1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue *q) {
    for(int i=q->front+1; i<=q->rear; i++) {
        cout<<q->Q[i]<<endl;
    }
}

int sum(struct Node *root) {
    int x, y;
    if(root) {
        x = sum(root->lchild);
        y = sum(root->rchild);
        return x + y + root->data;
    }
    return 0;
}

// Here count follows post order.
int count(struct Node *root) {
    int x, y;
    if(root) {
        x = count(root->lchild);
        y = count(root->rchild);
        return x + y + 1;
    }
    return 0;
}

// Single line count.
// int count(struct Node *root) {
//     if(root) {
//         return count(root->lchild) + count(root->rchild) + 1;
//     }
//     return 0;
// }

// Height of a tree.
int height(struct Node *root) {
    int x = 0, y = 0;
    if(root == NULL) {
        return 0;
    }

    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y) {
        return x + 1;
    } else {
        return y + 1;
    }
}

int countLeaf(struct Node *root) {
    int x, y;

    if(root) {
        x = countLeaf(root->lchild);
        y = countLeaf(root->rchild);
        if(!root->lchild && !root->rchild) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int nodeWithDeg2(struct Node *root) {
    int x, y;
    if(root) {
        x = nodeWithDeg2(root->lchild);
        y = nodeWithDeg2(root->rchild);
        if(root->lchild && root->rchild) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int nodeWithDeg1(struct Node *root) {
    int x, y;
    if(root) {
        x = nodeWithDeg1(root->lchild);
        y = nodeWithDeg1(root->rchild);
        if(root->lchild != NULL ^ root->rchild != NULL) { // Bitwise XOR: TT - F, FF - F, TF - T, FT - T.
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}

int nodeWithDeg1Or2(struct Node *root) {
    int x, y;
    if(root) {
        x = nodeWithDeg1Or2(root->lchild);
        y = nodeWithDeg1Or2(root->rchild);
        if(root->lchild || root->rchild) {
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
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

void inorder(struct Node *p) {
    if(p) {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p) {
    if(p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}


int main() {
    create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Sum: "<<sum(root)<<endl;
    cout<<"Count: "<<count(root)<<endl;
    cout<<"Height: "<<height(root)<<endl;
    cout<<"Count Leaf: "<<countLeaf(root)<<endl;
    cout<<"Deg 2 Nodes: "<<nodeWithDeg2(root)<<endl;
    cout<<"Deg 1 Nodes: "<<nodeWithDeg1(root)<<endl;
    cout<<"Deg 1 or 2 Nodes: "<<nodeWithDeg1Or2(root)<<endl;
    return 0;
}