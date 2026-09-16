#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter integer:";
    cin>>n;

    // Validate marks (n<0 and n>100)
    if(n<=0 || n>100){
        cout<<"No allocation or mark input."<<endl;
        return 1; 
    }
    int* marks =  new int[n]; 
    for (int i=0; i<n; i++){
        cout<<"Enter mark for student "<<i+1<<": ";
        cin>>*(marks+i);
    }

    int total =0; 
    double avg= 0;
    int count=0; 
    for(int i=0; i<n; i++){
        cout<<"Marks for student"<<i+1<<": "<<*(marks+i)<<endl;
        total += *(marks+i);
        avg= total/n;
        if(*(marks+i)>=50){
            count++;
        }
    }
    cout<<"Total marks: "<<total<<endl;
    cout<<"Average marks: "<<avg<<endl;
    cout<<"Number of students with marks >=50: "<<count<<endl;

    //release array
    delete[] marks;
    marks= nullptr;
    return 0;

}