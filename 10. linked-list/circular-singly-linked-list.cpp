// I have written a very few functions for CSLL. Reason: This is same as SLL, there we will check for NULL, here we check for head's address.

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void create(int A[], int n) {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    struct Node *tail = head;

    for(int i=1; i<n; i++) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
}

void display(struct Node *ptr1) {
    if(ptr1 == NULL) {
        return;
    }

    struct Node *ptr2 = ptr1;
    do {
        cout<<ptr2->data<<" ";
        ptr2 = ptr2->next;
    }while(ptr2 != ptr1);

    cout<<endl;
}

int main() {
    int A[] = {5, 10, 15, 20, 25};
    int n = sizeof(A)/sizeof(A[0]);
    
    create(A, n);
    display(head);
    return 0;
}