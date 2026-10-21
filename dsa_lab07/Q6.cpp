// Name: Rimsha Mahmood
// Reg No: 455080
// Section: CS-15E
// DSA Lab 07 - Task 6: Deque using doubly linked nodes

#include <iostream>
using namespace std;

class LinkedDeque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
        explicit node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    node* front;
    node* rear;

public:
    LinkedDeque() : front(nullptr), rear(nullptr) {}
    LinkedDeque(const LinkedDeque&) = delete;
    LinkedDeque& operator=(const LinkedDeque&) = delete;

    ~LinkedDeque() { ClearDeque(); }

    bool IsEmpty() const { return front == nullptr; }

    void InsertFront(int value) {
        node* fresh = new node(value);
        if (IsEmpty()) front = rear = fresh;
        else {
            fresh->next = front;
            front->prev = fresh;
            front = fresh;
        }
        cout << value << " inserted at front.\n";
    }

    void InsertRear(int value) {
        node* fresh = new node(value);
        if (IsEmpty()) front = rear = fresh;
        else {
            fresh->prev = rear;
            rear->next = fresh;
            rear = fresh;
        }
        cout << value << " inserted at rear.\n";
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }
        node* temp = front;
        cout << "Deleted from front: " << temp->data << '\n';
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
        else front->prev = nullptr;
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }
        node* temp = rear;
        cout << "Deleted from rear: " << temp->data << '\n';
        rear = rear->prev;
        delete temp;
        if (rear == nullptr) front = nullptr;
        else rear->next = nullptr;
    }

    void Display() const {
        if (IsEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque (front to rear): ";
        for (node* current = front; current != nullptr; current = current->next)
            cout << current->data << ' ';
        cout << '\n';
    }

    void ClearDeque() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    LinkedDeque d;
    int choice, value;

    do {
        cout << "\n--- Linked Deque Menu ---\n"
             << "1. Insert at front\n"
             << "2. Insert at rear\n"
             << "3. Delete from front\n"
             << "4. Delete from rear\n"
             << "5. Display deque\n"
             << "6. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            if (cin >> value) d.InsertFront(value);
            else { cout << "Invalid value.\n"; d.ClearDeque(); return 0; }
            break;
        case 2:
            cout << "Enter value: ";
            if (cin >> value) d.InsertRear(value);
            else { cout << "Invalid value.\n"; d.ClearDeque(); return 0; }
            break;
        case 3:
            d.DeleteFront();
            break;
        case 4:
            d.DeleteRear();
            break;
        case 5:
            d.Display();
            break;
        case 6:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid menu choice. Choose 1-6.\n";
        }
    } while (choice != 6);

    d.ClearDeque();
    return 0;
}
