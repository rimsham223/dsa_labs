// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 5: Deque using a circular array

#include <iostream>
using namespace std;

class ArrayDeque {
private:
    int items[5];
    int front, rear;

public:
    ArrayDeque() : front(-1), rear(-1) {}

    bool IsEmpty() const { return front == -1; }
    bool IsFull() const { return !IsEmpty() && (rear + 1) % 5 == front; }

    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Deque is full. Cannot insert " << value << " at front.\n";
            return;
        }
        if (IsEmpty()) front = rear = 0;
        else front = (front + 5 - 1) % 5;
        items[front] = value;
        cout << value << " inserted at front.\n";
    }

    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Deque is full. Cannot insert " << value << " at rear.\n";
            return;
        }
        if (IsEmpty()) front = rear = 0;
        else rear = (rear + 1) % 5;
        items[rear] = value;
        cout << value << " inserted at rear.\n";
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        cout << "Deleted from front: " << items[front] << '\n';
        if (front == rear) front = rear = -1;
        else front = (front + 1) % 5;
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        cout << "Deleted from rear: " << items[rear] << '\n';
        if (front == rear) front = rear = -1;
        else rear = (rear + 5 - 1) % 5;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque (front to rear): ";
        int i = front;
        while (true) {
            cout << items[i] << ' ';
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << '\n';
    }
};

int main() {
    ArrayDeque d;
    d.InsertRear(20);
    d.InsertFront(10);
    d.InsertRear(30);
    d.Display(); // 10 20 30
    d.DeleteRear();
    d.DeleteFront();
    d.Display(); // 20

    d.InsertFront(5);
    d.InsertRear(30);
    d.InsertRear(40);
    d.InsertFront(1);
    d.Display(); // 1 5 20 30 40
    d.InsertRear(50); // Full test at rear.
    d.InsertFront(0); // Full test at front.

    cout << "\nDelete-only-value tests:\n";
    ArrayDeque onlyFront;
    onlyFront.InsertRear(7);
    onlyFront.DeleteFront();
    onlyFront.DeleteFront(); // Empty test.

    ArrayDeque onlyRear;
    onlyRear.InsertFront(8);
    onlyRear.DeleteRear();
    onlyRear.DeleteRear(); // Empty test.
    return 0;
}
