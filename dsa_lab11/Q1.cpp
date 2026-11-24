/*
 * Lab 11 - Heaps and Sorting Algorithms
 * Task 1: Building a Max Heap
 *
 * Name:            Rimsha Mahmood
 * Registration No: 455080
 * Section:         BSCS-15E    
*/

#include <iostream>
using namespace std;

// Swap two integers (we write our own; no STL heap functions are used).
void swapInt(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// Restore the max-heap property at index i, assuming the subtrees rooted
// at its children are already max-heaps. n is the current heap size.
// Iterative version: extra space O(1) (no recursion stack).
void maxHeapify(int arr[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Always check a child index against n before reading it.
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest == i) break;      // heap property holds here
        swapInt(arr[i], arr[largest]);
        i = largest;                  // continue sifting down
    }
}

// Bottom-up heap construction: start at the last non-leaf node (n/2 - 1)
// and heapify each node back to the root. Runs in O(n).
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// ---------- Helper / testing functions ----------

void printArray(const int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Print the complete binary tree level by level.
void printTree(const int arr[], int n) {
    if (n == 0) {
        cout << "  (empty tree)" << endl;
        return;
    }
    int levelStart = 0, levelSize = 1, level = 0;
    while (levelStart < n) {
        cout << "  Level " << level << ": ";
        for (int i = levelStart; i < levelStart + levelSize && i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        levelStart += levelSize;
        levelSize *= 2;
        level++;
    }
}

// Check parent >= child at every non-leaf node and print each check.
bool verifyMaxHeap(const int arr[], int n, bool verbose) {
    bool ok = true;
    for (int i = 0; i <= n / 2 - 1; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (verbose) cout << "  Node[" << i << "]=" << arr[i] << ": ";
        if (left < n) {
            bool good = arr[i] >= arr[left];
            if (verbose) cout << "left[" << left << "]=" << arr[left]
                              << (good ? " OK" : " VIOLATION") << "  ";
            ok = ok && good;
        }
        if (right < n) {
            bool good = arr[i] >= arr[right];
            if (verbose) cout << "right[" << right << "]=" << arr[right]
                              << (good ? " OK" : " VIOLATION");
            ok = ok && good;
        }
        if (verbose) cout << endl;
    }
    if (verbose && n <= 1) cout << "  (no non-leaf nodes to check)" << endl;
    return ok;
}

void runTest(const char* title, int arr[], int n) {
    cout << "==== " << title << " (n = " << n << ") ====" << endl;
    cout << "Before: ";
    printArray(arr, n);
    cout << "Tree before:" << endl;
    printTree(arr, n);

    buildMaxHeap(arr, n);

    cout << "After buildMaxHeap: ";
    printArray(arr, n);
    cout << "Tree after:" << endl;
    printTree(arr, n);
    cout << "Verifying parent >= child:" << endl;
    bool ok = verifyMaxHeap(arr, n, true);
    cout << "Result: " << (ok ? "VALID max-heap" : "NOT a max-heap") << endl << endl;
}

int main() {
    // Main test array from the lab
    int a[] = {35, 12, 43, 8, 51, 27, 19};
    runTest("Main array", a, 7);

    // Boundary case: empty array
    int* empty = nullptr;
    runTest("Empty array", empty, 0);

    // Boundary case: single element
    int single[] = {42};
    runTest("Single element", single, 1);

    // Repeated values
    int rep[] = {5, 9, 5, 9, 1, 9, 5};
    runTest("Repeated values", rep, 7);

    // All equal values
    int same[] = {7, 7, 7, 7};
    runTest("All equal values", same, 4);

    return 0;
}


