/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 5: Removing values from a queue
 */

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue is full (Insertion Blocked)! Cannot enqueue " << value << ".\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "Enqueued " << value << " into the queue.\n";
}

void dequeue() {
    if (front == -1) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }
    cout << "Removed value: " << items[front] << "\n";
    if (front == rear) {
        // Reset indices when last item is removed
        front = -1;
        rear = -1;
        cout << "Queue is now empty. Indices reset to -1.\n";
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout << "Queue is empty. No front element.\n";
        return;
    }
    cout << "Front element: " << items[front] << "\n";
}

void display() {
    if (front == -1) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue contents (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Insert 10, 20, 30
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Remove once
    dequeue();

    // Peek and display
    peekFront();
    display();

    // Remove remaining items
    dequeue();
    dequeue();

    // Try another removal on empty queue
    dequeue();

    // Insert 40 to check queue works after reset
    enqueue(40);
    display();

    return 0;
}