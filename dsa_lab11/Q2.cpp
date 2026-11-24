/*
 * Lab 11 - Heaps and Sorting Algorithms
 * Task 2: Heap Sort
 *
  * Name:            Rimsha Mahmood
 * Registration No: 455080
 * Section:         BSCS-15E    
*/

#include <iostream>
using namespace std;

void swapInt(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// ---- Reused from Task 1 ----
void maxHeapify(int arr[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest == i) break;
        swapInt(arr[i], arr[largest]);
        i = largest;
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Print the array with a '|' between the active heap [0, heapSize)
// and the sorted suffix [heapSize, n).
void printWithBoundary(const int arr[], int n, int heapSize) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        if (i == heapSize) cout << "| ";
        cout << arr[i] << " ";
    }
    if (heapSize == n) cout << "| ";
    cout << "]" << endl;
}

// Heap sort (ascending).
// 1. Build the max-heap ONCE.
// 2. Repeatedly swap root (max) with the last element of the active heap,
//    shrink the heap by one, and repair only the root with maxHeapify.
//    The sorted suffix is never touched again.
void heapSort(int arr[], int n) {
    if (n <= 1) {
        cout << "  n <= 1: already sorted, nothing to do." << endl;
        return;
    }

    buildMaxHeap(arr, n);
    cout << "  After buildMaxHeap: ";
    printWithBoundary(arr, n, n);

    for (int heapSize = n - 1; heapSize >= 1; heapSize--) {
        swapInt(arr[0], arr[heapSize]);     // move max to its final place
        maxHeapify(arr, heapSize, 0);       // repair active heap only
        cout << "  Iteration " << (n - heapSize) << ":         ";
        printWithBoundary(arr, n, heapSize);
    }
}

void printArray(const int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

bool isSortedAsc(const int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i]) return false;
    return true;
}

void runTest(const char* title, int arr[], int n) {
    cout << "==== " << title << " (n = " << n << ") ====" << endl;
    cout << "  Input:  ";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "  Output: ";
    printArray(arr, n);
    cout << "  Sorted correctly? " << (isSortedAsc(arr, n) ? "YES" : "NO") << endl << endl;
}

int main() {
    cout << "Format: [ active heap | sorted suffix ]" << endl << endl;

    int a[] = {35, 12, 43, 8, 51, 27, 19};
    runTest("Main array", a, 7);

    int sorted[] = {1, 2, 3, 4, 5, 6};
    runTest("Already sorted", sorted, 6);

    int reverse[] = {6, 5, 4, 3, 2, 1};
    runTest("Reverse sorted", reverse, 6);

    int rep[] = {4, 1, 4, 2, 1, 4};
    runTest("Repeated values", rep, 6);

    int* empty = nullptr;
    runTest("Empty array", empty, 0);

    int single[] = {9};
    runTest("Single element", single, 1);

    return 0;
}


