/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 2: Insertion and Deletion in a Doubly Linked List
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

    void InsertBefore(int position, int value) {
        if (position < 1 || head == nullptr) {
            std::cout << "Invalid position or empty list. Insertion failed." << std::endl;
            return;
        }

        node* current = head;
        int currentPos = 1;

        while (current != nullptr && currentPos < position) {
            current = current->next;
            currentPos++;
        }

        if (current == nullptr) {
            std::cout << "Position " << position << " is out of bounds. Insertion failed." << std::endl;
            return;
        }

        node* newNode = new node{value, nullptr, nullptr};

        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }

    void DeleteNode(int value) {
        if (head == nullptr) {
            std::cout << "Cannot delete from an empty list." << std::endl;
            return;
        }

        node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Value " << value << " not found in the list." << std::endl;
            return;
        }

        if (current == head && current == tail) {
            head = tail = nullptr;
        } else if (current == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
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
    std::cout << "=== Task 2 Demonstration ===" << std::endl;

    DoublyList list;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    std::cout << "Initial list:" << std::endl;
    list.PrintForward();
    list.PrintReverse();

    std::cout << "\nInserting 15 before position 2:" << std::endl;
    list.InsertBefore(2, 15);
    list.PrintForward();
    list.PrintReverse();

    std::cout << "\nDeleting node with value 20:" << std::endl;
    list.DeleteNode(20);
    list.PrintForward();
    list.PrintReverse();

    std::cout << "\nInserting before head (position 1 with value 5):" << std::endl;
    list.InsertBefore(1, 5);
    list.PrintForward();

    std::cout << "\nDeleting head (5):" << std::endl;
    list.DeleteNode(5);
    list.PrintForward();

    std::cout << "\nDeleting tail (30):" << std::endl;
    list.DeleteNode(30);
    list.PrintForward();

    std::cout << "\nDeleting missing value (99):" << std::endl;
    list.DeleteNode(99);

    std::cout << "\nDeleting remaining nodes until empty:" << std::endl;
    list.DeleteNode(10);
    list.DeleteNode(15);
    list.PrintForward();

    return 0;
}