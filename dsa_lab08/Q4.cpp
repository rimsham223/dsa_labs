// Name: Rimsha Mahmood
// Reg No: 455080
// Section: BSCS- 15E
// Lab 08 - Task 4: Searching in a BST

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

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* curr = root;
    while (curr != nullptr) {
        if (key == curr->data) return curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return nullptr;
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    int keys[] = {40, 10, 70, 25};
    for (int i = 0; i < 4; i++) {
        int k = keys[i];
        cout << "Search " << k << " (recursive): "
             << (searchRecursive(root, k) ? "Found" : "Not found") << endl;
        cout << "Search " << k << " (iterative): "
             << (searchIterative(root, k) ? "Found" : "Not found") << endl;
    }

    // Empty tree
    cout << "\nSearch 40 in empty tree (recursive): "
         << (searchRecursive(nullptr, 40) ? "Found" : "Not found") << endl;
    cout << "Search 40 in empty tree (iterative): "
         << (searchIterative(nullptr, 40) ? "Found" : "Not found") << endl;

    // Nodes compared when searching for 25:
    // 25 vs 40 -> go left; 25 vs 20 -> go right; 25 vs 30 -> go left;
    // left of 30 is nullptr -> Not found.  Compared: 40, 20, 30 (3 nodes)
    cout << "\nSearching 25 compares nodes: 40, 20, 30 (3 nodes), then reaches nullptr." << endl;

    freeTree(root);
    return 0;
}