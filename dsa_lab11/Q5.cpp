/*
 * Lab 11 - Heaps and Sorting Algorithms
 * Task 5: Selection Sort and Comparison
 *
 * Name:            Rimsha Mahmood
 * Registration No: 455080
 * Section:         BSCS-15E    
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Counters for the most recent sort call (element comparisons and actual swaps).
long gComparisons = 0, gSwaps = 0;
bool gVerbose = true;   // print array after each pass

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

void printPass(int pass, const int arr[], int n) {
    if (!gVerbose) return;
    cout << "    Pass " << pass << ": ";
    printArray(arr, n);
    cout << endl;
}

// Selection sort (ascending): find the minimum of the unsorted part and
// swap it into position i -- only if it is at a different index.
void selectionSort(int arr[], int n) {
    gComparisons = gSwaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            gComparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            swapInt(arr[i], arr[minIdx]);
            gSwaps++;
        }
        printPass(i + 1, arr, n);
    }
}

// ---- Bubble sorts (same as Task 4) included for the comparison table ----
void bubbleSort(int arr[], int n) {
    gComparisons = gSwaps = 0;
    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - 1 - pass; j++) {
            gComparisons++;
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
                gSwaps++;
            }
        }
        printPass(pass + 1, arr, n);
    }
}

void bubbleSortOptimized(int arr[], int n) {
    gComparisons = gSwaps = 0;
    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - pass; j++) {
            gComparisons++;
            if (arr[j] > arr[j + 1]) {
                swapInt(arr[j], arr[j + 1]);
                gSwaps++;
                swapped = true;
            }
        }
        printPass(pass + 1, arr, n);
        if (!swapped) break;
    }
}

void copyArray(const int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

void runSelection(const char* title, const int input[], int n) {
    int work[20];
    copyArray(input, work, n);
    cout << "==== Selection sort: " << title << " ";
    printArray(input, n);
    cout << " (n = " << n << ") ====" << endl;
    if (n <= 1) cout << "    n <= 1: no passes needed." << endl;
    gVerbose = true;
    selectionSort(work, n);
    cout << "    Result: ";
    printArray(work, n);
    cout << "\n    Comparisons = " << gComparisons << ", Swaps = " << gSwaps << endl << endl;
}

// One row of the comparison table: run all three sorts on fresh copies.
void compareRow(const char* title, const int input[], int n) {
    int work[20];
    gVerbose = false;

    copyArray(input, work, n);
    bubbleSort(work, n);
    long bc = gComparisons, bs = gSwaps;

    copyArray(input, work, n);
    bubbleSortOptimized(work, n);
    long oc = gComparisons, os = gSwaps;

    copyArray(input, work, n);
    selectionSort(work, n);
    long sc = gComparisons, ss = gSwaps;

    cout << left << setw(16) << title
         << right << setw(8) << bc << setw(7) << bs
         << setw(10) << oc << setw(7) << os
         << setw(10) << sc << setw(7) << ss << endl;
}

int main() {
    const int unsorted[] = {5, 1, 4, 2, 8};
    const int sorted[]   = {1, 2, 4, 5, 8};
    const int reversed[] = {8, 5, 4, 2, 1};
    const int repeated[] = {3, 1, 3, 2, 1};
    const int single[]   = {7};

    runSelection("Unsorted", unsorted, 5);
    runSelection("Already sorted", sorted, 5);
    runSelection("Reverse sorted", reversed, 5);
    runSelection("Repeated values", repeated, 5);
    runSelection("Empty", nullptr, 0);
    runSelection("Single element", single, 1);

    cout << "================ COMPARISON TABLE (comparisons / swaps) ================" << endl;
    cout << left << setw(16) << "Input"
         << right << setw(15) << "Bubble"
         << setw(17) << "Bubble-Opt"
         << setw(17) << "Selection" << endl;
    cout << left << setw(16) << ""
         << right << setw(8) << "comp" << setw(7) << "swap"
         << setw(10) << "comp" << setw(7) << "swap"
         << setw(10) << "comp" << setw(7) << "swap" << endl;
    compareRow("{5,1,4,2,8}", unsorted, 5);
    compareRow("{1,2,4,5,8}", sorted, 5);
    compareRow("{8,5,4,2,1}", reversed, 5);
    compareRow("{3,1,3,2,1}", repeated, 5);

    return 0;
}

/*
 * Why selection sort still scans sorted input:
 *   It has no way to know the rest is sorted - to find the minimum of the
 *   unsorted part it must compare against every remaining element. So it
 *   always does n(n-1)/2 comparisons (10 for n = 5), even on sorted input.
 *
 * Why at most n - 1 swaps (n >= 1):
 *   There are n - 1 passes and each pass does at most one swap (and none if
 *   the minimum is already in place). Sorted input -> 0 swaps.
 *   Reverse {8,5,4,2,1} -> only 2 swaps, whereas bubble sort needs 10.
 *
 * Viva check:
 *   Algorithm        Worst time     Stable?   Extra space
 *   Heap sort        O(n log n)     No        O(1) (iterative heapify)
 *   Bubble sort      O(n^2)         Yes       O(1)
 *   Selection sort   O(n^2)         No        O(1)
 *
 *   Stability with equal keys, e.g. records (2,a), (2,b), (1,c):
 *   - Bubble sort only swaps when left > right, so (2,a) never passes (2,b):
 *     result (1,c), (2,a), (2,b) -> stable.
 *   - Selection sort swaps (2,a) with (1,c) at the end of pass 1:
 *     (1,c), (2,b), (2,a) -> order of equal keys changed -> unstable.
 *   - Heap sort moves the root to the end with long-distance swaps, which
 *     can also reverse equal keys -> unstable.
 *
 *   Extra space of my heapify: iterative loop, so O(1). A recursive heapify
 *   would use O(log n) stack space (one call per tree level).
 */
