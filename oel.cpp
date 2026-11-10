/*
 * Name:            Rimsha Mahmood
 * Registration No: 455080
 * Section:         BSCS-15E
 *
 * Open Ended Lab - Student Help Desk
 * ----------------------------------
 * DESIGN EXPLANATION
 * 1) Student records -> Binary Search Tree (BST) keyed on roll number.
 *    - Roll numbers are unique keys, so a BST naturally rejects duplicates
 *      while inserting (we meet the existing key on the way down).
 *    - Searching by roll number only follows one path from the root, which is
 *      much faster than scanning an array/list when the tree is reasonably
 *      balanced.
 *    - An in-order traversal prints all students sorted by roll number for free.
 *    - Nodes are allocated dynamically, so there is no fixed capacity
 *      (no "array full" case) and no shifting of elements.
 *
 * 2) Additional feature: Help requests -> Queue (linked-list implementation).
 *    - The help desk must serve students in the order they asked for help
 *      (First-In-First-Out), which is exactly what a queue provides.
 *    - Enqueue at the rear and dequeue from the front are both O(1) using a
 *      front and rear pointer.
 *    - A linked list lets the queue grow as needed; the same student may
 *      appear multiple times (repeated requests are allowed).
 *
 * TIME COMPLEXITY (n = number of students, h = height of BST)
 *    Add student    : O(h) -> worst case O(n) (skewed tree, e.g. sorted input),
 *                     average O(log n)
 *    Search student : O(h) -> worst case O(n), average O(log n)
 *    Display all    : O(n)
 *    Add request    : O(h) to verify the student is registered + O(1) enqueue
 *    Serve request  : O(1) dequeue (+ O(h) lookup to print the name)
 *
 * ALTERNATIVE DATA STRUCTURE
 *    A self-balancing BST (AVL / Red-Black tree) would guarantee O(log n)
 *    worst case for add and search. A hash table would give O(1) average
 *    search, but would lose sorted display order.
 *
 * No STL containers are used; all structures are implemented manually.
 */

#include <iostream>
#include <string>
using namespace std;

// ======================= Student BST =======================

struct Student {
    int roll;
    string name;
    Student* left;
    Student* right;

    Student(int r, const string& n) : roll(r), name(n), left(nullptr), right(nullptr) {}
};

class StudentBST {
private:
    Student* root;
    int count;

    // In-order traversal: prints records in ascending roll-number order
    void inOrder(Student* node) const {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << "  " << node->roll << "\t" << node->name << "\n";
        inOrder(node->right);
    }

    // Post-order deletion of every node (children before parent).
    void destroy(Student* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    StudentBST() : root(nullptr), count(0) {}
    ~StudentBST() { destroy(root); }

    bool isEmpty() const { return root == nullptr; }
    int size() const { return count; }

    // Iterative insert. Returns false if the roll number already exists.
    // Worst case O(n) for a skewed tree, average O(log n).
    bool insert(int roll, const string& name) {
        if (root == nullptr) {
            root = new Student(roll, name);
            count++;
            return true;
        }
        Student* curr = root;
        while (true) {
            if (roll == curr->roll) {
                return false;                       // duplicate rejected
            } else if (roll < curr->roll) {
                if (curr->left == nullptr) {
                    curr->left = new Student(roll, name);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new Student(roll, name);
                    break;
                }
                curr = curr->right;
            }
        }
        count++;
        return true;
    }

    // Iterative search. Returns nullptr if not found.
    // Worst case O(n) for a skewed tree, average O(log n).
    Student* search(int roll) const {
        Student* curr = root;
        while (curr != nullptr) {
            if (roll == curr->roll) return curr;
            curr = (roll < curr->roll) ? curr->left : curr->right;
        }
        return nullptr;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No students registered yet.\n";
            return;
        }
        cout << "  Roll\tName\n";
        cout << "  ----\t----\n";
        inOrder(root);
        cout << "Total students: " << count << "\n";
    }
};

// ======================= Help Request Queue =======================

struct RequestNode {
    int roll;
    RequestNode* next;

    RequestNode(int r) : roll(r), next(nullptr) {}
};

class RequestQueue {
private:
    RequestNode* front;
    RequestNode* rear;
    int count;

public:
    RequestQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~RequestQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const { return front == nullptr; }
    int size() const { return count; }

    // O(1): add to the rear.
    void enqueue(int roll) {
        RequestNode* node = new RequestNode(roll);
        if (rear == nullptr) {
            front = rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        count++;
    }

    // O(1): remove from the front. Caller must check isEmpty() first.
    int dequeue() {
        RequestNode* temp = front;
        int roll = temp->roll;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        count--;
        return roll;
    }

    // Shows waiting requests from earliest (front) to latest (rear).
    void display(const StudentBST& students) const {
        if (isEmpty()) {
            cout << "No help requests are waiting.\n";
            return;
        }
        cout << "Waiting requests:\n";
        int pos = 1;
        for (RequestNode* curr = front; curr != nullptr; curr = curr->next) {
            Student* s = students.search(curr->roll);
            cout << "  " << pos++ << ". " << curr->roll;
            if (s != nullptr) cout << " (" << s->name << ")";
            cout << "\n";
        }
    }
};

// ======================= Menu handlers =======================

void addStudent(StudentBST& students) {
    int roll;
    string name;
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter name: ";
    cin >> ws;
    getline(cin, name);

    if (students.insert(roll, name)) {
        cout << "Student " << roll << " (" << name << ") added successfully.\n";
    } else {
        cout << "Error: roll number " << roll << " already exists. Student not added.\n";
    }
}

void searchStudent(const StudentBST& students) {
    if (students.isEmpty()) {
        cout << "No students registered yet. Nothing to search.\n";
        return;
    }
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    Student* s = students.search(roll);
    if (s != nullptr) {
        cout << "Found: Roll " << s->roll << ", Name: " << s->name << "\n";
    } else {
        cout << "Student with roll number " << roll << " not found.\n";
    }
}

void addRequest(const StudentBST& students, RequestQueue& requests) {
    int roll;
    cout << "Enter roll number requesting help: ";
    cin >> roll;

    if (students.search(roll) == nullptr) {
        cout << "Request rejected: roll number " << roll << " is not registered.\n";
        return;
    }
    requests.enqueue(roll);
    cout << "Help request added for " << roll << ". Position in queue: "
         << requests.size() << "\n";
}

void serveRequest(const StudentBST& students, RequestQueue& requests) {
    if (requests.isEmpty()) {
        cout << "No help requests are waiting.\n";
        return;
    }
    int roll = requests.dequeue();
    Student* s = students.search(roll);
    cout << "Now serving: Roll " << roll;
    if (s != nullptr) cout << " (" << s->name << ")";
    cout << ". Remaining requests: " << requests.size() << "\n";
}

void showMenu() {
    cout << "\n========= Student Help Desk =========\n";
    cout << "1. Add student\n";
    cout << "2. Search student by roll number\n";
    cout << "3. Display all students\n";
    cout << "4. Add help request\n";
    cout << "5. Serve earliest help request\n";
    cout << "6. View waiting help requests\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    StudentBST students;
    RequestQueue requests;
    int choice;

    do {
        showMenu();
        if (!(cin >> choice)) break;   // stop cleanly at end of input
        cout << "\n";

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: searchStudent(students); break;
            case 3: students.display(); break;
            case 4: addRequest(students, requests); break;
            case 5: serveRequest(students, requests); break;
            case 6: requests.display(students); break;
            case 0: cout << "Exiting. Releasing memory...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    // Destructors of StudentBST and RequestQueue free all dynamic memory here.
    return 0;
}


