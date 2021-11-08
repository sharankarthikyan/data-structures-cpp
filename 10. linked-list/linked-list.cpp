#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first=NULL;

void create(int A[], int n) {
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

struct Node * insertNodeBeg(struct Node *p, int x) {
    if(p == NULL) {
        return p;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = p;
    p = temp;
    return p;
}

void insertNodeEnd(struct Node *p, int x) {
    if(p == NULL) {
        return;
    }

    while(p->next != NULL) {
        p = p->next;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    p->next = temp;
}

void insertNodeBt(struct Node *p, int x, int pos) { // Function for inserting a node in between. pos is index. 
    if(p == NULL) {
        return;
    }

    int count = 0;
    while(p != NULL) {
        if(count < pos-1) {
            count++;
            p = p->next;
        } else {
            break;
        }
    }

    if(p == NULL) {
        return;
    }
    
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

struct Node* deleteNodeBeg(struct Node *p) {
    if(p == NULL) {
        return p;
    }

    struct Node *temp = p;
    p = p->next;
    delete temp;
    return p;
}

void deleteNodeEnd(struct Node *p) {
    if(p == NULL) {
        return;
    }

    while(p->next->next != NULL) {
        p = p->next;
    }
    
    delete p->next;
    p->next = NULL;
}

void deleteNodeBt(struct Node *p, int pos) {
    if(p == NULL) {
        return;
    }

    int count = 0;
    while(p != NULL) {
        if(count < pos - 1) {
            count++;
            p = p->next;
        } else {
            break;
        }
    }

    struct Node *temp = p->next;
    p->next = temp->next;
    delete temp;
}


void display(struct Node *p) {
    while(p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int nodeCount(struct Node *p) {
    if(p == NULL) {
        return 0;
    }

    int count = 0;
    while(p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int sumOfNodesData(struct Node *p) {
    if(p == NULL) {
        return 0;
    }

    int sum = 0;
    while(p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int maxEle(struct Node *p) {
    if(p == NULL) {
        return INT32_MIN;
    }

    int max = p->data;
    p = p->next;
    while(p != NULL) {
        if(p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}


int linearSearch(struct Node *p, int val) {
    if(p == NULL) {
        return -1;
    }

    int pos = 0;
    while(p != NULL) {
        if(p->data == val) {
            return pos;
        }
        pos++;
        p = p->next;
    }
    return -1;
}

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Selection sort.
void sort(struct Node *ptr1) {
    if(ptr1 == NULL) {
        return;
    }

    struct Node *ptr2 = ptr1;
    while(ptr1 != NULL) {
        ptr2 = ptr1->next;
        struct Node *minAdd = ptr1;
        while(ptr2 != NULL) {
            if(minAdd->data > ptr2->data) {
                minAdd = ptr2;
            }
            ptr2 = ptr2->next;
        }
        swap(&ptr1->data, &minAdd->data);
        ptr1 = ptr1->next;
    }
}


int main() {

    int A[] = {3, 1, 6, 5, 10};
    int n = sizeof(A)/sizeof(A[0]);

    create(A, n);
    display(first);
    cout<<nodeCount(first);
    cout<<endl<<sumOfNodesData(first);
    cout<<endl<<maxEle(first);
    cout<<endl<<linearSearch(first, 6)<<endl;
    sort(first);
    display(first);

    insertNodeBt(first, 100, 2);
    cout<<endl;
    display(first);

    first = insertNodeBeg(first, 50);
    display(first);
    
    insertNodeEnd(first, 45);
    display(first);

    first = deleteNodeBeg(first);
    display(first);

    deleteNodeEnd(first);
    display(first);

    deleteNodeBt(first, 2);
    display(first);

    return 0;
}