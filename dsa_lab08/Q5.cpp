// Name: Rimsha Mahmood
// Reg No: 455080
// Section: BSCS- 15E
// Lab 08 - Task 5: Recursive insertion in a BST

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insertRecursive(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data)
        root->left = insertRecursive(root->left, value);
    else if (value > root->data)
        root->right = insertRecursive(root->right, value);
    // else: duplicate, ignore
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int values[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        root = insertRecursive(root, values[i]);
    }
    cout << "Initial inorder       : "; inorder(root); cout << endl;

    root = insertRecursive(root, 25);
    cout << "After inserting 25    : "; inorder(root); cout << endl;

    root = insertRecursive(root, 20);  // duplicate
    cout << "After inserting 20 (dup): "; inorder(root); cout << endl;

    cout << "Search 25: " << (searchRecursive(root, 25) ? "Found" : "Not found") << endl;

    freeTree(root);
    return 0;
}