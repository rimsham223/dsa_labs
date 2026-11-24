/*
 * Lab 11 - Heaps and Sorting Algorithms
 * Task 4: Bubble Sort (normal and optimized)
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

void printArray(const int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";
}

// Normal bubble sort: always n - 1 passes; the unsorted part shrinks by one
// each pass because the largest remaining value bubbles to the end.
void bubbleSort(int arr[], int n) {
    long comparisons = 0, swaps = 0;

    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - 1 - pass; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {          // strictly greater -> stable
                swapInt(arr[j], arr[j + 1]);
                swaps++;
            }
        }
        cout << "    Pass " << pass + 1 << ": ";
        printArray(arr, n);
        cout << endl;
    }
    cout << "    Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
}

// Optimized bubble sort: stop after a pass in which no swap happened.
void bubbleSortOptimized(int arr[], int n) {
    long comparisons = 0, swaps = 0;

    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - pass; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        cout << "    Pass " << pass + 1 << ": ";
        printArray(arr, n);
        cout << endl;
        if (!swapped) {
            cout << "    No swaps in this pass -> array is sorted, stopping early." << endl;
            break;
        }
    }
    cout << "    Comparisons = " << comparisons << ", Swaps = " << swaps << endl;
}

void copyArray(const int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

// Run both versions on fresh copies of the same input.
void runBoth(const char* title, const int input[], int n) {
    int work[20];
    cout << "==== " << title << " ";
    printArray(input, n);
    cout << " (n = " << n << ") ====" << endl;

    copyArray(input, work, n);
    cout << "  Normal bubble sort:" << endl;
    if (n <= 1) cout << "    n <= 1: no passes needed." << endl;
    bubbleSort(work, n);
    cout << "    Result: ";
    printArray(work, n);
    cout << endl;

    copyArray(input, work, n);
    cout << "  Optimized bubble sort:" << endl;
    if (n <= 1) cout << "    n <= 1: no passes needed." << endl;
    bubbleSortOptimized(work, n);
    cout << "    Result: ";
    printArray(work, n);
    cout << endl << endl;
}

int main() {
    const int unsorted[] = {5, 1, 4, 2, 8};
    const int sorted[]   = {1, 2, 4, 5, 8};
    const int reversed[] = {8, 5, 4, 2, 1};
    const int repeated[] = {3, 1, 3, 2, 1};
    const int single[]   = {7};

    runBoth("Unsorted", unsorted, 5);
    runBoth("Already sorted", sorted, 5);
    runBoth("Reverse sorted", reversed, 5);
    runBoth("Repeated values", repeated, 5);
    runBoth("Empty", nullptr, 0);
    runBoth("Single element", single, 1);

    return 0;
}


