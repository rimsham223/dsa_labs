// Name: Rimsha Mahmood   CMS: 455080   Section: BSCS-15E
#include <iostream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    float marks;
};

void displayStudent(const Student* s) {
    cout << "Student Information:\n";
    cout << "ID: " << s->id << endl;
    cout << "Name: " << s->name << endl;
    cout << "Marks: " << s->marks << endl;
}

void updateMarks(Student* s, float newMarks) {
    s->marks = newMarks;
}

void displayIfExists(const Student* s){
    if(s!= nullptr){
        displayStudent(s);
    } else {
        cout << "No record available" << endl;
    }
}

int main(){
    Student* s1 = nullptr;
    float newMarks;
    
    //Before Allocation
    cout<<"Before Allocation: "<<endl;
    displayIfExists(s1);

    s1 = new Student;

    cout<<"Enter student id: ";
    cin>>s1->id;

    cout<<"Enter student name: ";
    cin.ignore();
    getline(cin, s1->name);

    cout<<"Enter student marks: ";
    cin>>s1->marks;

    cout<<"Enter new marks: ";
    cin>>newMarks; 
    updateMarks(s1, newMarks);
    
    //After Allocation
    cout<<"\nAfter Allocation: "<<endl;
    displayIfExists(s1);

    //After Deletion
    delete s1;
    s1 = nullptr;

    cout<<"\nAfter Deletion: "<<endl;
    displayIfExists(s1);

    
    return 0;
}