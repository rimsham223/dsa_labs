/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 1: Creating and Traversing a Doubly Linked List
 */

#include <iostream>

class DoublyList {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;

public:
    DoublyList() : head(nullptr), tail(nullptr) {}

    ~DoublyList() {
        ClearList();
    }

    void AddNode(int value) {
        node* newNode = new node{value, nullptr, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void PrintForward() const {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        std::cout << "Forward: ";
        node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << (temp->next ? ", " : "");
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void PrintReverse() const {
        if (tail == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        std::cout << "Reverse: ";
        node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << (temp->prev ? ", " : "");
            temp = temp->prev;
        }
        std::cout << std::endl;
    }

    void ClearList() {
        node* current = head;
        while (current != nullptr) {
            node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    std::cout << "=== Task 1 Demonstration ===" << std::endl;

    DoublyList list;

    std::cout << "-- Testing Empty List --" << std::endl;
    list.PrintForward();
    list.PrintReverse();

    std::cout << "\n-- Testing Single Node (10) --" << std::endl;
    list.AddNode(10);
    list.PrintForward();
    list.PrintReverse();

    list.ClearList();

    std::cout << "\n-- Testing Three Nodes (10, 20, 30) --" << std::endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintForward();
    list.PrintReverse();

    return 0;
}