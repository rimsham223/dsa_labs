// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 4: Rotating service turns using a circular queue

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
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1;
        }
        int value = items[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
        return value;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (next student first): ";
        int i = front;
        while (true) {
            cout << items[i] << ' ';
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << '\n';
    }

    void RotateTurn() {
        if (IsEmpty()) {
            cout << "No students are waiting; cannot rotate an empty queue.\n";
            return;
        }
        int served = Dequeue();
        Enqueue(served);
        cout << "Student served: " << served << '\n';
        cout << "Updated ";
        Display();
    }
};

int main() {
    CircularQueue q;
    q.Enqueue(101);
    q.Enqueue(102);
    q.Enqueue(103);

    cout << "Five service turns:\n";
    for (int turn = 1; turn <= 5; ++turn) {
        cout << "\nTurn " << turn << ":\n";
        q.RotateTurn();
    }

    cout << "\nEmpty-queue test:\n";
    CircularQueue emptyQueue;
    emptyQueue.RotateTurn();

    cout << "\nOne-student test:\n";
    CircularQueue oneStudent;
    oneStudent.Enqueue(201);
    oneStudent.RotateTurn();
    oneStudent.Display();
    return 0;
}
