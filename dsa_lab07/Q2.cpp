// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 2: Queue using linked nodes

#include <iostream>
using namespace std;

class LinkedQueue {
private:
    struct node {
        int data;
        node* next;
        explicit node(int value) : data(value), next(nullptr) {}
    };

    node* front;
    node* rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

    ~LinkedQueue() { ClearQueue(); }

    bool IsEmpty() const { return front == nullptr; }

    void Enqueue(int value) {
        node* fresh = new node(value);
        if (IsEmpty()) front = rear = fresh;
        else {
            rear->next = fresh;
            rear = fresh;
        }
        cout << value << " enqueued.\n";
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        node* temp = front;
        cout << "Dequeued: " << temp->data << '\n';
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
    }

    void Peek() const {
        if (IsEmpty()) cout << "Queue is empty. Nothing to peek.\n";
        else cout << "Front value: " << front->data << '\n';
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (node* current = front; current != nullptr; current = current->next)
            cout << current->data << ' ';
        cout << '\n';
    }

    void ClearQueue() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Dequeue();
    q.Display(); // 20 30
    q.Peek();
    q.Dequeue();
    q.Dequeue(); // Removes the only remaining node.
    q.Dequeue(); // Empty-queue test.
    q.Enqueue(40); // Insertion after becoming empty.
    q.Display();
    q.ClearQueue();
    return 0;
}
