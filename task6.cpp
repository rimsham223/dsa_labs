/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 6: Building a customer service queue
 */

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Insertion Blocked! Queue is full at the end (rear = " << SIZE - 1 << ").\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "Customer token " << value << " added to the queue.\n";
}

void dequeue() {
    if (front == -1) {
        cout << "Queue is empty! No customers to serve.\n";
        return;
    }
    cout << "Serving customer token: " << items[front] << "\n";
    if (front == rear) {
        front = -1;
        rear = -1;
        cout << "All customers served. Queue has been reset.\n";
    } else {
        front++;
    }
}

void peekFront() {
    if (front == -1) {
        cout << "Queue is empty! No customers in line.\n";
        return;
    }
    cout << "Next customer token to be served: " << items[front] << "\n";
}

void display() {
    if (front == -1) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Current Customer Queue (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, token;

    do {
        cout << "\n--- Customer Service Queue System ---\n";
        cout << "1. Add customer\n";
        cout << "2. Serve next\n";
        cout << "3. View next\n";
        cout << "4. Display queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer token number: ";
                cin >> token;
                enqueue(token);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}