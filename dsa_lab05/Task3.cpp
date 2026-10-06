/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 3: Creating and Traversing a Circular Linked List
 * 
 * Explanation on Traversal Termination:
 * A normal nullptr-based traversal relies on finding a node whose next pointer is nullptr to end 
 * the loop. In a non-empty circular linked list, the tail node points back to the head node, so 
 * no next pointer is ever nullptr. Consequently, a standard `while (temp != nullptr)` loop would 
 * result in an infinite loop. We must stop traversal after completing one cycle (i.e., when temp 
 * returns to head).
 */

#include <iostream>

class CircularList {
private:
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    CircularList() : head(nullptr), tail(nullptr) {}

    ~CircularList() {
        ClearList();
    }

    void AddNode(int value) {
        node* newNode = new node{value, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    int CountNodes() const {
        if (head == nullptr) return 0;

        int count = 0;
        node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void PrintList() const {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        std::cout << "List: ";
        node* temp = head;
        do {
            std::cout << temp->data << (temp->next != head ? ", " : "");
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    void ClearList() {
        if (head == nullptr) return;

        tail->next = nullptr; // Break the cycle
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
    std::cout << "=== Task 3 Demonstration ===" << std::endl;

    CircularList list;

    std::cout << "-- Testing Empty List --" << std::endl;
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    std::cout << "\n-- Testing Single Node (10) --" << std::endl;
    list.AddNode(10);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.ClearList();

    std::cout << "\n-- Testing Three Nodes (10, 20, 30) --" << std::endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    return 0;
}