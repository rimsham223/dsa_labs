#include <iostream>
using namespace std;

int main(){
    //rows-> bracnhes, columns-> days
    int sales[2][3];
    int(*rowPtr)[3] = sales;

    // read vlaues
    for (int i=0; i<2; i++){
        for(int j=0;j<3;j++){
            cout<<"Enter sales for branch"<<i+1<<" day "<<j+1<<": ";
            cin>>*(*(rowPtr+i)+j);
        }
    }

    //display non-negative values in two row table
    cout<<"Sales Table"<<endl;
    for(int i=0; i<2;i++){
        for(int j=0; j<3; j++){
            if(*(*(rowPtr+i)+j) >= 0){
                cout<<*(*(rowPtr+i)+j)<<"\t";
            }
        }
        cout<<endl;
    }

    //branch total
    cout<<"Branch Totals:"<<endl;
    for(int i=0; i<2;i++){
        int branchTotal=0;
        for(int j=0; j<3; j++){
            branchTotal += *(*(rowPtr+i)+j);
        }
        cout<<"Branch "<<i+1<<": "<<branchTotal<<endl;
    }
    //days total
    cout<<"Days Totals:"<<endl;
    for(int j=0; j<3; j++){
        int dayTotal=0;
        for(int i=0; i<2; i++){
            dayTotal += *(*(rowPtr+i)+j);
        }
        cout<<"Day "<<j+1<<": "<<dayTotal<<endl;
    }

    return 0;

}