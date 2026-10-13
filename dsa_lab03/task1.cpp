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
    cout<<"Enter student id: ";
    cin>>s1.id;

    cout<<"Enter student name: ";
    cin.ignore();
    getline(cin, s1.name);

    cout<<"Enter student marks: ";
    cin>>s1.marks;

    cout<<"\nStudent Information:\n";
    cout<<"ID: "<<s1.id<<endl;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Marks: "<<s1.marks<<endl;

}