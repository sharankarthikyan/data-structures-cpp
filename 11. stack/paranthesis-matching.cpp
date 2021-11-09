#include <iostream>
using namespace std;

struct Node {
    char ch;
    struct Node *next;
} *top = NULL;

bool isEmpty(struct Node *top) {
    if(top == NULL) {
        return true;
    } else {
        return false;
    }
}

struct Node* push(struct Node *top, char x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = x;
    temp->next = top;
    top = temp;
    return top;    
}

struct Node* pop(struct Node *top) {
    if(isEmpty(top)) {
        return NULL;
    }
    struct Node *temp = top;
    top = top->next;
    delete temp;
    return top;
}

int peek(struct Node *top) {
    if(!isEmpty(top)) {
        return top->ch;
    } else {
        return -1;
    }
}

int main() {

    string str;
    cin>>str;
    bool isBalanced = true;

    for (int i=0; str[i] != '\0'; i++) {
        if(str[i] == '(') {
            top = push(top, str[i]);
        } else if (str[i] == ')') {
            if(top == NULL) {
                isBalanced= false;
                break;
            }
            
            if(peek(top) == '(') {
                top = pop(top);
            } else {
                isBalanced = false;
                break;
            }
        }
    }

    if(top != NULL) {
        isBalanced = false;
    }

    if(isBalanced) {
        cout<<"Balanced";
    } else {
        cout<<"Not Balanced";
    }
    return 0;
}