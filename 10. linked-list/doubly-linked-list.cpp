#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
} *head;

void create(int A[], int n) {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head->prev = NULL;
    struct Node *tail = head;

    for(int i=1; i<n; i++) {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp; // OR: tail = tail->next;
    }
}

void display(struct Node *head) {
    if(head == NULL) {
        return;
    }

    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

struct Node* insertNodeBeg(struct Node *head, int x) {
    if(head == NULL) {
        return head;
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

void insertNodeBt(struct Node *head, int x, int pos) { // error will occur if you try to insert at begininng and end.
    if(head == NULL) {
        return;
    }

    int count = 0;
    while(count < pos && head != NULL) {
        count++;
        head = head->next;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
}

void insertNodeEnd(struct Node *head, int x) {
    if(head == NULL) {
        return;
    }

    while(head->next != NULL) {
        head = head->next;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = head;
    head->next = temp;
}

struct Node* delNodeBeg(struct Node *head) {
    if(head == NULL) {
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

void delNodeBt(struct Node *head, int pos) {
    if(head == NULL) {
        return;
    }

    int count = 0;
    while(count < pos) {
        count++;
        head = head->next;
    }
    struct Node *temp = head;
    head->prev->next = head->next;
    head->next->prev = temp->prev;
    head = head->next;
    delete temp;    
}

void delNodeEnd(struct Node *head) {
    if(head == NULL) {
        return;
    }

    while(head->next != NULL) {
        head = head->next;
    }

    head->prev->next = NULL;
    delete head;
}

int main() {

    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A)/sizeof(A[0]);
    
    create(A, n);
    display(head);

    head = insertNodeBeg(head, 5);
    display(head);

    insertNodeBt(head, 15, 2);
    display(head);

    insertNodeEnd(head, 60);
    display(head);

    head = delNodeBeg(head);
    display(head);

    delNodeBt(head, 1);
    display(head);

    delNodeEnd(head);
    display(head);

    return 0;
}