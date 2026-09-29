// Name: Rimsha Mahmood  CMS: 455080  Section: BSCS-15E
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

        void AddNode(int newData){
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                curr = head;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode;
            }
        }

        void InsertAtBeginning(int addData){
            Node* newnode= new Node();
            newnode->data= addData;
            newnode->next= head;
            head= newnode;
        }

        int CountNodes(){
            int count = 0;
            curr= head;
            if(curr==nullptr){
                cout<<"List is empty"<<endl;
                return 0;
            }
            while(curr!=nullptr){
                count++;
                curr= curr->next;
            }
            return count;
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

        void SearchNode(int searchData) {
            curr = head;
            int pos = 1;
            while (curr != nullptr) {
                if (curr->data == searchData) {
                    cout << "Node with value " << searchData << " found at position " << pos << "." << endl;
                    return;
                }
                curr = curr->next;
                pos++;
            }
            cout << "Value " << searchData << " not found." << endl;
        }

        void PrintSecondNode(){
            if(head == nullptr || head->next == nullptr) {
                cout << "The list does not have a second node." << endl;
                return;
            }
            cout << "The second node has the value: " << head->next->data << endl;
        }


    };

    
    int main() {
        List myList;
        cout<<"Insert 20 at beginning of the list"<<endl;
        myList.InsertAtBeginning(20);
        cout<<"Insert 10 at beginning of the list"<<endl;
        myList.InsertAtBeginning(10);
        cout<<"Append 30 at end of the list"<<endl;
        myList.AddNode(30);
        cout<<"The list is: ";
        myList.PrintList();
        return 0;
    }