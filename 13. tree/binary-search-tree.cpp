#include <iostream>
using namespace std;

struct TreeNode {
    struct TreeNode *lchild, *rchild;
    int data;
} *root = NULL;

void insert(int key) {
    struct TreeNode *t = root;
    struct TreeNode *r, *p;

    if(root == NULL) {
        p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while(t != NULL) {
        r = t;
        if(key < t->data) {
            t = t->lchild;
        } else if(key > t->data) {
            t = t->rchild;
        } else {
            return;
        }
    }

    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if(key < r->data) {
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

void inorder(struct TreeNode *root) {
    if(root) {
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
    cout<<" ";
}

struct TreeNode* search(int key) {
    struct TreeNode *t = root;

    while(t) {
        if(key == t->data) {
            return t;
        } else if(key > t->data) {
            t = t->rchild;
        } else {
            t = t->lchild;
        }
    }
    return NULL;
}

// Height of a tree.
int height(struct TreeNode *root) {
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

struct TreeNode *inPre(struct TreeNode *p) {
    while(p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

struct TreeNode *inSucc(struct TreeNode *p) {
    while(p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

struct TreeNode * Delete(struct TreeNode *p, int key) {

    struct TreeNode *q;

    if(p == NULL) {
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL) {
        if(p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if(key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if(key > p->data) {
        p->rchild = Delete(p->rchild, key);
    } else {
        if(height(p->lchild) > height(p->rchild)) {
            q = inPre(p->lchild);// Inorder precedor.
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = inSucc(p->rchild);// Inorder successor.
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main() {
    int n;
    cout<<"Enter no. of nodes in a tree: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        int val;
        cout<<"Enter the data: ";
        cin>>val;
        insert(val);
    }

    Delete(root, 10);

    inorder(root);

    struct TreeNode *found = search(6);
    if(found) {
        cout<<"\nElement found: "<<found->data;
    } else {
        cout<<"\nElement Not found.";
    }
}