#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* pre;

    Node(int data){
        this->data = data;
        next = NULL;
        pre = NULL;
    }
};

class DLL{
    private:
    Node* head;

    public:
    DLL(){
        head  = NULL;
       
    }

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            while (temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->pre = temp;
        }
    }

    void insertAtStart(int val){
        Node* newNode = new Node(val);
        if (head==NULL){
            head = newNode;
            return;
        }
        else{
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
        }
    }

    void deletefromStart(){
        if(head==NULL){
            cout << "List is empty!\n";
            return;
        }
        if(head->next==NULL){
            delete head;
            return;
        }
        else{
            head= head->next;
            delete head->pre;
            head->pre = NULL;
        }
    }

    void deletefromEnd(){
         if(head==NULL){
            cout << "List is empty!\n";
            return;
        }
        if(head->next==NULL){
            delete head;
            return;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            temp->pre->next=NULL;
            delete temp;
        }
    }

    void deleteByIndex(int pos){
        if (pos==1){
            deletefromStart();
            return;
        }
        else{
            Node* temp  = head;
            for(int i = 1;i<pos-1 && temp!=NULL;i++){
                temp = temp->next;
            }
            if(temp!=NULL){
                cout << "index not found!\n";
                return;
            }
            temp->next = temp->next->next;
            delete temp->next->next->pre;
            if(temp->next!=NULL){
                temp->next->pre = temp;
            }
        }
    }
         

    void diplay(){
        
        if (head==NULL){
            cout << "List is Empty!";
            return;
        }
        else{
            Node* temp = head;
            cout << "NULL<-->";
            while (temp!=NULL)
            {
                cout << temp->data << "<-->";
                temp = temp->next;
            }
            cout << "NULL\n";
            
        }
    }
};

int main(){

    DLL dll;
    dll.insertAtEnd(5);
    dll.insertAtEnd(10);
    dll.insertAtEnd(15);
    dll.insertAtStart(1);
    
    dll.diplay();
    dll.deleteByIndex(2);
    dll.diplay();

    return 0;
}