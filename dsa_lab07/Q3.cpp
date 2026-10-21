// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 3: Circular queue using an array

#include <iostream>
using namespace std;

class CircularQueue {
private:
    int items[5];
    int front, rear;

public:
    CircularQueue() : front(-1), rear(-1) {}

    bool IsEmpty() const { return front == -1; }
    bool IsFull() const { return !IsEmpty() && (rear + 1) % 5 == front; }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }
        if (IsEmpty()) front = rear = 0;
        else rear = (rear + 1) % 5;
        items[rear] = value;
        cout << value << " enqueued.\n";
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        cout << "Dequeued: " << items[front] << '\n';
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
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
        int i = front;
        while (true) {
            cout << items[i] << ' ';
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << "\nfront = " << front << ", rear = " << rear << '\n';
    }
};

int main() {
    CircularQueue q;
    for (int value : {10, 20, 30, 40, 50}) q.Enqueue(value);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(60);
    q.Enqueue(70);
    q.Display(); // 30 40 50 60 70; front=2, rear=1
    q.Enqueue(80); // Full-queue test.
    q.Peek();
    while (!q.IsEmpty()) q.Dequeue();
    q.Dequeue(); // Empty-queue test.
    q.Enqueue(90); // Reuse after emptying.
    q.Display();
    return 0;
}
