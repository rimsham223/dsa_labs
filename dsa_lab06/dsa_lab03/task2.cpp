// Name: Rimsha Mahmood   CMS: 455080   Section: BSCS-15E
#include <iostream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    float marks;
};

int main(){
    Student s1;
    Student* ptr= &s1;
    float newMarks;

    cout<<"Enter student id: ";
    cin>>ptr->id;

    cout<<"Enter student name: ";
    cin.ignore();
    getline(cin, ptr->name);

    cout<<"Enter student marks: ";
    cin>>ptr->marks;

    cout<<"Enter new marks: ";
    cin>>newMarks; 
    ptr->marks = newMarks;
    
    cout<<"\n-----Updated record:------ "<<endl;

    cout<<"ID: "<<ptr->id<<endl;
    cout<<"Name: "<<ptr->name<<endl;
    cout<<"Marks: "<<ptr->marks<<endl;
    
    return 0;
}