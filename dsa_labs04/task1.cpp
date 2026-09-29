// Name: Rimsha Mahmood  cms: 455080  Section: BSCS-15E
#include <iostream>
using namespace std;

class List{
    private:
        struct Node{
            int data;
            Node* next;
        };
        Node* head;
        Node* curr;
    public:
        List(){
            head= nullptr;
            curr= nullptr;
        }

        void CreateThreeNodes(){
            Node* first= new Node();
            Node* second= new Node();  
            Node* third= new Node();
            int value;
            //input data in nodes
            cout<<"Enter value for first node: ";
            cin>>value;
            first->data= value;
            cout<<"Enter value for second node: ";
            cin>>value;
            second->data= value;
            cout<<"Enter value for third node: ";
            cin>>value;
            third->data= value;
            //link node in input sequence
            first->next = second;
            second-> next= third;
            third->next= nullptr;
            head= first;
        }

        void PrintList(){
            curr = head;
            if(curr==nullptr){
                cout<<"List is empty"<<endl;
                return;
            }
            while(curr!=nullptr){
                cout<<curr->data<<" ";
                curr= curr->next;
            }
            cout<<endl;
        }

        void ClearList(){
            curr= head;
            while(curr!=nullptr){
                Node* temp= curr;
                curr= curr->next;
                delete temp;
            }
            head= nullptr;
        }

    };

    int main() {
    List myList;

    cout << "Before creating nodes, the linked list is: ";
    myList.PrintList();

    cout << "Creating three nodes in the linked list..." << endl;
    myList.CreateThreeNodes();

    cout << "The linked list is: ";
    myList.PrintList();

    /*cout << "Clearing the linked list..." << endl;
    myList.ClearList();

    cout << "The linked list after clearing is: ";
    myList.PrintList();*/

    return 0;
}