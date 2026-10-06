/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 6: Implementing a Stack Using Linked Nodes
 * 
 * Explanation of LIFO and Comparison:
 * LIFO (Last-In, First-Out): The element added most recently is the first one removed. 
 * Both push and pop operate solely on the `top` pointer at the head of the list, ensuring O(1) time complexity.
 * 
 * ArrayStack (Task 5) vs LinkedStack (Task 6):
 * - Fixed Capacity: ArrayStack has a rigid size limit (5 elements). Pushing past this limit leads to overflow.
 * - Dynamic Allocation: LinkedStack grows dynamically at runtime. It is bounded only by available system memory, 
 *   eliminating stack overflow due to fixed array limits.
 */

#include <iostream>

class LinkedStack {
private:
    struct node {
        int data;
        node* next;
    };

    node* top;

public:
    LinkedStack() : top(nullptr) {}

    ~LinkedStack() {
        ClearStack();
    }

    bool IsEmpty() const {
        return top == nullptr;
    }

    void Push(int value) {
        node* newNode = new node{value, top};
        top = newNode;
        std::cout << "Pushed: " << value << std::endl;
    }

    void Pop() {
        if (IsEmpty()) {
            std::cout << "Underflow: Stack is empty! Cannot pop." << std::endl;
            return;
        }
        node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        std::cout << "Popped: " << poppedValue << std::endl;
    }

    void Peek() const {
        if (IsEmpty()) {
            std::cout << "Underflow: Stack is empty! Cannot peek." << std::endl;
            return;
        }
        std::cout << "Top element: " << top->data << std::endl;
    }

    void Display() const {
        if (IsEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack (Top to Bottom): ";
        node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << (temp->next ? ", " : "");
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void ClearStack() {
        while (top != nullptr) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    std::cout << "=== Task 6 Demonstration ===" << std::endl;

    LinkedStack stack;
    int choice = 0;
    int val = 0;

    // Direct programmatic test before menu loop as per lab instructions
    std::cout << "-- Automated Test Runs --" << std::endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Display();

    stack.Pop();
    stack.Peek();
    stack.Display();

    std::cout << "\n-- Interactive Menu Loop --" << std::endl;
    while (choice != 5) {
        std::cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input!" << std::endl;
            break;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter integer to push: ";
                std::cin >> val;
                stack.Push(val);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.Peek();
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                std::cout << "Exiting menu... Releasing remaining nodes." << std::endl;
                break;
            default:
                std::cout << "Invalid option! Try again." << std::endl;
        }
    }

    return 0;
}