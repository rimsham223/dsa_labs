/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 4: Deletion in a Circular Linked List
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

    void DeleteNode(int value) {
        if (head == nullptr) {
            std::cout << "Cannot delete from an empty list." << std::endl;
            return;
        }

        node* current = head;
        node* prev = tail;
        bool found = false;

        do {
            if (current->data == value) {
                found = true;
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        if (!found) {
            std::cout << "Value " << value << " not found in the list." << std::endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            if (current == head) {
                head = head->next;
                tail->next = head;
            } else if (current == tail) {
                tail = prev;
                tail->next = head;
            } else {
                prev->next = current->next;
            }
            delete current;
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

        tail->next = nullptr;
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
    std::cout << "=== Task 4 Demonstration ===" << std::endl;

    CircularList list;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    std::cout << "Initial state:" << std::endl;
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    std::cout << "\nDeleting head (10):" << std::endl;
    list.DeleteNode(10);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    std::cout << "\nDeleting tail (30):" << std::endl;
    list.DeleteNode(30);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    std::cout << "\nDeleting only remaining node (20):" << std::endl;
    list.DeleteNode(20);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    std::cout << "\n-- Testing Duplicate Deletion --" << std::endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    std::cout << "Before deleting 20: ";
    list.PrintList();

    list.DeleteNode(20);
    std::cout << "After deleting first 20: ";
    list.PrintList();

    return 0;
}