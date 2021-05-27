// Heap is array representation of complete binary tree.
// Max heapify is the method to maintain teh property of max heap.

#include<stdio.h>

void max_heapify(int a[], int n, int index); //declarartion of max_heapify.
void print(int a[], int n);

int main(void) {
    int n; //size of the heap.
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) //input of heap.
        scanf("%d", &a[i]);
    int index = 1;
    max_heapify(a, n, index); //calling of max-heap.

    print(a, n);
    return 0;
}
void print(int a[], int n){
    for (int i = 0; i < n; i++) //printing all the elements of max-heap.
        printf("%d, ", a[i]);
}

void max_heapify(int a[], int n, int index) {
    int largest;
    int left = 2*index + 1;
    int right = 2*index + 2;
    printf("root = %d, left = %d, right = %d\n", a[index], a[left], a[right]);
    if (left < n && a[index] < a[left])
        largest = left;
    else
        largest = index;

    if (right < n && a[largest] < a[right])
        largest = right;

    if (largest != index) {
        int temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;
        print(a, n);
        max_heapify(a, n, largest);
    }
}

// T(n) <= T(2n/3) + O(1) ---------> O(lgn)