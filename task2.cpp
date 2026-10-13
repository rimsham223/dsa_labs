/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 2: Implementing a stack using a linked list
 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << value << " into the stack.\n";
}

void pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    Node* temp = top;
    cout << "Popped value: " << temp->data << "\n";
    top = top->next;
    delete temp;
}

void peek() {
    if (top == nullptr) {
        cout << "Stack is empty. No top element.\n";
        return;
    }
    cout << "Top value: " << top->data << "\n";
}

void display() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack contents (top to bottom): ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void releaseMemory() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    // Push 5, 15, 25
    push(5);
    push(15);
    push(25);

    // Display from top to bottom
    display();

    // Pop once
    pop();

    // Peek
    peek();

    // Pop remaining elements to test empty pop
    pop();
    pop();

    // Test empty pop
    pop();

    // Release any remaining nodes before exit
    releaseMemory();

    return 0;
}