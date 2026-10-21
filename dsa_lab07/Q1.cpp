// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 1: Linear queue using an array

#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int items[5];
    int front, rear;

public:
    ArrayQueue() : front(-1), rear(-1) {}

    bool IsEmpty() const { return front == -1; }
    bool IsFull() const { return rear == 4; }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (IsEmpty()) front = 0;
        items[++rear] = value;
        cout << value << " enqueued.\n";
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << items[front] << '\n';
        if (front == rear) front = rear = -1;
        else ++front;
    }

    void Peek() const {
        if (IsEmpty()) cout << "Queue is empty. Nothing to peek.\n";
        else cout << "Front value: " << items[front] << '\n';
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; ++i) cout << items[i] << ' ';
        cout << '\n';
    }
};

int main() {
    ArrayQueue q;
    for (int value : {10, 20, 30, 40, 50}) q.Enqueue(value);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(60); // Rejected: linear queue has reached rear index 4.
    q.Display();
    q.Peek();
    while (!q.IsEmpty()) q.Dequeue();
    q.Dequeue();
    q.Enqueue(70); // Queue can be reused after it becomes empty.
    q.Display();
    return 0;
}
