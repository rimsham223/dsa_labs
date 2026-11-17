// Lab 10 - Task 1: BST Deletion
// Name: Rimsha Mahmood | Reg No: 455080 | Section: BSCS-15E
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;            // not used in Task 1
};

Node* newNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}

// Plain BST insert (duplicates ignored)
Node* insertBST(Node* root, int value) {
    if (root == nullptr) return newNode(value);
    if (value < root->data)      root->left  = insertBST(root->left, value);
    else if (value > root->data) root->right = insertBST(root->right, value);
    return root;
}

// Helper: smallest node of a subtree (inorder successor for two-child case)
Node* minNode(Node* node) {
    while (node != nullptr && node->left != nullptr)
        node = node->left;
    return node;
}

// Recursive deletion; returns the updated subtree root
Node* deleteBST(Node* root, int value) {
    if (root == nullptr) return nullptr;              // empty tree / missing key

    if (value < root->data)
        root->left = deleteBST(root->left, value);
    else if (value > root->data)
        root->right = deleteBST(root->right, value);
    else {
        // Case 1 (leaf) and Case 2 (one child, right only)
        if (root->left == nullptr) {
            Node* child = root->right;                // nullptr when leaf
            delete root;
            return child;
        }
        // Case 2 (one child, left only)
        if (root->right == nullptr) {
            Node* child = root->left;
            delete root;
            return child;
        }
        // Case 3: two children -> copy inorder successor, delete it from right subtree
        Node* succ = minNode(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    return root;
}

// Used only to print which case applies before deleting
void describeCase(Node* root, int value) {
    Node* cur = root;
    while (cur != nullptr && cur->data != value)
        cur = (value < cur->data) ? cur->left : cur->right;

    cout << "Deleting " << value << ": ";
    if (cur == nullptr)                            cout << "key not found (tree unchanged)\n";
    else if (!cur->left && !cur->right)            cout << "Case 1 - leaf node\n";
    else if (!cur->left || !cur->right)            cout << "Case 2 - one child\n";
    else cout << "Case 3 - two children (successor = "
              << minNode(cur->right)->data << ")\n";
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void printInorder(const char* label, Node* root) {
    cout << label << " inorder: ";
    if (root == nullptr) cout << "(empty)";
    else inorder(root);
    cout << "\n";
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 65};
    for (int k : keys) root = insertBST(root, k);
    printInorder("Initial", root);

    // Predictions:
    //  delete 20 -> leaf        : 30 40 50 60 65 70 80
    //  delete 60 -> one child   : 30 40 50 65 70 80
    //  delete 50 -> two children: 30 40 65 70 80 (successor 65)
    int toDelete[] = {20, 60, 50};
    for (int v : toDelete) {
        describeCase(root, v);
        root = deleteBST(root, v);
        printInorder("After", root);
    }

    cout << "\n--- Boundary tests ---\n";
    describeCase(root, 999);
    root = deleteBST(root, 999);                   // missing key
    printInorder("After missing key", root);

    Node* empty = nullptr;
    empty = deleteBST(empty, 10);                  // empty tree
    cout << "Delete from empty tree -> " << (empty == nullptr ? "nullptr" : "not null") << "\n";

    Node* single = newNode(42);
    single = deleteBST(single, 42);                // only node
    cout << "Delete only node -> " << (single == nullptr ? "nullptr" : "not null") << "\n";

    freeTree(root);                                // release remaining nodes
    return 0;
}
