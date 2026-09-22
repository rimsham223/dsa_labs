// Name: Rimsha Mahmood   CMS: 455080   Section: BSCS-15E
#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    float marks;
};

void displayStudent(const Student* s) {
    if(s!= nullptr){
        cout << "Student Information:\n";
        cout << "ID: " << s->id << endl;
        cout << "Name: " << s->name << endl;
        cout << "Marks: " << s->marks << endl;
    } else {
        cout << "No record available" << endl;
    }
}

void updateMarks(Student* s, float newMarks) {
    if(s != nullptr){
        s->marks = newMarks;
        cout << "Student marks updated." << endl;
    } else {
        cout << "No record available." << endl;
    }
}

void deleteStudent(Student*& s) {
    if(s != nullptr){
        delete s;
        s = nullptr;
        cout << "Student record deleted." << endl;
    } else {
        cout << "No record available." << endl;
    }
}

void createStudent(Student*& s){
    if(s != nullptr){
        cout << "A student record already exists." << endl;
        return;
    }

    s = new Student;
    cout<<"Enter student id: ";
    cin>>s->id;

    cout<<"Enter student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s->name);

    cout<<"Enter student marks: ";
    cin>>s->marks;
}

int main(){
    Student* s1 = nullptr;

    while (true){
        int choice;
        cout << "\nChoose from menu:" << endl;
        cout << "1. Create Student Record" << endl;
        cout << "2. Update Student Marks" << endl;
        cout << "3. Display Student Record" << endl;
        cout << "4. Delete Student Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";

        if(!(cin >> choice)){
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                createStudent(s1);
                break;
            case 2:
                if(s1 != nullptr){
                    float newMarks;
                    cout << "Enter new marks: ";
                    cin >> newMarks;
                    updateMarks(s1, newMarks);
                } else {
                    cout << "No record available." << endl;
                }
                break;
            case 3:
                displayStudent(s1);
                break;
            case 4:
                deleteStudent(s1);
                break;
            case 5:
                deleteStudent(s1);
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}