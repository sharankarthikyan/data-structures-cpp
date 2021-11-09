// I have written a very few functions for CDLL. Reason: This is same as DLL, there we will check for NULL, here we check for head's address.

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
} *head;

void create(int A[], int n) {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->prev = head;
    head->next = head;

    struct Node *tail = head;
    for(int i=1; i<n; i++) {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->prev = tail;
        temp->next = head;
        tail->next = temp;
        tail = tail->next;
    }
}

void display(struct Node *head) {
    struct Node *ptr = head;
    do {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }while(ptr != head);
}

int main() {

    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/sizeof(A[0]);

    create(A, n);
    display(head);

    return 0;
}