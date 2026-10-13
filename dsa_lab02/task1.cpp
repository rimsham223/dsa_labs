#include <iostream>
using namespace std;

int main(){
    int sales[5];
    int* p= sales;
    
    //Read non-negative numebrs
    for(int i=0; i<5; i++){
        cout<<"Enter sales for day "<<i+1<<": ";
        cin>>*(p+i);
        while(*(p+i)<0){
            cout<<"Invalid input. Please enter a non-negative number: ";
            cin>>*(p+i);
        }
    }
    //Display initial values and claculate total sales
    int total = 0;
    for(int i=0; i<5; i++){
        cout<<"Sales for day "<<i+1<<": "<<*(p+i)<<endl;
        total += *(p+i);
    }
    cout<<"Total sales: "<<total<<endl;

    //Add 2 to third day's value
    *(p+2) += 2;
    cout<<"Sales for day 3 (after adding 2): "<<*(p+2)<<endl;

    // display updated vlaues and total sales
    total = 0;
    for(int i=0; i<5; i++){
        cout<<"Sales for day "<<i+1<<": "<<*(p+i)<<endl;
        total += *(p+i);
    }   
    cout<<"Total sales (after update): "<<total<<endl;
    return 0;

}