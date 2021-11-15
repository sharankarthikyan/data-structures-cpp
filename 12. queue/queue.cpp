#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = temp;
    } else {
        rear->next = temp;
    } 
    rear = temp;
}

struct Node* dequeue() {
    if(front == NULL) {
        return NULL;
    }
    struct Node *temp = front;
    cout<<temp->data;
    front = front->next;
    delete temp;
    return front;
}

int main() {

    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        enqueue(x);
    }

    front = dequeue();
    front = dequeue();
    front = dequeue();
    front = dequeue();
    front = dequeue();
    front = dequeue();
   
    return 0;
}