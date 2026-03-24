#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        next = NULL;
        prev = NULL;
        data = val;
    }
};

class DoublyList{
    Node* head;
    public:
    DoublyList(){
        head= NULL;
    }

    void insertAtPos(int pos,int val){
        Node* newNode = new Node(val);
        if (pos==1){
            if(head==NULL){
                head = newNode;
                return;
            }
            else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                return; 
            }
        }

        Node* temp = head;
        int i = 1;
        while(temp!=NULL && i<pos-1){
            temp = temp->next;
            i++;
        }

        if(temp == NULL){
            cout << "Position not found!\n";
            return;
        }
          newNode->prev = temp;
          newNode->next = temp->next;
          if(temp->next!=NULL){
            temp->next->prev = newNode;
          }
          temp->next = newNode;
       
    }

    void display(){
        Node* temp = head;
        cout << "Null->";
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "->NULL";
    }

};

int main (){

    DoublyList dll;
    dll.insertAtPos(0,0);
    dll.insertAtPos(1,5);
    dll.insertAtPos(2,10);
    dll.insertAtPos(3,15);
    dll.insertAtPos(5,25);
    dll.insertAtPos(4,20);
    dll.insertAtPos(5,25);
    dll.display();

    return 0;
}