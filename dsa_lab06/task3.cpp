/*
 * Name: Rimsha Mahmood
 * Registration No: 455080
 * Section: CS-15E
 * Task 3: Reversing a word using a stack
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 20;
char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack full!\n";
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    char ch = stack[top];
    top--;
    return ch;
}

void reverseWord(const string& word) {
    if (word.length() > MAX_SIZE) {
        cout << "Word length exceeds maximum capacity of " << MAX_SIZE << " characters.\n";
        return;
    }

    top = -1; // Reset stack

    // Push characters onto stack
    for (size_t i = 0; i < word.length(); i++) {
        push(word[i]);
    }

    // Pop and print characters to reverse word
    cout << "Original word: " << word << "\n";
    cout << "Reversed word: ";
    while (top != -1) {
        cout << pop();
    }
    cout << "\n\n";
}

int main() {
    // Test standard word
    string word1 = "DATA";
    reverseWord(word1);

    // Test single-letter word
    string word2 = "A";
    reverseWord(word2);

    return 0;
}