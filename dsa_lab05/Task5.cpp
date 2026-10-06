/*
 * Name: RIMSHA MAHMOOD
 * Registration Number: 455080
 * Section: BSCS-15E
 * Lab 05 - Task 5: Implementing a Stack Using an Array
 */

#include <iostream>

class ArrayStack {
private:
    int items[5];
    int top;

public:
    ArrayStack() : top(-1) {}

    bool IsEmpty() const {
        return top == -1;
    }

    bool IsFull() const {
        return top == 4;
    }

    void Push(int value) {
        if (IsFull()) {
            std::cout << "Overflow: Stack is full! Cannot push " << value << std::endl;
            return;
        }
        items[++top] = value;
        std::cout << "Pushed: " << value << std::endl;
    }

    void Pop() {
        if (IsEmpty()) {
            std::cout << "Underflow: Stack is empty! Cannot pop." << std::endl;
            return;
        }
        std::cout << "Popped: " << items[top--] << std::endl;
    }

    void Peek() const {
        if (IsEmpty()) {
            std::cout << "Underflow: Stack is empty! Cannot peek." << std::endl;
            return;
        }
        std::cout << "Top element: " << items[top] << std::endl;
    }

    void Display() const {
        if (IsEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack (Top to Bottom): ";
        for (int i = top; i >= 0; --i) {
            std::cout << items[i] << (i > 0 ? ", " : "");
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "=== Task 5 Demonstration ===" << std::endl;

    ArrayStack stack;

    std::cout << "-- Pushing 10, 20, 30, 40, 50 --" << std::endl;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    stack.Display();

    std::cout << "\n-- Testing Sixth Push (Overflow) --" << std::endl;
    stack.Push(60);

    std::cout << "\n-- Popping 50, then Peeking --" << std::endl;
    stack.Pop();
    stack.Peek();
    stack.Display();

    std::cout << "\n-- Emptying Stack --" << std::endl;
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();

    std::cout << "\n-- Testing Pop on Empty Stack (Underflow) --" << std::endl;
    stack.Pop();

    return 0;
}