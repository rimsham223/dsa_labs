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
        //Menu to choose
        int choice;
        while(true){
            cout<<"Menu:"<<endl;
            cout<<"1. Add Node"<<endl;
            cout<<"2. Insert at Beginning"<<endl;
            cout<<"3. Count Nodes"<<endl;
            cout<<"4. Print List"<<endl;
            cout<<"5. Clear List"<<endl;
            cout<<"6. Search Node"<<endl;
            cout<<"7. Print Second Node"<<endl;
            cout<<"8. Delete Node"<<endl;
            cout<<"9. Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                    int newData;
                    cout << "Enter value for new node: ";
                    cin >> newData;
                    myList.AddNode(newData);
                    break;
                case 2:
                    int addData;
                    cout << "Enter value to insert at beginning: ";
                    cin >> addData;
                    myList.InsertAtBeginning(addData);
                    break;
                case 3:
                    cout << "Number of nodes in the list: " << myList.CountNodes() << endl;
                    break;
                case 4:
                    myList.PrintList();
                    break;
                case 5:
                    myList.ClearList();
                    cout << "List cleared." << endl;
                    break;
                case 6:
                    int searchValue;
                    cout << "Enter a value to search in the list: ";
                    cin >> searchValue;
                    myList.SearchNode(searchValue);
                    break;
                case 7:
                    myList.PrintSecondNode();
                    break;
                case 8:
                    int delValue;
                    cout << "Enter a value to delete in the list: ";
                    cin >> delValue;
                    myList.DeleteNode(delValue);
                    break;
                case 9:
                    myList.ClearList();
                    cout << "Exiting program. All nodes cleared." << endl;
                    return 0;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }

        return 0;
    }