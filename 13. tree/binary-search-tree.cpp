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
    cout<<endl;
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

    inorder(root);

    struct TreeNode *found = search(6);
    if(found) {
        cout<<"Element found: "<<found->data;
    } else {
        cout<<"Element Not found.";
    }
}