// HeapSort is a sorting algorihtm which has time complexity of O(nlgn) and it
// is inplace sorting algorithm.

#include <stdio.h>

void heapsort(int a[], int n);
void build_max_heap(int a[], int n);
void max_heapify(int a[], int n, int index);
void print(int a[], int n);

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) //Random input array.
        scanf("%d", &a[i]);

    heapsort(a, n);
    print(a, n);
}
void heapsort(int a[], int n){
    build_max_heap(a, n);
    int m = n;
    for (int i = n-1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        m--;
        max_heapify(a, m, 0);
    }
}
void build_max_heap(int a[], int n) {
    for (int i = n/2; i >= 0; i--) {
        max_heapify(a, n, i);
    }
}
void max_heapify(int a[], int n, int index) {
    // O(lgn) or O(h), where h is height of the heap.
    int largest;
    int left = 2*index + 1;
    int right = 2*index + 2;
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
        max_heapify(a, n, largest);
    }
}
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d, ", a[i]);
    printf("\n");
}