#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;
    
    Node(int val){
        this->data = val;
        this->next = NULL;
    }

};

class LinkedList{ 
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    void addAtStart(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        Node* temp = head;
        if(temp==NULL){
            head=newNode;
            return;
        }

        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertBeforeNode(int target,int val){
         Node* newNode = new Node(val);
         if (head==NULL){
            cout << "List is Empty!\n";
            return;
         }
         if (head->data==target){
            newNode->next = head;
            head = newNode;
            return;
         }
         Node* temp = head;
         while( temp->next!=NULL && temp->next->data!=target){
            temp = temp->next;
         }
         if(temp->next==NULL){
            cout << "Target not Found!\n";
            return;
         }
         newNode->next = temp->next;
         temp->next = newNode;
    }

    void insertAfterNode(int target,int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            cout << "List is Empty!\n";
            return;
        }
        if (head->data==target){
            newNode->next = head->next;
            head->next = newNode;
            return;
        }

        Node* temp = head;
        while(temp!=NULL && temp->data!=target){
            temp = temp->next;
        }

        if(temp==NULL){
            cout << "Target not Found!\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtStart(){
        if(head==NULL){
            cout << "List is Empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;

    }

    void deleteAtEnd(){
        if(head == NULL){
            cout << "List is Empty!\n";
            return;
        }
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;   
    }
    void deleteSpecificNode(int target){
        if(head==NULL){
            cout << "List is Empty!\n";
            return;
        }
        if(head->data==target){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next!=NULL && temp->next->data!=target){
            temp = temp->next;
        }
        if (temp->next==NULL){
            cout << "Target not Found!\n";
            return;
        }
        Node* save = temp->next;
        temp->next = temp->next->next;
        save->next = NULL;
        delete save;    
    }

    bool searchNode(int key){
        if ( head==NULL){
        cout << "List is Empty!\n";
        return false;
        }
        Node* temp = head;
        while (temp!=NULL){
            if(temp->data==key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int coutNode(){
        int cout=0;
        if(head==NULL){
            return 0;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout++;
            temp = temp->next;
        }
        return cout;
    }
    

    void display(){
        Node* temp = head;
        if(temp==NULL){
            cout << "List is Empty!\n";
            return;
        }
        while (temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    LinkedList ll;
    ll.addAtStart(15);
    ll.addAtStart(20);
    ll.addAtStart(25);
    ll.addAtStart(30);
    cout << "is Found : " << ll.searchNode(26) << endl;
    cout << "Number of element in List is : " << ll.coutNode() <<endl;
    ll.display();
    return 0;
}

