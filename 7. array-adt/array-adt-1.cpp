#include <iostream>
using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("Elements are\n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    cout<<endl;
}

void Append(struct Array *arr, int x) {
    if(arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x) {
    if(index >= 0 && index <= arr->length) {
        for(int i=arr->length; i>index; i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) {
    int x = arr->A[index];
    if(index >= 0 && index <= arr->length) {
        for(int i=index; i<arr->length-1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    return x;
}

int LinearSearch(struct Array *arr, int val) {
    for(int i=0; i<arr->length; i++) {
        if(val == arr->A[i]) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int val) {
    int l = 0, h = arr->length, mid;
    while(l <= h) {
        mid = (l + h)/2;
        if(arr->A[mid] == val) {
            return mid;
        } else if(arr->A[mid] > val) {
            h = mid - 1;
        } else if(arr->A[mid] < val) {
            l = mid + 1;
        }
    }
    return -1;
}

int RecBinarySearch(int a[], int l, int h, int val) {
    if(l <= h) {
        int mid = (l + h)/2;
        if(a[mid] == val) {
            return mid;
        } else if(a[mid] > val){
            return RecBinarySearch(a, l, mid - 1, val);
        } else {
            return RecBinarySearch(a, mid + 1, h, val);
        }
    }
    return -1;
}

int Get(struct Array *arr, int index) {
    if(index >= 0 && index < arr->length) {
        return arr->A[index];
    }
    return -1; 
}

void Set(struct Array *arr, int val, int index) {
    if(index >= 0 && index < arr->length) {
        arr->A[index] = val;
    }
}

int Max(struct Array *arr) {
    int max = arr->A[0];
    for(int i=1; i<arr->length; i++) {
        if(arr->A[i] > max) {
            max = arr->A[i];
        }
    }
    return max;
}

float Avg(struct Array *arr) {
    float avg = 0;
    for(int i=0; i<arr->length; i++) {
        avg += arr->A[i];
    }
    avg = avg/arr->length;
    return avg;
}

int main() {
    struct Array arr;
    printf("Enter size of an array ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    cout<<arr.A;
    arr.length = 0;

    printf("Enter n ");
    scanf("%d", &arr.length);
    for(int i=0; i<arr.length;i++) {
        scanf("%d", &arr.A[i]);
    }
    
    Display(arr);

    Append(&arr, 10);
    Insert(&arr, 2, 15);
    Display(arr);
    cout<<"Del: "<<Delete(&arr, 2)<<endl;
    Display(arr);

    cout<<"BS: "<<BinarySearch(&arr, 5)<<endl;
    cout<<"Recursion BS: "<<RecBinarySearch(arr.A, 0, 5, 5)<<endl;
    cout<<"Get: "<<Get(&arr, 4)<<endl;
    Set(&arr, 100, 1);
    Display(arr);

    cout<<"Max: "<<Max(&arr)<<endl;
    cout<<"Avg: "<<Avg(&arr)<<endl;
    return 0;
}