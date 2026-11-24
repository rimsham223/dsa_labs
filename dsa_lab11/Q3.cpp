/*
 * Lab 11 - Heaps and Sorting Algorithms
 * Task 3: Heap-based Priority Queue (max-heap of Job records)
 *
 * Name:            Rimsha Mahmood
 * Registration No: 455080
 * Section:         BSCS-15E    
*/

#include <iostream>
using namespace std;

const int CAPACITY = 20;

struct Job {
    int id;
    int priority;
};

// Swap whole Job records so IDs stay paired with their priorities.
void swapJob(Job& a, Job& b) {
    Job t = a;
    a = b;
    b = t;
}

// Sift-down adapted from maxHeapify (Task 1), comparing priorities.
void heapifyDown(Job heap[], int size, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && heap[left].priority > heap[largest].priority) largest = left;
        if (right < size && heap[right].priority > heap[largest].priority) largest = right;
        if (largest == i) break;
        swapJob(heap[i], heap[largest]);
        i = largest;
    }
}

// Insert: append at the end, then move up while priority exceeds parent's.
// O(log n) worst case.
bool insertJob(Job heap[], int& size, int capacity, Job item) {
    if (size >= capacity) return false;   // full
    int i = size;
    heap[i] = item;
    size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].priority > heap[parent].priority) {
            swapJob(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
    return true;
}

// Peek: return root without changing the queue. O(1).
bool peekJob(const Job heap[], int size, Job& item) {
    if (size == 0) return false;          // empty
    item = heap[0];
    return true;
}

// Remove: save root, move last job to root, shrink, sift down. O(log n).
bool removeJob(Job heap[], int& size, Job& item) {
    if (size == 0) return false;          // empty
    item = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(heap, size, 0);
    return true;
}

void displayQueue(const Job heap[], int size) {
    cout << "Queue contents (HEAP ORDER, not service order), size = " << size << ":" << endl;
    if (size == 0) {
        cout << "  (empty)" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
        cout << "  [" << i << "] ID " << heap[i].id << ", priority " << heap[i].priority << endl;
}

// ---------- Automated test sequence from the lab ----------
void runTests() {
    Job heap[CAPACITY];
    int size = 0;
    Job j;

    cout << "\n===== AUTOMATED TEST SEQUENCE =====" << endl;

    // Empty-queue operations
    cout << "Peek on empty queue: " << (peekJob(heap, size, j) ? "true" : "false (correct)") << endl;
    cout << "Remove on empty queue: " << (removeJob(heap, size, j) ? "true" : "false (correct)") << endl;

    Job jobs[] = {{101, 3}, {102, 5}, {103, 1}, {104, 4}};
    for (int k = 0; k < 4; k++) {
        insertJob(heap, size, CAPACITY, jobs[k]);
        cout << "Inserted (" << jobs[k].id << ", " << jobs[k].priority << ")" << endl;
    }
    displayQueue(heap, size);

    int before = size;
    if (peekJob(heap, size, j))
        cout << "Peek -> ID " << j.id << ", priority " << j.priority << endl;
    cout << "Size before peek = " << before << ", after peek = " << size
         << (before == size ? "  (unchanged, correct)" : "  (CHANGED - error)") << endl;

    if (removeJob(heap, size, j))
        cout << "Remove -> ID " << j.id << ", priority " << j.priority << endl;

    insertJob(heap, size, CAPACITY, Job{105, 6});
    cout << "Inserted (105, 6)" << endl;
    displayQueue(heap, size);

    cout << "Removing all remaining jobs (service order):" << endl;
    while (removeJob(heap, size, j))
        cout << "  Served ID " << j.id << ", priority " << j.priority << endl;
    cout << "Expected service order overall: 102, 105, 104, 101, 103" << endl;

    // Capacity test
    cout << "\nCapacity test: filling queue to " << CAPACITY << " jobs..." << endl;
    for (int k = 0; k < CAPACITY; k++)
        insertJob(heap, size, CAPACITY, Job{200 + k, k + 1});
    cout << "Size = " << size << endl;
    bool ok = insertJob(heap, size, CAPACITY, Job{999, 100});
    cout << "Insert beyond capacity: " << (ok ? "true (ERROR)" : "false (correct)") << endl;
    cout << "Size still = " << size << endl;
    cout << "===== END OF TESTS =====\n" << endl;
}

// ---------- Interactive menu ----------
int main() {
    Job heap[CAPACITY];
    int size = 0;
    int choice;

    do {
        cout << "\n--- Computer Lab Job Priority Queue ---" << endl;
        cout << "1. Insert job" << endl;
        cout << "2. Peek (highest priority)" << endl;
        cout << "3. Remove (serve highest priority)" << endl;
        cout << "4. Display (heap order)" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Run automated lab tests" << endl;
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;   // stop cleanly on end of input

        Job j;
        switch (choice) {
            case 1:
                cout << "Enter job ID: ";
                cin >> j.id;
                cout << "Enter priority (larger = higher): ";
                cin >> j.priority;
                if (insertJob(heap, size, CAPACITY, j))
                    cout << "Job inserted." << endl;
                else
                    cout << "Queue is FULL (capacity " << CAPACITY << "). Insert failed." << endl;
                break;
            case 2:
                if (peekJob(heap, size, j))
                    cout << "Next job: ID " << j.id << ", priority " << j.priority << endl;
                else
                    cout << "Queue is EMPTY." << endl;
                break;
            case 3:
                if (removeJob(heap, size, j))
                    cout << "Served job: ID " << j.id << ", priority " << j.priority << endl;
                else
                    cout << "Queue is EMPTY. Nothing to remove." << endl;
                break;
            case 4:
                displayQueue(heap, size);
                break;
            case 5:
                cout << "Exiting." << endl;
                break;
            case 6:
                runTests();
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}


