#include <iostream>
using namespace std;

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

struct Node* push(struct Node *p, char ch) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = ch;
    temp->next = p;
    p = temp;
    return p;
}

struct Node* pop(struct Node *p) {
    if(p == NULL) {
        return NULL;
    }
    struct Node *temp = p;
    p = p->next;
    delete temp;
    return p;
}

char peek(struct Node *p) {
    if(p != NULL)
        return p->data;
    else 
        return 0;
}

bool isOperand(char ch) {
    if(ch == '-' || ch == '+' || ch == '*' || ch == '/') {
        return false;
    } else {
        return true;
    }
}

int precedence(char ch) {
    if(ch == '+' || ch == '-') {
        return 1;
    } else if(ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

int main() {

    string str;
    cin>>str;

    for(int i=0; str[i] != '\0'; i++) {
        if(!isOperand(str[i])) {
            if(precedence(str[i]) > precedence(peek(top))) {
                top = push(top, str[i]);
            } else {
                cout<<peek(top);
                top = pop(top);
                while(precedence(str[i]) == precedence(peek(top))) {
                    cout<<peek(top);
                    top = pop(top);
                }
                top = push(top, str[i]);
            }
        } else {
            cout<<str[i];
        }
    }

    while(top != NULL) {
        cout<<peek(top);
        top = pop(top);
    }

    return 0;
}