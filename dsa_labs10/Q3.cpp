// Lab 10 - Task 3: AVL Insertion and Deletion
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

Node* rightRotate(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

Node* leftRotate(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    updateHeight(root);
    updateHeight(newRoot);
    return newRoot;
}

// Rebalance using balance factors of the node and its heavy child
// (works for both insertion and deletion)
Node* rebalance(Node* root) {
    updateHeight(root);
    int bf = balanceFactor(root);

    if (bf > 1) {                                       // left heavy
        if (balanceFactor(root->left) >= 0) {           // LL (or child bf 0 -> single rotation)
            cout << "  [Left-heavy at " << root->data << "] right rotation\n";
            return rightRotate(root);
        }
        cout << "  [Left-heavy at " << root->data << "] left then right rotation\n";
        root->left = leftRotate(root->left);            // LR
        return rightRotate(root);
    }
    if (bf < -1) {                                      // right heavy
        if (balanceFactor(root->right) <= 0) {          // RR (or child bf 0 -> single rotation)
            cout << "  [Right-heavy at " << root->data << "] left rotation\n";
            return leftRotate(root);
        }
        cout << "  [Right-heavy at " << root->data << "] right then left rotation\n";
        root->right = rightRotate(root->right);         // RL
        return leftRotate(root);
    }
    return root;                                        // already balanced
}

Node* insertAVL(Node* root, int value) {
    if (root == nullptr) return newNode(value);
    if (value < root->data)      root->left  = insertAVL(root->left, value);
    else if (value > root->data) root->right = insertAVL(root->right, value);
    else return root;                                   // ignore duplicates
    return rebalance(root);
}

Node* minNode(Node* node) {
    while (node != nullptr && node->left != nullptr) node = node->left;
    return node;
}

Node* deleteAVL(Node* root, int value) {
    if (root == nullptr) return nullptr;                // empty tree / missing key

    if (value < root->data)
        root->left = deleteAVL(root->left, value);
    else if (value > root->data)
        root->right = deleteAVL(root->right, value);
    else {
        if (root->left == nullptr) {                    // leaf or only right child
            Node* child = root->right;
            delete root;
            return child;                               // child already balanced
        }
        if (root->right == nullptr) {                   // only left child
            Node* child = root->left;
            delete root;
            return child;
        }
        Node* succ = minNode(root->right);              // two children
        root->data = succ->data;
        root->right = deleteAVL(root->right, succ->data);
    }
    // Subtree still non-empty: update height and rebalance at every ancestor
    return rebalance(root);
}

void preorder(Node* r) { if (!r) return; cout << r->data << " "; preorder(r->left); preorder(r->right); }
void inorder(Node* r)  { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }

void printNodes(Node* r) {                              // key, height, balance factor
    if (!r) return;
    printNodes(r->left);
    cout << "    key=" << r->data << "  height=" << r->height
         << "  bf=" << balanceFactor(r) << "\n";
    printNodes(r->right);
}

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

void show(const char* label, Node* root) {
    cout << label << "\n  Preorder: ";
    preorder(root);
    cout << "\n  Inorder:  ";
    inorder(root);
    bool ok = true;
    verify(root, ok);
    cout << "\n  Balanced: " << (ok ? "YES" : "NO") << "\n  Nodes:\n";
    printNodes(root);
}

int main() {
    // ---- Main test: 30 20 40 10 25 50 5, then delete 50 and 40 ----
    cout << "=== Main test ===\n";
    Node* root = nullptr;
    int keys[] = {30, 20, 40, 10, 25, 50, 5};
    for (int k : keys) root = insertAVL(root, k);
    show("After insertions", root);

    cout << "\nDelete 50 (30 becomes left-heavy, child 20 has bf +1 -> right rotation)\n";
    root = deleteAVL(root, 50);
    show("After deleting 50", root);

    cout << "\nDelete 40 (no rotation needed)\n";
    root = deleteAVL(root, 40);
    show("After deleting 40", root);

    // ---- Boundary tests ----
    cout << "\n=== Missing key ===\n";
    root = deleteAVL(root, 999);
    show("After deleting 999", root);
    freeTree(root);

    cout << "\n=== Empty tree ===\n";
    Node* empty = nullptr;
    empty = deleteAVL(empty, 10);
    cout << "Result: " << (empty == nullptr ? "nullptr" : "not null") << "\n";

    cout << "\n=== One node ===\n";
    Node* one = newNode(7);
    one = deleteAVL(one, 7);
    cout << "Result: " << (one == nullptr ? "nullptr" : "not null") << "\n";

    // ---- Heavy child balance factor = 0 ----
    // Tree: 20(10, 30(25,35)). Delete 10 -> node 20 has bf -2, right child 30 has bf 0.
    // A single LEFT rotation is enough: 30 becomes root, 20 takes 25 as its right child,
    // heights become 20=2, 30=3, balanced. A double rotation is unnecessary because the
    // heavy child is balanced, so its inner subtree is no taller than its outer one;
    // a single rotation therefore cannot make the tree lopsided the other way.
    cout << "\n=== Heavy child bf = 0 ===\n";
    Node* t = nullptr;
    int ks[] = {20, 10, 30, 25, 35};
    for (int k : ks) t = insertAVL(t, k);
    show("Before", t);
    cout << "\nDelete 10\n";
    t = deleteAVL(t, 10);
    show("After deleting 10", t);
    freeTree(t);

    return 0;
}
