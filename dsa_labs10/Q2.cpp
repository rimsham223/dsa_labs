// Lab 10 - Task 2: AVL Insertion and Rotations
// Name: Rimsha Mahmood | Reg No: 455080 | Section: BSCS-15E
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;
};

Node* newNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}

int height(Node* n) { return n ? n->height : 0; }

int balanceFactor(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

void updateHeight(Node* n) { n->height = 1 + max(height(n->left), height(n->right)); }

// LL case fix: returns new subtree root
Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);        // old root first
    updateHeight(newRoot);     // then new root
    return newRoot;
}

// RR case fix: returns new subtree root
Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* insertAVL(Node* root, int value) {
    if (root == nullptr) return newNode(value);

    if (value < root->data)      root->left  = insertAVL(root->left, value);
    else if (value > root->data) root->right = insertAVL(root->right, value);
    else return root;                                  // ignore duplicates

    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1 && value < root->left->data) {          // LL
        cout << "  [LL at " << root->data << "] right rotation\n";
        return rightRotate(root);
    }
    if (bf < -1 && value > root->right->data) {        // RR
        cout << "  [RR at " << root->data << "] left rotation\n";
        return leftRotate(root);
    }
    if (bf > 1 && value > root->left->data) {          // LR
        cout << "  [LR at " << root->data << "] left rotation on child, then right rotation\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bf < -1 && value < root->right->data) {        // RL
        cout << "  [RL at " << root->data << "] right rotation on child, then left rotation\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preorder(Node* r) { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)  { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }

// Recomputes real heights; checks stored height and |balance| <= 1 at every node
int verify(Node* r, bool& ok) {
    if (!r) return 0;
    int lh = verify(r->left, ok);
    int rh = verify(r->right, ok);
    int h = 1 + max(lh, rh);
    if (h != r->height || abs(lh - rh) > 1) ok = false;
    return h;
}

void freeTree(Node* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
}

void runSequence(const char* label, const int* seq, int n) {
    cout << "\nSequence " << label << ": ";
    for (int i = 0; i < n; i++) cout << seq[i] << " ";
    cout << "\n";

    Node* root = nullptr;
    for (int i = 0; i < n; i++) root = insertAVL(root, seq[i]);

    cout << "  Preorder: ";  preorder(root);
    cout << "\n  Inorder:  "; inorder(root);
    bool ok = true;
    verify(root, ok);
    cout << "\n  All nodes balanced: " << (ok ? "YES" : "NO") << "\n";
    freeTree(root);
}

int main() {
    int a[] = {30, 20, 10};   // LL
    int b[] = {10, 20, 30};   // RR
    int c[] = {30, 10, 20};   // LR
    int d[] = {10, 30, 20};   // RL
    runSequence("(a)", a, 3);
    runSequence("(b)", b, 3);
    runSequence("(c)", c, 3);
    runSequence("(d)", d, 3);
    return 0;
}
