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


    };

    
    int main() {
        List myList;
        int n;
        cout << "Enter the number of nodes you want to add: ";
        cin >> n;
        cout << endl;

        if (n == 0) {
            cout << "No nodes to add. The list is empty." << endl;
        } else {
            for (int i = 0; i < n; i++) {
                int value;
                cout << "Enter value for node " << i+1 << ": ";
                cin >> value;
                myList.AddNode(value);
            }

            cout << endl;
            cout << "The number of nodes in the list is: " << myList.CountNodes() << endl;
            cout << "The list is: ";
            myList.PrintList();
        }

    }
