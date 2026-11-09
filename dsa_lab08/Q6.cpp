// Name: Rimsha Mahmood
// Reg No: 455080
// Section: BSCS- 15E
// Lab 08 - Task 6: Iterative insertion in a BST

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
    return root;
}

Node* insertIterative(Node* root, int value) {
    Node* newNode = createNode(value);
    if (root == nullptr) return newNode;   // empty tree

    Node* parent = nullptr;
    Node* curr = root;
    while (curr != nullptr) {
        parent = curr;
        if (value < curr->data)       curr = curr->left;
        else if (value > curr->data)  curr = curr->right;
        else {                         // duplicate: ignore
            delete newNode;
            return root;
        }
    }
    if (value < parent->data) parent->left = newNode;
    else                      parent->right = newNode;
    return root;
}

Node* searchIterative(Node* root, int key, int& compared) {
    compared = 0;
    Node* curr = root;
    while (curr != nullptr) {
        compared++;
        if (key == curr->data) return curr;
        if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return nullptr;
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

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    // Same insertions as Task 5, built both ways
    int values[] = {40, 20, 60, 10, 30, 50, 70, 25, 20};
    int n = 9;

    Node* recRoot = nullptr;
    Node* itRoot = nullptr;
    for (int i = 0; i < n; i++) {
        recRoot = insertRecursive(recRoot, values[i]);
        itRoot = insertIterative(itRoot, values[i]);
    }

    cout << "Recursive tree - Inorder : "; inorder(recRoot);  cout << endl;
    cout << "Iterative tree - Inorder : "; inorder(itRoot);   cout << endl;
    cout << "Recursive tree - Preorder: "; preorder(recRoot); cout << endl;
    cout << "Iterative tree - Preorder: "; preorder(itRoot);  cout << endl;

    // Skewed tree
    Node* skewed = nullptr;
    int sv[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) skewed = insertIterative(skewed, sv[i]);

    int compared = 0;
    Node* res = searchIterative(skewed, 50, compared);
    cout << "\nSkewed tree (10,20,30,40,50) - Search 50: "
         << (res ? "Found" : "Not found")
         << ", nodes compared = " << compared << endl;   // 5

    // Why slower: a skewed BST degenerates into a linked list of height n-1,
    // so search is O(n) (every node may be compared). A balanced BST has
    // height ~log2(n), so search is O(log n), which grows far more slowly as n increases.

    freeTree(recRoot);
    freeTree(itRoot);
    freeTree(skewed);
    return 0;
}