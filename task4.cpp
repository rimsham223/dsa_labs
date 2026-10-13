/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 4: Inserting values into a queue
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

void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Nothing to display.\n";
        return;
    }
    cout << "Queue contents (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Display empty queue message
    display();

    // Insert 10, 20, 30
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Display contents
    display();

    // Fill the queue
    enqueue(40);
    enqueue(50);

    // Attempt one more insertion when full
    enqueue(60);

    return 0;
}