/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 1: Implementing a stack using an array
 */

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << value << ".\n";
        return;
    }
    top++;
    items[top] = value;
    cout << "Pushed " << value << " into the stack.\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }
    cout << "Popped value: " << items[top] << "\n";
    top--;
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty. No top element.\n";
        return;
    }
    cout << "Top value: " << items[top] << "\n";
}

void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack contents (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << items[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Push 10, 20, 30
    push(10);
    push(20);
    push(30);

    // Display stack
    display();

    // Pop
    pop();

    // Peek
    peek();

    // Fill the remaining spots
    push(40);
    push(50);
    push(60);

    // Test sixth insertion (Stack Overflow)
    push(70);

    // Remove all values
    pop();
    pop();
    pop();
    pop();
    pop();

    // Test pop after removing all values (Stack Underflow)
    pop();

    return 0;
}