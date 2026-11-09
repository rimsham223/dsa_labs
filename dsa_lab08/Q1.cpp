// Name: Rimsha Mahmood
// Reg No: 455080
// Section: BSCS- 15E
// Lab 08 - Task 1: Recursive depth-first traversals

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

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Build tree by linking nodes directly
    Node* root = createNode(40);
    root->left = createNode(20);
    root->right = createNode(60);
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // Predicted:
    // Inorder   : 10 20 30 40 50 60 70
    // Preorder  : 40 20 10 30 60 50 70
    // Postorder : 10 30 20 50 70 60 40
    cout << "Inorder   : "; inorder(root);   cout << endl;
    cout << "Preorder  : "; preorder(root);  cout << endl;
    cout << "Postorder : "; postorder(root); cout << endl;

    // Test nullptr
    cout << "\n[Empty tree]" << endl;
    cout << "Inorder   : "; inorder(nullptr);   cout << endl;
    cout << "Preorder  : "; preorder(nullptr);  cout << endl;
    cout << "Postorder : "; postorder(nullptr); cout << endl;

    // Test single-node tree
    Node* single = createNode(99);
    cout << "\n[Single-node tree]" << endl;
    cout << "Inorder   : "; inorder(single);   cout << endl;
    cout << "Preorder  : "; preorder(single);  cout << endl;
    cout << "Postorder : "; postorder(single); cout << endl;

    freeTree(root);
    freeTree(single);
    return 0;
}