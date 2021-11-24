// Generate tree from traversal with InOrder and PreOrder.

#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *lchild, *rchild;
} *root = NULL;

struct TreeNode* createNode(struct TreeNode* node, int data) {
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

int searchInorder(int* inArray, int inStart, int inEnd, int data) {
    for(int i=inStart; i<=inEnd; i++) {
        if(inArray[i] == data) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* generateFromTraversal(int* inorder, int* preorder, int inStart, int inEnd) {
    static int preIndex = 0;

    if(inStart > inEnd) {
        return NULL;
    }

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node = createNode(node, preorder[preIndex++]);

    if(inStart == inEnd) {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

void preorderTra(struct TreeNode *root) {
    if(root) {
        cout<<root->data<<" ";
        preorderTra(root->lchild);
        preorderTra(root->rchild);
    }
}

int main() {
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    root = generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);

    preorderTra(root);

    return 0;
}