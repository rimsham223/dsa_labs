// Name: Rimsha Mahmood
// Reg No: 455080
// Section: BSCS- 15E
// Lab 08 - Task 3: Iterative traversals using a stack

#include <iostream>
#include <stack>
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

// Push RIGHT first so LEFT is popped first (stack is LIFO).
void preorderIterative(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right != nullptr) s.push(curr->right);
        if (curr->left != nullptr)  s.push(curr->left);
    }
}

// Keep going left, remembering nodes on the stack; visit when we can't go left.
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
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

    cout << "Preorder  (recursive): "; preorder(root);          cout << endl;
    cout << "Preorder  (iterative): "; preorderIterative(root); cout << endl;
    cout << "Inorder   (recursive): "; inorder(root);           cout << endl;
    cout << "Inorder   (iterative): "; inorderIterative(root);  cout << endl;

    cout << "\n[Empty tree]" << endl;
    cout << "Preorder  (iterative): "; preorderIterative(nullptr); cout << endl;
    cout << "Inorder   (iterative): "; inorderIterative(nullptr);  cout << endl;

    freeTree(root);
    return 0;
}