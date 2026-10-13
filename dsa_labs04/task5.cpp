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

        void DeleteNode(int delData){
            // Check if the list is empty
            if(head == nullptr){
                cout<<"List is empty. Cannot delete."<<endl;
                return;
            }

            //Case 1: If the node to be deleted is the head node
            if(head->data == delData){
                Node* temp = head;
                head = head -> next;
                delete temp;
                cout<<"Node with value "<<delData<<" deleted."<<endl;
                return;
            }
            //find the node to be deleted
            curr = head;
            while(curr->next != nullptr && curr->next->data != delData){
                curr = curr->next;
            }
            //node not found
            if(curr->next == nullptr){
                cout<<"Node with value "<<delData<<" not found."<<endl;
                return;
            }
            //delete the matching node
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout<<"Node with value "<<delData<<" deleted."<<endl;
            
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
                cout << "Enter value for node " << i + 1 << ": ";
                cin >> value;
                myList.AddNode(value);
            }

            cout << endl;
            cout << "The number of nodes in the list is: " << myList.CountNodes() << endl;
            cout << "The list is: ";
            myList.PrintList();

            cout << "Enter a value to delete in the list: ";
            int delValue;
            cin >> delValue;
            myList.DeleteNode(delValue);

            cout << "The list after deletion is: ";
            myList.PrintList();
        }

        return 0;
    }