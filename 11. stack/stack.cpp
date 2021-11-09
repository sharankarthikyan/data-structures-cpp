// Stack using Linked List.

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

struct Node* push(struct Node *top, int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
    return top;    
}

struct Node* pop(struct Node *top) {
    if(top == NULL) {
        return NULL;
    }
    struct Node *temp = top;
    top = top->next;
    delete temp;
    return top;
}

int peek(struct Node *top) {
    if(top != NULL) {
        return top->data;
    } else {
        return -1;
    }
}

void display(struct Node *top) {
    while(top != NULL) {
        cout<<top->data<<" ";
        top = top->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    int n;
    do {
        cout<<"0. Push"<<endl;
        cout<<"1. Pop"<<endl;
        cout<<"2. Peek"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"-1. Exit"<<endl;
        cout<<"Enter No.: ";
        cin>>n;
        switch (n)
        {
            case 0:
                cout<<"Enter the data: ";
                int data;
                cin>>data;
                top = push(top, data);
                break;
            case 1:
                top = pop(top);
                break;
            case 2:
                cout<<"Peeked: "<<peek(top)<<endl;
                break;
            case 3:
                cout<<"Displayed: ";
                display(top);
                break;
        }
    } while(n != -1);

    return 0;
}