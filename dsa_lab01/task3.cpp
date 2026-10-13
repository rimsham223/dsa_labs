#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber;
    int marks;

    void display() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {

    Student s1;
    Student s2;

    // Assign values
    s1.rollNumber = 1;
    s1.marks = 75;

    s2.rollNumber = 2;
    s2.marks = 90;

    // Display original values
    cout << "Before changing s1.marks:" << endl;

    s1.display();
    s2.display();

    // Change only s1 marks
    s1.marks = 80;

    // Display again
    cout << "\nAfter changing s1.marks:" << endl;

    s1.display();
    s2.display();

    return 0;
}
